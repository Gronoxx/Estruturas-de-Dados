# Makefile

# Diretórios
SRCDIR := src
INCDIR := include
OBJDIR := obj
BINDIR := bin

# Nome do executável
EXEC := $(BINDIR)/programa

# Fontes
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Opções de compilação
CFLAGS := -Wall -Wextra -I$(INCDIR)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	gcc $^ -o $@ -lm

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc -c $(CFLAGS) $< -o $@ 

clean:
	rm -f $(OBJDIR)/*
	rm -f $(BINDIR)/*
	rm -f *.txt

run:
	./$(EXEC) -o saida.txt -s 10 -n 10

