## What is it
This file "do-while-loop" is a CPP program that demonstrates do-while loops. It asks the user for integer input between 0 and 20, outputting whether it is larger, smaller or exactly 10.

Key difference from the while loop version - this uses `do {...} while (condition)` instead of `while (condition) {...}`. Practically the same result when using `while (true)` with `break`, but good to understand both syntaxes.

Also includes proper input validation using `std::cin.fail()`, `std::cin.clear()`, and `std::cin.ignore()` - so typing letters or symbols doesn't break it any more. It'll just tell you off and ask again.

Enter -1 to quit.

## How I've built it, and what it outputs
g++ -S -masm=intel do-while-loop.cpp = ASM file output

g++ -masm=intel do-while-loop.cpp -o do-while-loop = Intel ELF file