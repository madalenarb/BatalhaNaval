CC = gcc
CFLAGS = -Wall -std=c11 -Wextra -g

default: wargame

wargame: main.o tabuleiro.o pecas.o bibliotecadepecas.o modo_p.o
	$(CC) $(CFLAGS) -o wargame main.o tabuleiro.o pecas.o bibliotecadepecas.o modo_p.o

main.o: main.c pecas.h tabuleiro.h bibliotecadepecas.h
	$(CC) $(CFLAGS) -c main.c

tabuleiro.o: tabuleiro.c tabuleiro.h headers.h
	$(CC) $(CFLAGS) -c tabuleiro.c

pecas.o: pecas.c pecas.h headers.h
	$(CC) $(CFLAGS) -c pecas.c

bibliotecadepecas.o: bibliotecadepecas.c bibliotecadepecas.h headers.h
	$(CC) $(CFLAGS) -c bibliotecadepecas.c

modo_p.o: modo_p.c modo_p.h pecas.h bibliotecadepecas.h tabuleiro.h
	$(CC) $(CFLAGS) -c modo_p.c

clean:
	rm -rf *.o $(wargame) *~