# Matthew Miller
# May 6, 2016

# Simple makefile for aprspass program
TARGET=aprspass
CC=g++

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET)

