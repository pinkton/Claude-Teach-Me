## GCC commands
### Create ELF
g++ -masm=intel <file.cpp> -o <output>

### Create ADM file
g++ -S -masm=intel <file.cpp>
