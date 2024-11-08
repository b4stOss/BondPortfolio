CC = gcc-14
LIBS = -ljson-c

all: bond_calculator

bond_calculator: main.c bond.c portfolio.c scenario.c file_handler.c utils.c
	$(CC) -o bond_calculator main.c bond.c portfolio.c scenario.c file_handler.c utils.c $(LIBS)

clean:
	rm -f bond_calculator
