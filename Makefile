CFLAGS=-std=c11 -g -static

kcc: kcc.c

test: kcc
	./test.sh

clean:
	rm -f kcc *.o *~ tmp*

.PHONY: test clean
