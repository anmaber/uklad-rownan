CC=g++
FLAGS=-Wall
LDFLAGS= 
SOURCES= *.cpp
OBJECTS=$(SOURCES: .cpp=.o)
EXECUTABLE=uklad

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

