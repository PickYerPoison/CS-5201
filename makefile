###############################################################################
 # Author:     Brian Catanzaro
 # Username:   bpchyd
 # Class:      CS5201
 # Assignment: 6
 # File:       makefile
 # Credit:     Derived from makefile by Rob Wiehage

 # Basic makefile for compiling the matrix project
###############################################################################

# Compiler
CXX = /usr/bin/g++
FLAGS = -g -Wall -W -pedantic-errors -std=c++11

# Code Files
SOURCES = ${wildcard *.cpp}
HEADERS = ${wildcard *.h}
OBJECTS = ${SOURCES:%.cpp=%.o}

# Project
default: driver

%.o: %.cpp
	@echo "Compiling $<"
	@${CXX} ${FLAGS} -c $< -o $@

driver: ${OBJECTS}
	@echo "Building $@"
	@${CXX} ${FLAGS} ${OBJECTS} -o $@
	@echo "Successfully built $@"

clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
	-@rm -f dependencies > /dev/null 2>&1
	-@rm -f ${OBJECTS} > /dev/null 2>&1
	-@rm -f ${wildcard *.h.gch}
	-@rm -f ${wildcard *.hpp.gch}

# Dependencies
dependencies: ${SOURCES} ${HEADERS}
	@${CXX} -MM *.cpp > $@

-include dependencies
