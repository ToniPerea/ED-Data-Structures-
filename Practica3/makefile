
INC = ./include
SRC = ./src
OBJ = ./obj
DOC = ./doc
DATA = ./datos
BIN = ./bin
LIB = ./lib
CXX = g++
CFLAGS = -std=c++11 -I$(INC)

all: $(BIN)/main

init: 
	@mkdir -p $(BIN) $(DATA) $(OBJ) $(DOC) $(INC) $(SRC) $(LIB)

# Reglas de construccion de la entrega
entrega: clean docs
	tar -cvf ../cola_max.tar .

docs:
	doxygen $(DOC)/doxys/Doxyfile

$(BIN)/main: $(SRC)/Cola_max_vd.cpp $(SRC)/Cola_max_pila.cpp $(SRC)/pruebacola_max.cpp docs
	$(CXX) $(CFLAGS) $(SRC)/pruebacola_max.cpp -o $(BIN)/main


# Reglas de limpieza
clean:
	@echo "Limpiando ..."
	@rm -f $(BIN)/*  $(OBJ)/*  $(LIB)/*
