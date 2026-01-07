# Learning Progress Tracker

**Last Updated:** 2026-01-07

This file tracks session-by-session progress. See CLAUDE.md for methodology and overall learning path.

---

## Current Session: 2026-01-07

### Session Focus
- Completed `sizeof` operator for arrays
- Created bash workflow shortcuts
- Started pointers (address-of and dereference operators)

### What Was Completed Today

**1. sizeof Operator - COMPLETED**
- Learnt `sizeof(array) / sizeof(array[0])` for dynamic array length calculation
- Understood why `sizeof(array[0])` is better than `sizeof(type)` (maintainability)
- Tested with different array sizes and types (`int` vs `char`)
- Proved that dynamic sizing adapts automatically when array size changes

**2. Bash Shortcuts - COMPLETED**
- Created `compile-asm` function in `~/.bashrc`
  - Compiles C++ to executable and Intel-syntax assembly in one command
  - Usage: `compile-asm filename.cpp`
- Created `gitpush` function in `~/.bashrc`
  - Stages, commits, and pushes to main in one command
  - Usage: `gitpush "commit message"`
- Documented both shortcuts in README.md and CLAUDE.md

**3. Pointers - IN PROGRESS**
- Created `practice/cpp/pointers/` directory and `pointers.cpp`
- Learnt address-of operator (`&`) - gets memory address of variable
- Learnt pointer declaration syntax (`int* ptr = &num`)
- Observed ASLR in action (addresses change each run)
- Started learning dereference operator (`*ptr`) to access value at address

### Where We Left Off

**File:** `practice/cpp/pointers/pointers.cpp`

**Current code state:**
```cpp
#include <iostream>

int main() {
    int num = 42;
    int* ptr = &num;

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Address of num: " << &num << std::endl;
    std::cout << "Value stored in ptr: " << ptr << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;  // About to test this

    return 0;
}
```

**Next action:** Compile and run to verify `*ptr` outputs `42` (the value, not the address)

### Next Session Plan

1. **Verify dereference operator** - Run pointers.cpp, confirm `*ptr` shows `42`
2. **Arrays and pointers relationship** - Demonstrate that arrays ARE pointers
3. **Pointer arithmetic** - Show how `ptr + 1` moves by `sizeof(type)` bytes
4. **Practice exercise** - Iterate through an array using pointer arithmetic instead of indexing

### Knowledge to Test Next Session

Before continuing pointers:
- "What does `&variable` give you?" (address)
- "What does `*pointer` give you?" (value at that address)
- "What's the difference between `int* ptr` (declaration) and `*ptr` (dereferencing)?"

---

## Recent Milestones

### Arrays - COMPLETED (2026-01-07)
- ✓ Declaration, initialisation, zero-based indexing
- ✓ Memory layout understanding (contiguous 4-byte chunks for int)
- ✓ Undefined behaviour demonstration (out-of-bounds access)
- ✓ `sizeof` operator for dynamic length calculation
- ✓ Range-based for loops mentioned (C++11 feature)

### Loops - COMPLETED (Previous Sessions)
- ✓ `while` loops - condition checked first
- ✓ `do-while` loops - condition checked after, guaranteed one execution
- ✓ `for` loops - best for counting/iteration
- ✓ Loop control - `break` and `continue`
- ✓ Input validation with `cin.fail()`, `cin.clear()`, `cin.ignore()`

### Functions - COMPLETED (Previous Sessions)
- ✓ Parameters and return values
- ✓ x86-64 calling conventions (EDI/ESI for params, EAX for return)
- ✓ Compiling to assembly for analysis

### Git Workflow - COMPLETED (Previous Sessions)
- ✓ Branch strategy (feature → develop → main)
- ✓ GitHub authentication (Personal Access Token)
- ✓ Handling divergent branches
- ✓ Understanding when to use full workflow vs pragmatic commits

---

## Current Learning Phase

**Phase:** C/C++ Development (Phase 2 of 5)

**Immediate Goals:**
- [ ] Complete pointers fundamentals
- [ ] Pointer arithmetic and array/pointer relationship
- [ ] Different data types (char, float, string, bool)
- [ ] Memory management (heap vs stack from developer perspective)

**Next Phase:** Windows Internals & DLL Development
