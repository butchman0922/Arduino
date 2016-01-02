/* Copyright (C)
 * 2016 - Butch "butchman" Wayman <butch@butchmanhome.net>
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

/**
 * @file Server.ino
 * @brief Arduino Web server for Butchmanhome
 * @author Butch "butchman" Wayman <butch@butchmanhome.net>
 * @version .001
 * @date 2016-01-01
 */


/* you can change the authentication realm by defining
 * WEBDUINO_AUTH_REALM before including WebServer.h */
#define WEBDUINO_AUTH_REALM "ButchmanHome.net Control Server"

#include "SPI.h"
#include "Ethernet.h"
#include "WebServer.h"

/* CHANGE THIS TO YOUR OWN UNIQUE VALUE.  The MAC number should be
 * different from any other devices on your network or you'll have
 * problems receiving packets. */
static uint8_t mac[] = { 0x00, 0x16, 0x3E, 0xD5, 0x48, 0x0D };

/* CHANGE THIS TO MATCH YOUR HOST NETWORK.  Most home networks are in
 * the 192.168.0.XXX or 192.168.1.XXX subrange.  Pick an address
 * that's not in use and isn't going to be automatically allocated by
 * DHCP from your router. */
static uint8_t ip[] = { 192, 168, 0, 106 };

/* This creates an instance of the webserver.  By specifying a prefix
 * of "", all pages will be at the root of the server. */
#define PREFIX ""
WebServer webserver(PREFIX, 80);

void defaultCmd(WebServer &server, WebServer::ConnectionType type, char *, bool)
{
    server.httpSuccess();
    if (type != WebServer::HEAD)
    {
        P(helloMsg) = "<h1>ButchmanHome.net Dashboard</h1><a href=\"private.html\">Login</a>";
        server.printP(helloMsg);
    }
}

void privateCmd(WebServer &server, WebServer::ConnectionType type, char *, bool)
{
    if (server.checkCredentials("YnV0Y2htYW46aWF0bW8xdmZz"))
    {
        server.httpSuccess();
        if (type != WebServer::HEAD)
        {
            P(helloMsg) = "<h1>Hello Butchman</h1>";
            server.printP(helloMsg);
        }
    }
    else
    {
        /* send a 401 error back causing the web browser to prompt the user for credentials */
        server.httpUnauthorized();
    }
}

void setup()
{
    Ethernet.begin(mac, ip);
    webserver.setDefaultCommand(&defaultCmd);
    webserver.addCommand("index.html", &defaultCmd);
    webserver.addCommand("private.html", &privateCmd);
    webserver.begin();
}

void loop()
{
    char buff[64];
    int len = 64;

    /* process incoming connections one at a time forever */
    webserver.processConnection(buff, &len);
}
