all: _2choice

_2choice: test.o _2-choice_hash.o hash.o
	gcc -o _2choice test.o _2-choice_hash.o hash.o

hash.o: hash.c hash.h
	gcc -c hash.c
	
_2-choice_hash.o: _2-choice_hash.c _2-choice_hash.h
	gcc -c _2-choice_hash.c
	
test.o: test.c _2-choice_hash.h
	gcc -c test.c
	
clean:
	rm -rf *.o _2choice
