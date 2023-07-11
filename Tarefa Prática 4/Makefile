CC=g++
CFLAGS=-c -Wall
LDFLAGS=
BINDIR=bin
SRCDIR=src
OBJDIR=obj
SOURCES=$(SRCDIR)/main.cpp $(SRCDIR)/fila.cpp $(SRCDIR)/pilha.cpp
OBJECTS=$(OBJDIR)/main.o $(OBJDIR)/fila.o $(OBJDIR)/pilha.o
EXECUTABLE=$(BINDIR)/programa

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJDIR)/*
	rm -f $(BINDIR)/* 

run:
	./$(EXECUTABLE)
