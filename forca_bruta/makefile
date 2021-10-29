CFLAGS = -std=c99 -pedantic-errors -Wall -lm

all: functions.o lista_info.o it_info.o lista_mov.o it_mov.o main.o
	gcc functions.o lista_info.o it_info.o lista_mov.o it_mov.o main.o -o run $(CFLAGS);./run

functions.o:
	gcc -c ./functions/functions.c $(CFLAGS) -I/functions -o functions.o

main.o:
	gcc -c main.c $(CFLAGS) -o main.o

lista_info.o:
	gcc -c ./lista_info/lista_info.c $(CFLAGS) -I/lista_info -o lista_info.o

it_info.o:
	gcc -c ./lista_info/it_info/it_info.c $(CFLAGS) -I/lista_info/it_info -o it_info.o

lista_mov.o:
	gcc -c ./lista_mov/lista_mov.c $(CFLAGS) -I/lista_mov -o lista_mov.o

it_mov.o:
	gcc -c ./lista_mov/it_mov/it_mov.c $(CFLAGS) -I/lista_mov/it_mov -o it_mov.o

run:
	./run

clean:
	rm *.o *.zip run
