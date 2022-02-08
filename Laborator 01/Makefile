CC=gcc
FLAGS=-std=c9x
EXE1=charTest
EXE2=longTest
OBJ1=charTest.c
OBJ2=longTest.c
HEADER=OrderedSet.h

build: $(EXE1) $(EXE2)

$(EXE1) : $(OBJ1) $(HEADER)
	$(CC) $(FLAGS) $(OBJ1) -o $(EXE1)
$(EXE2) : $(OBJ2) $(HEADER)
	$(CC) $(FLAGS) $(OBJ2) -o $(EXE2)

.PHONY: clean 
clean:
	rm -f $(EXE1) $(EXE2)