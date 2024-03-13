MustansarFaizA1: MustansarFaizA1.o MustansarFaizA1Main.o
	gcc MustansarFaizA1.o MustansarFaizA1Main.o -o MustansarFaizA1 -lm

MustansarFaizA1.o: MustansarFaizA1.c givenA1.h
	gcc -Wall -std=c99 -c MustansarFaizA1.c

MustansarFaizA1Main.o: MustansarFaizA1Main.c givenA1.h
	gcc -Wall -std=c99 -c MustansarFaizA1Main.c

clean:
	rm -f *.o MustansarFaizA1
