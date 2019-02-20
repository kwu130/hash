all: linear

linear: test.o linear_probing_hash.o hash.o
	gcc -o linear test.o linear_probing_hash.o hash.o -lm

hash.o: hash.c hash.h
	gcc -c hash.c
	
linear_probing_hash.o: linear_probing_hash.c linear_probing_hash.h
	gcc -c linear_probing_hash.c
	
test.o: test.c linear_probing_hash.h
	gcc -c test.c
	
clean:
	rm -rf *.o linear
