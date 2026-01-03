## What is it
This file "if-greater-smaller" is a CPP program demonstrating while loops and input validation. Asks the user for integer input between 0 and 20, outputting whether it is larger, smaller or exactly 10.

Uses `while (true)` with `break` to exit when user enters -1. Also includes proper input validation with `std::cin.fail()`, `std::cin.clear()`, and `std::cin.ignore()` - so typing letters or symbols won't break it any more. Loops back and asks again until you give it a valid number.

Enter -1 to quit.

## How I've built it, and what it outputs
g++ -S -masm=intel if-greater-smaller.cpp = ASM file output

g++ -masm=intel if-greater-smaller.cpp -o if-greater-smaller = Intel ELF file