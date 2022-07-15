CFLAGS=-std=c11 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

atcc: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS): atcc.h

test: atcc
	./test.sh

clean:
	rm -f atcc *.o *~ tmp*

.PHONY: test clean 