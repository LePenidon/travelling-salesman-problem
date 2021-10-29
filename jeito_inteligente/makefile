CFLAGS = -std=c99 -pedantic-errors -Wall -lm

all: functions.o item.o lista.o main.o 
	gcc functions.o item.o lista.o main.o -o execute $(CFLAGS);./execute

functions.o:
	gcc -c ./functions/functions.c -I/functions -o functions.o

lista.o:
	gcc -c ./TAD_lista_simplesmente_encadeada/lista.c $(CFLAGS) -I/TAD_lista_simplesmente_encadeada -o lista.o

main.o:
	gcc -c main.c $(CFLAGS) -I/ -o main.o

item.o:
	gcc -c ./TAD_lista_simplesmente_encadeada/TAD_item/item.c $(CFLAGS) -I./TAD_lista_simplesmente_encadeada/TAD_item/ -o item.o

run:
	./execute

clean:
	rm *.o *.zip execute
