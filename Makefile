CFLAGS=-std=c11 -g -static

atcc:atcc.c

test: atcc
	./test.sh

clean:
	rm -f atcc *.o *~ tmp*

.PHONY: test clean 