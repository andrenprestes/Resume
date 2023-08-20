CC=gcc
CFLAGS=-I. -Wall  -lm
DEPS = Jogo.h Cartas.h
OBJ = Bisca.o Jogo.o Cartas.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


Bisca: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run:
	valgrind --leak-check=full --track-origins=yes -v ./Bisca

clean:
	rm -f *.o
