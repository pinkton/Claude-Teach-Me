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
- Different data types (`char*` vs `int*`)

### What Was Completed Today

**1. Pointer Fundamentals - VERIFIED**
- Confirmed dereference operator works: `*ptr` outputs `42`

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

**6. Pointer Arithmetic Iteration - COMPLETED**
- Iterated through array using `*(p + i)` instead of `scores[i]`
- Discussed why pointer arithmetic matters for modding vs application development

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
- Changed `scores[2]` from `30` to `555` using `*(scores + 2) = 555`
- Core principle: write to an address, the original data changes
- This is the foundation of game memory modification

**11. ASLR and Offsets - CONCEPTUAL UNDERSTANDING**
- ASLR randomises base addresses each process load
- But **offsets stay the same** — structure inside executable is fixed
- Workflow: get module base at runtime (`GetModuleHandle()`), add known offset
- `health_ptr = base + 0x4A8` works every time with correct offset
- This is why game updates break mods — offsets shift when code changes
- Cheat Engine does exactly this: find value → pointer scan → trace to static offset

**12. Different Data Types (`char*`) - COMPLETED**
- Created `char` array and `char*` pointer
- Observed 1-byte spacing between addresses (vs 4-byte for `int*`)
- Pointer arithmetic scales automatically based on type
- `cout` quirk: `char*` prints as string, need `(void*)` cast to see address

**13. Hex Offset Calculation - PRACTISED**
- Question: `double` array at `0x1000`, what's `&arr[3]`?
- Answer: 3 × 8 = 24 decimal = 0x18 hex, so `0x1018`
- Caught mistake: wrote `0x1024` (treated 24 as hex instead of decimal)
- Reminder: convert to hex *after* calculating in decimal

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

    std::cout << "\n--- Modify Middle Element ---" << std::endl;
    std::cout << "scores[2] before: " << scores[2] << std::endl;
    
    *(scores + 2) = 555;
    
    std::cout << "scores[2] after: " << scores[2] << std::endl;

    std::cout << "\n--- Pointer Arithmetic with Different Types ---" << std::endl;
    
    char letters[5] = {'A', 'B', 'C', 'D', 'E'};
    char* cp = letters;
    
    std::cout << "Address of letters[0]: " << (void*)cp << std::endl;
    std::cout << "Address of letters[1]: " << (void*)(cp + 1) << std::endl;
    std::cout << "Address of letters[2]: " << (void*)(cp + 2) << std::endl;

    return 0;
}
```

### Where We Left Off

**Pointers section COMPLETE.** Covered all fundamentals:
- Declaration, dereferencing, address-of
- Array/pointer equivalence
- Pointer arithmetic (both iteration patterns)
- Modification through pointers
- Different type sizes (`int*` = 4 bytes, `char*` = 1 byte)
- ASLR and offsets conceptually

**Next topic: Structs**

### Next Session Plan

1. **Quick review questions** — Test pointer concepts (see below)
2. **Structs** — Custom data structures
   - Define a struct (e.g., `Player` with health, x, y)
   - Access members with `.` operator
   - Pointers to structs and `->` operator
   - Calculate offsets within structs (directly relevant to game modding)
3. **Memory layout of structs** — How members are arranged contiguously

### Knowledge to Test Next Session

**Pointer fundamentals:**
- "What does `&variable` give you?" (the memory address)
- "What does `*pointer` give you?" (the value at that address)
- "What's the difference between `int* ptr` (declaration) and `*ptr` (expression)?" (type vs dereference operator)

**Array/pointer equivalence:**
- "What does `scores[2]` actually do under the hood?" (pointer arithmetic + dereference: `*(scores + 2)`)
- "Rewrite `*(ptr + 3)` using array syntax." (`ptr[3]`)

**Pointer arithmetic:**
- "What does `p++` do when `p` is an `int*`?" (adds 4 bytes)
- "What does `p++` do when `p` is a `char*`?" (adds 1 byte)
- "If a `double*` points to `0x2000`, what's `p + 3`?" (0x2018 — 3 × 8 = 24 = 0x18)

**Modification:**
- "How do you change the value at an address?" (`*ptr = newvalue`)

**Practical:**
- "Why do game updates break mods?" (offsets shift when code changes)
- "Why cast `char*` to `void*` when printing?" (`cout` treats `char*` as string)

---

## Previous Session: 2026-01-07

### What Was Completed

- `sizeof` operator for dynamic array length calculation
- Bash shortcuts (`compile-asm`, `gitpush`)
- Started pointers (address-of, declaration, ASLR observation)

---

## Recent Milestones

### Pointers - FUNDAMENTALS COMPLETE (2026-01-08)
- ✓ Address-of operator (`&`)
- ✓ Pointer declaration (`int* ptr`)
- ✓ Dereference operator (`*ptr`)
- ✓ Declaration vs expression context for `*`
- ✓ Arrays are pointers (`scores` == `&scores[0]`)
- ✓ Indexing is dereferencing (`scores[2]` == `*(scores + 2)`)
- ✓ Address spacing observation
- ✓ Pointer arithmetic iteration with `*(p + i)`
- ✓ Pointer increment iteration with `p++`
- ✓ Modifying values through pointers
- ✓ References vs pointers distinction
- ✓ ASLR and offsets conceptual understanding
- ✓ Different data types (`char*` = 1 byte, `int*` = 4 bytes)
- ✓ Hex offset calculation practice

### Arrays - COMPLETED (2026-01-07)
- ✓ Declaration, initialisation, zero-based indexing
- ✓ Memory layout understanding (contiguous chunks)
- ✓ Undefined behaviour demonstration
- ✓ `sizeof` operator for dynamic length calculation

### Loops - COMPLETED (Previous Sessions)
- ✓ `while`, `do-while`, `for` loops
- ✓ Loop control (`break`, `continue`)
- ✓ Input validation

### Functions - COMPLETED (Previous Sessions)
- ✓ Parameters and return values
- ✓ x86-64 calling conventions

### Git Workflow - COMPLETED (Previous Sessions)
- ✓ Branch strategy, authentication, divergent branches

---

## Current Learning Phase

**Phase:** C/C++ Development (Phase 2 of 5)

**Immediate Goals:**
- [ ] Structs — custom data structures (NEXT)
- [ ] Pointers to structs and `->` operator
- [ ] Memory layout and offset calculation within structs
- [ ] Memory management (heap vs stack)

**Next Phase:** Windows Internals & DLL Development
