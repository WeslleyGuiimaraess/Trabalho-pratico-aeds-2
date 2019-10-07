all: tp clean

tp: fila.o tp.o
	gcc fila.o tp.o -o tp

tp.o: tp.c fila.h
	gcc -g -c tp.c

fila.o: fila.c fila.h
	gcc -g -c fila.c

clean:
	rm *.o
