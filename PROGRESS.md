# Learning Progress Tracker

**Last Updated:** 2026-01-08

This file tracks session-by-session progress. See CLAUDE.md for methodology and overall learning path.

---

## Current Session: 2026-01-08

### Session Focus
- Continued pointers — array/pointer relationship
- Identified mental model shift needed (high-level vs low-level thinking)
- Pointer arithmetic iteration
- Modifying values through pointers
- ASLR and offsets conceptual discussion

### What Was Completed Today

**1. Pointer Fundamentals - VERIFIED**
- Confirmed dereference operator works: `*ptr` outputs `42`
- Full output verified:
  ```
  Value of num: 42
  Address of num: 0x7ffd08750ca4
  Value stored in ptr: 0x7ffd08750ca4
  Value pointed to by ptr: 42
  ```

**2. Arrays ARE Pointers - COMPLETED**
- Proved `scores` and `&scores[0]` output identical addresses
- Array name by itself is the address of the first element

**3. Array Indexing is Pointer Arithmetic - COMPLETED**
- Proved `scores[2]` and `*(scores + 2)` both output `30`
- Bracket notation is syntactic sugar for pointer arithmetic + dereference
- `scores[i]` is equivalent to `*(scores + i)`

**4. Address Spacing Observation - COMPLETED**
- Displayed addresses of `scores[0]`, `scores[1]`, `scores[2]`
- Observed 4-byte increments (sizeof int)
- Pointer arithmetic scales by `sizeof(type)`, not by 1 byte

**5. Mental Model Gap Identified - CRITICAL**
- User has years of high-level thinking: "array[i] points to a value"
- Low-level reality: "array[i] dereferences an address"
- This is backwards from intuition and requires active reinforcement
- Added varied test questions to CLAUDE.md for future sessions

**6. Pointer Arithmetic Iteration - COMPLETED**
- Iterated through array using `*(p + i)` instead of `scores[i]`
- Discussed why pointer arithmetic matters:
  - Functions only receive pointers, not arrays
  - Memory manipulation and injection work with raw addresses
  - Application devs use abstractions; modders work underneath them

**7. Pointer Increment Iteration - COMPLETED**
- Implemented `while (p < end)` pattern with `p++`
- Understood `p++` adds `sizeof(type)` bytes (4 for int), not 1 byte
- Two patterns now known:
  - `*(p + i)` — fixed base, calculate offset
  - `p++` — move the pointer itself

**8. Declaration vs Operation Clarification - COMPLETED**
- `int* p` — declaration: "p is a pointer to int" (the `*` is part of the type)
- `*p` — expression: "dereference p" (the `*` is an operator)
- Same symbol, two jobs depending on context

**9. References vs Pointers - DISCUSSED**
- `int&` creates a reference (permanent alias, can't reassign, can't be null)
- `int*` creates a pointer (can reassign, can be null, explicit indirection)
- References useful for clean function parameters when modifying originals
- Pointers needed for memory manipulation work — references too "polite"

**10. Modifying Values Through Pointers - COMPLETED**
- Changed `scores[0]` from `10` to `999` using `*target = 999`
- Core principle: write to an address, the original data changes
- This is the foundation of game memory modification

**11. ASLR and Offsets - CONCEPTUAL UNDERSTANDING**
- ASLR randomises base addresses each process load
- But **offsets stay the same** — structure inside executable is fixed
- Workflow: get module base at runtime (`GetModuleHandle()`), add known offset
- `health_ptr = base + 0x4A8` works every time with correct offset
- This is why game updates break mods — offsets shift when code changes
- Cheat Engine does exactly this: find value → pointer scan → trace to static offset

### Current Code State

**File:** `practice/cpp/pointers/pointers.cpp`

```cpp
#include <iostream>

int main() {
    int num = 42;
    // int* ptr - declares a pointer (part of the type)
    // *ptr - dereferences a pointer (accesses the value)
    int* ptr = &num;

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Address of num: " << &num << std::endl;
    std::cout << "Value stored in ptr: " << ptr << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;

    // Arrays and pointers relationship
    int scores[5] = {10, 20, 30, 40, 50};

    std::cout << "\n--- Arrays ARE Pointers ---" << std::endl;
    std::cout << "scores (array name): " << scores << std::endl;
    std::cout << "&scores[0] (address of first element): " << &scores[0] << std::endl;

    std::cout << "\n--- Array Indexing is Pointer Arithmetic ---" << std::endl;
    std::cout << "scores[2]: " << scores[2] << std::endl;
    std::cout << "*(scores + 2): " << *(scores + 2) << std::endl;

    std::cout << "\n--- Watch the Addresses ---" << std::endl;
    std::cout << "Address of scores[0]: " << &scores[0] << std::endl;
    std::cout << "Address of scores[1]: " << &scores[1] << std::endl;
    std::cout << "Address of scores[2]: " << &scores[2] << std::endl;

    std::cout << "\n--- Iterate with Pointer Arithmetic ---" << std::endl;
    int* p = scores;  // p now points to first element
    for (int i = 0; i < 5; i++) {
        std::cout << "*(p + " << i << ") = " << *(p + i) << std::endl;
    }

    std::cout << "\n--- Iterate by Incrementing Pointer ---" << std::endl;
    int* p2 = scores;
    int* end = scores + 5;
    while (p2 < end) {
        std::cout << *p2 << std::endl;
        p2++;
    }

    std::cout << "\n--- Modify Through Pointer ---" << std::endl;
    std::cout << "scores[0] before: " << scores[0] << std::endl;
    
    int* target = scores;  // points to scores[0]
    *target = 999;         // change the value at that address
    
    std::cout << "scores[0] after: " << scores[0] << std::endl;

    return 0;
}
```

