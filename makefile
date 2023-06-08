# Variables used by makefile (assume have code.c code.h and main.c exists)

CC=g++
CXXFLAGS=-Wall -std=c++17
EXE=main

# Recipes for targets

main: $(OBJECTS)
	$(CC) -o $(EXE) $(EXE).cpp

# PHONY targets

.PHONY: clean
clean:
	rm -rf *~ $(EXE)

# End of makefile
