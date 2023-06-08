# Variables used by makefile

CC=g++
CXXFLAGS=-Wall -std=c++17
EXE=main
OBJECTS=

# Recipes for targets
main: $(OBJECTS)
	$(CC) $(CXXFLAGS) -o $(EXE) $(EXE).cpp

# PHONY targets

.PHONY: clean
clean:
	rm -rf *~ $(EXE)

# End of makefile
