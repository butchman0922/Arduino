
PROJECT_DIR       = /home/butchman/Arduino
ARDMK_DIR         = $(PROJECT_DIR)/Arduino-Makefile
ARDUINO_DIR       = /usr/share/arduino
USER_LIB_PATH    := $(PROJECT_DIR)/lib
BOARD_TAG         = uno
CFLAGS_STD        = -std=gnu11
CXXFLAGS_STD      = -std=gnu++11
CXXFLAGS         += -pedantic -Wall -Wextra
MONITOR_PORT      = /dev/ttyACM0
CURRENT_DIR       = $(shell basename $(CURDIR))
OBJDIR            = $(PROJECT_DIR)/$(CURRENT_DIR)/bin/$(BOARD_TAG)

include $(ARDMK_DIR)/Arduino.mk
