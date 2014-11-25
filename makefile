#Makefile for Runner
#Created by Murray Christopherson. Updated April 2010

#Defines the compiler of choice
CC=g++
#Defines the flags for creating the compiled 
CFLAGS=-c -Wall
#Defines the flags for linking
LDFLAGS=
#Defines the source files required for the compiling
SOURCES=src/Runner.cpp src/main.cpp
#Defines the name of the object files associated with the source files
OBJECTS=$(SOURCES:.cpp=.o)
#Defines the final name of the executable
APPLICATION=runner

#######################################################################################################################################
#Advanced Users Only
#Below is the script to compile the program. Should work, assuming the macros are specified correctly. Otherwise, edit below this line.
#######################################################################################################################################

all: $(APPLICATION) $(SOURCES)

$(APPLICATION): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
    
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
    
clean:
	find . -name "*.o" -print0 | xargs -0 rm -f
	find . -name "$(APPLICATION)" -print0 | xargs -0 rm -f
