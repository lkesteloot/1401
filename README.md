
These are programs for the [IBM 1401](https://en.wikipedia.org/wiki/IBM_1401) computer.

The goal is to write a simple ray tracer. It will read a scene description from punch cards
and print the image on the printer using ASCII art.

The `circle.aut` program draws a circle on the printer. It was written to test the
loop and printing logic.

The `ray.c` program is a fixed-point ray tracer in C. It's the prototype code for the
real version. It prints the scene on the console.

To run the `.aut` files, install ROPE (see below).

Resources
---------

- [ROPE 1401 assembler, emulator, and IDE](https://github.com/jpf/ROPE)
- [1401 Reference manual](http://bitsavers.trailing-edge.com/pdf/ibm/140x/A24-1403-5_1401_Reference_Apr62.pdf)
- [Autocoder specification](http://www.bitsavers.org/pdf/ibm/140x/J24-1434-2_autocoderSpec_61.pdf)

