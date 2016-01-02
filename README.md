# My CLI Arduino development environment

This is my setup for developing Arduino code on an Arch Linux desktop and laptop. 

First get nessary tools:

    sudo pacman -S avr-binutils avrdude avr-gcc avr-gdb avr-libc
    

Optional tools:

    sudo pacman -S simavr vim astyle

Git project:

    git clone git@github.com:butchman0922/Arduino.git
    cd Arduino

Update submodules:

    git submodule init
    git submodule update
