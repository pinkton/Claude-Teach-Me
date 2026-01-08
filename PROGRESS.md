# Learning Progress Tracker

**Last Updated:** 2026-01-08

This file tracks session-by-session progress. See CLAUDE.md for methodology and overall learning path.

---

## Current Session: 2026-01-08

### Session Focus
- Continued pointers — array/pointer relationship
- Identified mental model shift needed (high-level vs low-level thinking)
- Pointer arithmetic iteration

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

**7. Key Insight Discussed**
- Application developers think in terms of *what* data represents (`player.health`)
- Modders/RE work underneath: `base_address + 0x4A8`
- This is the fundamental difference between creating applications and manipulating them

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

    return 0;
}
```

### Where We Left Off

About to try iterating by incrementing the pointer itself (`p++`) instead of using `p + i`. Question posed: "What does `p++` do in terms of bytes?"

**Next code to add:**
```cpp
    std::cout << "\n--- Iterate by Incrementing Pointer ---" << std::endl;
    int* p2 = scores;
    int* end = scores + 5;
    while (p2 < end) {
        std::cout << *p2 << std::endl;
        p2++;
    }
```

**Question to answer:** What does `p++` do in terms of bytes? (Expected: adds 4 bytes because `int` is 4 bytes — pointer arithmetic scales by `sizeof(type)`)

### Next Session Plan

1. **Answer the question** — What does `p++` do in terms of bytes?
2. **Implement pointer increment iteration** — The `while (p < end)` pattern
3. **Modify values through pointers** — Show `*ptr = 100` changes the original variable
4. **Practice converting notations** — `array[i]` ↔ `*(array + i)` exercises

### Knowledge to Test Next Session

**Must ask these to reinforce mental model shift:**

Basic recall:
- "What does `&variable` give you?" (the memory address)
- "What does `*pointer` give you?" (the value at that address)

Syntax distinction:
- "What's the difference between `int* ptr` and `*ptr`?" (declaration vs dereferencing)

The critical insight (ask multiple ways):
- "What does `scores[2]` actually do under the hood?" (pointer arithmetic + dereference)
- "Is `scores[2]` a pointer or a value?" (a value — it's already dereferenced)
- "Rewrite `scores[3]` using pointer syntax." (`*(scores + 3)`)
- "Rewrite `*(ptr + 1)` using array syntax." (`ptr[1]`)

Address arithmetic:
- "Why does `scores + 1` add 4 bytes, not 1 byte?" (scales by sizeof(type))
- "If `scores` is at `0x1000`, what's the address of `scores[2]`?" (0x1008)

Equivalence:
- "Are `scores` and `&scores[0]` the same?" (yes — both address of first element)

New for this session:
- "Why use pointer arithmetic over `array[i]`?" (functions receive pointers not arrays, memory manipulation works with raw addresses)
- "What's the difference between how app devs and modders think about data?" (abstractions vs raw memory/offsets)

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

### Pointers - IN PROGRESS (2026-01-08)
- ✓ Address-of operator (`&`)
- ✓ Pointer declaration (`int* ptr`)
- ✓ Dereference operator (`*ptr`)
- ✓ Arrays are pointers (`scores` == `&scores[0]`)
- ✓ Indexing is dereferencing (`scores[2]` == `*(scores + 2)`)
- ✓ Address spacing observation (4 bytes per int)
- ✓ Pointer arithmetic iteration with `*(p + i)`
- ○ Mental model reinforcement (ongoing - requires practice)
- ☐ Pointer increment iteration (`p++`)
- ☐ Modifying values through pointers

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
- [ ] Pointer increment iteration (`p++` pattern)
- [ ] Modifying values through pointers
- [ ] Reinforce pointer/array mental model through varied exercises
- [ ] Different data types (char, float, string, bool)
- [ ] Memory management (heap vs stack from developer perspective)

**Concept Requiring Active Reinforcement:**
The relationship between arrays and pointers, specifically that `array[i]` is syntactic sugar for `*(array + i)`. User's high-level mental model ("pointing to a value") needs to be replaced with low-level understanding ("dereferencing an address"). This will be tested at the start of each session until it becomes automatic.

**Next Phase:** Windows Internals & DLL Development
