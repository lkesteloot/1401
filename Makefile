
.PHONY: all clean

all: ray
	./ray

ray: ray.c Makefile
	cc -Wall ray.c -o ray -lm

clean:
	rm -f ray *.out *.lst *.cd *.cdr *.brk
