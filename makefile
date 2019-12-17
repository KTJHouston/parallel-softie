IDIR = ./include
_DEPS = Island.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

SOURCE = ./src

ODIR = ./obj
_OBJ = main.o DNA.o best_fit.o Island.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

CC = g++
CFLAGS = -I$(IDIR) -std=c++14 -fopenmp

EXE = softie.exe

$(ODIR)/%.o: $(SOURCE)/%.cpp $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS) 

$(EXE): $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) 

test:
	./$(EXE)

clean:
	rm -f $(ODIR)/*.o *.out $(EXE)