# Variáveis
CC := g++
CFLAGS := -std=c++11
INCLUDE_DIR := include
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Arquivos fonte
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
EXECUTABLE := $(BIN_DIR)/program

# Regras de compilação
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Regras do Makefile
.PHONY: all clean run

all: $(EXECUTABLE)

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*
	rm binario_1.txt binario_2.txt binario_3.txt binario_4.txt saida_1.txt saida_2.txt saida_3.txt saida_4.txt 

run:
	$(EXECUTABLE) -c entrada_1.txt binario_1.txt
	$(EXECUTABLE) -d binario_1.txt saida_1.txt
	$(EXECUTABLE) -c entrada_2.txt binario_2.txt
	$(EXECUTABLE) -d binario_2.txt saida_2.txt
	$(EXECUTABLE) -c entrada_3.txt binario_3.txt
	$(EXECUTABLE) -d binario_3.txt saida_3.txt
	$(EXECUTABLE) -c entrada_4.txt binario_4.txt
	$(EXECUTABLE) -d binario_4.txt saida_4.txt