### Where We Left Off

Completed modifying values through pointers. Discussed ASLR and why offsets are the stable knowledge for game modding.

**Optional next:** Add middle element modification using `*(scores + 2) = 555` to combine pointer arithmetic with modification in one expression.

### Next Session Plan

1. **Quick review questions** — Test pointer concepts (see below)
2. **Middle element modification** — `*(scores + 2) = 555` if not done
3. **Different data types** — `char*` pointers and strings, see how pointer arithmetic changes
4. **Structs** — Custom data structures, foundation for understanding game objects

### Knowledge to Test Next Session

**Pointer fundamentals:**
- "What does `&variable` give you?" (the memory address)
- "What does `*pointer` give you?" (the value at that address)
- "What's the difference between `int* ptr` (declaration) and `*ptr` (expression)?" (type vs dereference operator)

**Array/pointer equivalence:**
- "What does `scores[2]` actually do under the hood?" (pointer arithmetic + dereference: `*(scores + 2)`)
- "Rewrite `*(ptr + 3)` using array syntax." (`ptr[3]`)
- "Are `scores` and `&scores[0]` the same?" (yes)

**Pointer arithmetic:**
- "What does `p++` do when `p` is an `int*`?" (adds 4 bytes — sizeof(int))
- "If `p` points to `0x1000` and is a `char*`, what's `p + 2`?" (0x1002)
- "If `p` points to `0x1000` and is an `int*`, what's `p + 2`?" (0x1008)

**Modification:**
- "How do you change the value at an address?" (dereference and assign: `*ptr = newvalue`)
- "If you write `*target = 999`, what happens to the original variable?" (it changes to 999)

**ASLR/Offsets (conceptual):**
- "What stays the same despite ASLR?" (offsets from module base)
- "Why do game updates break mods?" (code changes shift the offsets)
- "What's the general workflow for finding a value to modify in a game?" (find value → pointer scan → trace to static offset from base)

**References vs Pointers:**
- "What's `int&`?" (a reference — permanent alias)
- "Why use pointers over references for game modding?" (need explicit addresses, ability to reassign, work with arbitrary memory)

---

## Previous Session: 2026-01-07

### Session Focus
- Completed `sizeof` operator for arrays
- Created bash workflow shortcuts
- Started pointers (address-of and dereference operators)

### What Was Completed

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

**3. Pointers Started - PARTIAL**
- Created `practice/cpp/pointers/` directory and `pointers.cpp`
- Learnt address-of operator (`&`) - gets memory address of variable
- Learnt pointer declaration syntax (`int* ptr = &num`)
- Observed ASLR in action (addresses change each run)

---

## Recent Milestones

### Pointers - FUNDAMENTALS COMPLETE (2026-01-08)
- ✓ Address-of operator (`&`)
- ✓ Pointer declaration (`int* ptr`)
- ✓ Dereference operator (`*ptr`)
- ✓ Declaration vs expression context for `*`
- ✓ Arrays are pointers (`scores` == `&scores[0]`)
- ✓ Indexing is dereferencing (`scores[2]` == `*(scores + 2)`)
- ✓ Address spacing observation (4 bytes per int)
- ✓ Pointer arithmetic iteration with `*(p + i)`
- ✓ Pointer increment iteration with `p++`
- ✓ Modifying values through pointers
- ✓ References vs pointers distinction
- ✓ ASLR and offsets conceptual understanding
- ○ Mental model reinforcement (ongoing)
- ☐ Different data types (`char*`, strings)
- ☐ Structs and custom data structures

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
- [ ] Different data types (`char*` pointers, see how arithmetic changes)
- [ ] Structs — custom data structures (foundation for game objects)
- [ ] Memory management (heap vs stack from developer perspective)
- [ ] Reinforce pointer mental model through continued practice

**Concept Requiring Active Reinforcement:**
The relationship between arrays and pointers, specifically that `array[i]` is syntactic sugar for `*(array + i)`. User's high-level mental model ("pointing to a value") needs to be replaced with low-level understanding ("dereferencing an address"). This will be tested at the start of each session until it becomes automatic.

**Key Insight Gained This Session:**
ASLR randomises base addresses, but offsets remain constant. Game modding is about finding and using those stable offsets. This connects directly to Cheat Engine workflow and future DLL injection work.

**Next Phase:** Windows Internals & DLL Development
