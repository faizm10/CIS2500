worksheetW2: read1Grads.o read2Grads.o w2Main.o oneMoreDone.o
	gcc -Wall -std=c99 read1Grads.o oneMoreDone.o read2Grads.o w2Main.o -o worksheetW2

read2Grads.o: read2Grads.c
	gcc -Wall -std=c99 -c read2Grads.c

read1Grads.o: read1Grads.c
	gcc -Wall -std=c99 -c read1Grads.c

oneMoreDone.o: oneMoreDone.c
	gcc -Wall -std=c99 -c oneMoreDone.c

w2Main.o: w2Main.c
	gcc -Wall -std=c99 -c w2Main.c
	
clean:
	rm *.o worksheetW2
