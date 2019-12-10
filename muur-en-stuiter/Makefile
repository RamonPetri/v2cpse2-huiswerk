#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

PROJECT := main

SEARCH := folder/

HEADERS := ball.hpp rectangle.hpp
HEADERS += $(wildcard folder/*.hpp)

SOURCES := ball.cpp rectangle.cpp

TARGET := native

SERIAL_PORT :=

#HEAP := BMPTK

RUN_PAUSE := echo "Run complete"

#include $(RTOS)/makefile.inc
include $(HWLIB)/makefile.inc

