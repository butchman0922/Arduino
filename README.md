# My CLI Arduino development environment

This is my setup for developing Arduino code on an Arch Linux desktop and laptop. 

First get nessary tools:

    sudo pacman -S avr-binutils avrdude avr-gcc avr-gdb avr-libc desktop-file-utils giflib gtk2 jdk jre libusb-compat icoutils namcap

Optional tools:

    sudo pacman -S simavr vim astyle

Build and install arduino:

    mkdir builds
    cd builds
    git clone https://aur.archlinux.org/arduino.git
    cd arduino
    makepkg
    sudo pacman -U name-of-pkg.tar.xz
    cd ~

Git project:

    git clone git@github.com:butchman0922/Arduino.git
    cd Arduino

Update submodules:

    git submodule init
    git submodule update
