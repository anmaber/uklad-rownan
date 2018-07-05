CC=g++
STANDARD=-std=c++14
FLAGS=-Wall
LDFLAGS= 
SOURCES= *.cpp
OBJECTS=$(SOURCES: .cpp=.o)
EXECUTABLE=uklad

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(STANDARD) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(STANDARD) $(CFLAGS) $< -o $@

