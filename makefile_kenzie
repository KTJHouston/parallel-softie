CC = g++
CFLAGS = -I ./include
EXE = softie.exe
OBJECT = DNA.o 
SOURCE = ./src
INCLUDE = ./include

all: $(EXE)

$(EXE): $(OBJECT) 
	$(CC) -o $@ $< $(CFLAGS) 

$(OBJECT): $(SOURCE)/DNA.cpp $(INCLUDE)/DNA.h
	$(CC) -c $(SOURCE)/DNA.cpp $< $(CFLAGS)

test:
	./$(EXE)

clean:
	rm -rf *.o *.exe 