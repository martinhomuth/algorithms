
#define the distinct parts of the project
FOLDERS := chapter02

#define the Objectdirectories
OBJDIRS := $(addprefix build/,$(FOLDERS))

#define the C source files
SOURCEDIRS := $(addprefix src/,$(FOLDERS))

#define the C compiler
CC=gcc

CFLAGS = -Wall -Wextra -g -O3 --std=c11 -pedantic 

SOURCEFILES := $(foreach dir, $(SOURCEDIRS), $(wildcard $(dir)/*.c)) src/main.c
HEADERFILES := $(foreach dir, $(SOURCEDIRS), $(wildcard $(dir)/*.h))

.PHONY: depend clean help 

all: algorithms

algorithms: build/chap2

build/chap2: $(SOURCEFILES) $(HEADERFILES)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LFLAGS) $(LIBS)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(EXECUTABLE) $(OBJS) $(LFLAGS) $(LIBS)

# target: help - Displays some help and the available targets.
help:
	@egrep "^# target:" Makefile

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r build/*
	$(RM) -r lib/*.a
	$(RM) -r logs/*
