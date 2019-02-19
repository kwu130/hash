all: chain

chain: test.o chained_hash.o hash.o
	gcc -o chain test.o chained_hash.o hash.o -lm

hash.o: hash.c hash.h
	gcc -c hash.c
	
chained_hash.o: chained_hash.c chained_hash.h
	gcc -c chained_hash.c
	
test.o: test.c chained_hash.h
	gcc -c test.c
	
clean:
	rm -rf *.o chain
