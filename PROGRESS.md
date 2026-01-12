# Learning Progress Tracker

**Last Updated:** 2026-01-12

This file tracks session-by-session progress. See CLAUDE.md for methodology and overall learning path.

---

## Current Session: 2026-01-12

### Session Focus
- Comprehensive knowledge test across all topics (Git, Functions, Loops, Arrays, Pointers)
- Started structs — custom data structures
- Pointers to structs and `->` operator
- Memory layout and member offsets
- Treating structs as raw memory (critical for game modding)
- Pointer arithmetic scaling bug (Player* vs int*)

### What Was Completed Today

**1. Comprehensive Knowledge Test - COMPLETED**
- Tested retention across all previous topics after 4-day gap
- Score: 55/100 (needs improvement, but expected for new material)
- Identified critical gaps:
  - Function return values (RAX, not stack)
  - Array/pointer equivalence (`scores` == `&scores[0]`)
  - Pointer syntax (`*(scores + 3)` not `scores[base+12]`)
  - Hex arithmetic (0x1000 + 12 = 0x100C, not 0x1012)
  - Dereference vs assignment (`*ptr = 500` not `int* ptr = 500`)

**2. Struct Definition and Usage - COMPLETED**
- Defined `Player` struct with `int health, x, y`
- Created struct instances: `Player myPlayer;`
- Accessed members directly: `myPlayer.health = 100;`
- File: `cpp/structs/structs.cpp`

**3. Pointers to Structs - COMPLETED**
- Created pointer to struct: `Player* ptr = &myPlayer;`
- Used `->` operator: `ptr->health = 100;`
- Understood `->` as syntactic sugar for `(*ptr).member`
- Operator precedence: can't write `*ptr.health` (becomes `*(ptr.health)`)

**4. Member Offsets - COMPLETED**
- Calculated member offsets:
  - `health` at offset `0x00`
  - `x` at offset `0x04`
  - `y` at offset `0x08`
- Each `int` is 4 bytes, so members are 4 bytes apart

**5. Structs as Raw Memory - COMPLETED**
- Cast struct pointer to `int*`: `int* dataPtr = (int*)ptr;`
- Accessed members by offset: `*(dataPtr + 0)`, `*(dataPtr + 1)`, `*(dataPtr + 2)`
- Looped through struct members as an array of ints
- **This is exactly how Cheat Engine and game mods work**

**6. Critical Bug Discovery - POINTER ARITHMETIC SCALING**
- User initially wrote: `std::cout << (ptr + i)` where `ptr` is `Player*`
- This moves by `sizeof(Player)` = 12 bytes, not 4!
- **Correct:** Cast to `int*` first, then do arithmetic
- `Player* ptr + 1` = base + 12 bytes (struct units)
- `int* dataPtr + 1` = base + 4 bytes (int units)
- User fixed the bug and verified 4-byte spacing in output

**7. Memory Address Verification - COMPLETED**
- Printed actual memory addresses of each member
- Verified 4-byte spacing: `0x...1c`, `0x...20`, `0x...24`
- Confirmed pointer arithmetic with `int*` works correctly

### Current Code State

**File:** `cpp/structs/structs.cpp`

```cpp
#include <iostream>

struct Player {
    int health;
    int x;
    int y;
};

int main() {
    Player myPlayer;
    Player* ptr = &myPlayer;

    ptr->health=100;
    ptr->x=50;
    ptr->y=75;

    std::cout << "-- Simple one liners ---" << std::endl;
    std::cout << "Player HP: " << ptr->health << std::endl;
    std::cout << "Player X Pos: " << ptr->x << std::endl;
    std::cout << "Player Y Pos: " << ptr->y << std::endl;

    std::cout << "-- Looping through addresses ---" << std::endl;
    int* addrPtr = (int*)ptr;
    for (int i = 0; i < 3; i++) {
        std::cout << "Offset 0x" << std::hex << (i * 4) << std::dec
                  << ": " << *(addrPtr + i) << std::endl;
    }

    std::cout << "-- Looping through addresses with proof of pointer ---" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "Pointer:" << std::hex << (addrPtr + i) << std::endl;
        std::cout << "Offset 0x" << std::hex << (i * 4) << std::dec
                  << ": " << *(addrPtr + i) << std::endl;
    }

    return 0;
}
```

**Output:**
```
-- Simple one liners ---
Player HP: 100
Player X Pos: 50
Player Y Pos: 75
-- Looping through addresses ---
Offset 0x0: 100
Offset 0x4: 50
Offset 0x8: 75
-- Looping through addresses with proof of pointer ---
Pointer:0x7ffc48229c1c
Offset 0x0: 100
Pointer:0x7ffc48229c20
Offset 0x4: 50
Pointer:0x7ffc48229c24
Offset 0x8: 75
```

### Where We Left Off

**Structs fundamentals PARTIALLY COMPLETE:**
- ✓ Struct definition
- ✓ Member access with `.` operator
- ✓ Pointers to structs with `->` operator
- ✓ Member offset calculation
- ✓ Treating structs as raw memory
- ✓ Pointer arithmetic scaling (Player* vs int*)
- [ ] `offsetof()` macro (NEXT)
- [ ] Struct padding and alignment
- [ ] Nested structs
- [ ] Arrays of structs

**Game modding connection established:** User understands how to find a struct in memory and access members by offset, which is the foundation of game hacking.

### Next Session Plan

1. **Quick review questions** — Test struct concepts:
   - "What's the difference between `.` and `->`?"
   - "Why can't you write `*ptr.health`?"
   - "If `Player* ptr` is at `0x1000`, what address is `ptr + 2`?" (0x1018, not 0x1008!)
   - "How do you access the second member of a struct as an int?" (`*(int*)ptr + 1`)

2. **`offsetof()` macro** — Calculate member offsets at compile time
3. **Struct padding** — Why `sizeof(struct)` might be larger than expected
4. **Arrays of structs** — Managing multiple Player instances

### Knowledge to Test Next Session

**Struct fundamentals:**
- "What operator do you use to access struct members through a pointer?"
- "What's the offset of the third `int` member in a struct?"
- "What's the difference between `Player* ptr + 1` and `(int*)ptr + 1`?"

**Pointer casting:**
- "Why do we cast to `int*` before looping through struct members?"
- "What happens if you use `Player*` arithmetic instead of `int*`?"

**Game modding:**
- "If you find a Player struct at `0x12340000` and health is at offset `0x00`, how do you modify it?"

---

## Previous Session: 2026-01-08

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

**File:** `cpp/pointers/pointers.cpp`

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

### Structs - IN PROGRESS (2026-01-12)
- ✓ Struct definition and instantiation
- ✓ Member access with `.` operator
- ✓ Pointers to structs with `->` operator
- ✓ Member offset calculation (0x00, 0x04, 0x08)
- ✓ Treating structs as raw memory (cast to `int*`)
- ✓ Pointer arithmetic scaling (Player* vs int*)
- ✓ Memory address verification
- [ ] `offsetof()` macro
- [ ] Struct padding and alignment
- [ ] Nested structs
- [ ] Arrays of structs

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
- [x] Structs — custom data structures (IN PROGRESS - started 2026-01-12)
- [x] Pointers to structs and `->` operator
- [x] Memory layout and offset calculation within structs
- [ ] `offsetof()` macro and struct padding (NEXT)
- [ ] Arrays of structs
- [ ] Memory management (heap vs stack)

**Next Phase:** Windows Internals & DLL Development
