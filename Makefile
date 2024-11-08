CC = gcc-14
LIBS = -ljson-c
INCLUDE_DIR = include
SRC_DIR = src

all: bond_calculator

bond_calculator: $(SRC_DIR)/main.c $(SRC_DIR)/bond.c $(SRC_DIR)/portfolio.c $(SRC_DIR)/scenario.c $(SRC_DIR)/file_handler.c $(SRC_DIR)/utils.c
	$(CC) -o bond_calculator $(SRC_DIR)/main.c $(SRC_DIR)/bond.c $(SRC_DIR)/portfolio.c $(SRC_DIR)/scenario.c $(SRC_DIR)/file_handler.c $(SRC_DIR)/utils.c -I$(INCLUDE_DIR) $(LIBS)

clean:
	rm -f bond_calculator
