## What is it
This file "arrays" demonstrates array fundamentals in C++. Created an array of 5 integers (powers of 2: 1, 2, 4, 8, 16) and practiced accessing elements, iterating with for loops, and examining memory layout.

Key things learned:

C++ doesn't check array bounds - accessing `numbers[100]` compiles fine and just reads garbage from the stack

Undefined behaviour is weird - doesn't crash, just returns whatever was in that memory location

Intentionally accessed out-of-bounds indices to see undefined behaviour in action. Got random stack values (32115, 719494544, etc.) from reading memory that technically exists but isn't part of the array. 

## How I've built it, and what it outputs
g++ -S -masm=intel arrays.cpp = ASM file output

g++ -masm=intel arrays.cpp -o arrays = Intel ELF file
