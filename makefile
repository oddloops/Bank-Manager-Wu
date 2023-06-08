# Variables used by makefile (assume have code.c code.h and main.c exists)

CC=g++
CFLAGS=-Wall -std=c11
EXE=main

# Recipes for targets

main: $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(EXE).cpp

# PHONY targets

.PHONY: clean
clean:
	rm -rf *~ $(EXE)

# End of makefile
