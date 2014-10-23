
.PHONY: all clean assemble run show

TOOLS=$(HOME)/others/ROPE/dist/tools/mac
AUTOCODER=$(TOOLS)/autocoder
IBM1401=$(TOOLS)/ibm1401

all: ray
	./ray

ray: ray.c Makefile
	cc -Wall ray.c -o ray -lm

assemble: ray.aut Makefile
	$(AUTOCODER) -e S -t ray.mt1 -o ray.cd -l ray.lst ray.aut

run: assemble
	$(IBM1401) < runray.sim

show: run
	cat ray.out

clean:
	rm -f ray *.out *.lst *.cd *.cdr *.brk *.mt1
