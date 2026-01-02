## What is it
This file "helloworld" is a simple CPP program, that prints the typical "Hello World" to screen. 

## How I've built it, and what it outputs
g++ -S -masm=intel helloworld.cpp = ASM file output in Intel (GCC by default does AT&T, weird)
g++ -masm=intel helloworld.cpp = Intel ELF file

Nothing fancy, but hey, everyone starts somewhere.
