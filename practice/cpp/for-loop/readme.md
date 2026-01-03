## What is it
This file "for-loop" demonstrates for loops in C++. Three different examples showing different for loop patterns:

1. Counting forwards from 1 to 20 - standard increment (`i++`)
2. Counting backwards from 10 to 0 - decrement (`i--`)
3. Counting in steps of 2 from 0 to 20 - custom increment (`i+=2`)

Good practice for understanding the three parts of a for loop: initialization, condition, and update. Also learned the difference between `i+=2` (add 2 to i) vs `i=+2` (assign positive 2 to i) - caught that bug during development.

## How I've built it, and what it outputs
g++ -S -masm=intel for-loop.cpp = ASM file output

g++ -masm=intel for-loop.cpp -o for-loop = Intel ELF file