
.PHONY: all

all: ray
	./ray

ray: ray.c Makefile
	cc -Wall ray.c -o ray -lm

