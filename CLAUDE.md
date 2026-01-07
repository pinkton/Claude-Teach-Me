# Claude Context File

## Project: Game Modding Tools Development

## IMPORTANT: Language Preference
**Please use British English in all responses:**
- British spelling (colour, organisation, realise, whilst, etc.)
- British terminology and conventions
- Metric units where applicable

## Public Repository Notice
This repository is **publicly accessible** on GitHub at: https://github.com/pinkton/Claude-Teach-Me
- Do not include sensitive information
- User is learning and documenting the process publicly
- AI-generated files are prefixed with `AI-*` to distinguish from user-created work
- Work created then updated is a grey area, but user understands that they create their own files first, then get Claude to provide context and provide rewording based on pre-existing user created content, opposed to halucinating from nothingness.

## Project Purpose
This is a **learning repository** for developing C/C++ skills to create game modification tools, specifically targeting legacy games that struggle on modern operating systems or have abandoned features.
Every training session is to be it's own folder to some degree, allowing public visibility into what has/hasn't been achieved, and they can see an element of notes/examples for revision at later dates. 

**Current Target:** [This Means Warp](https://store.steampowered.com/app/1269300/This_Means_Warp/) - Roguelike space game with an unreliable multiplayer save system.

**Ultimate Goal:** Create DLL injection tools and game logic modifications to implement a reliable save system.

## User Background - IMPORTANT

**Existing Skills:**
- **GIAC GREM certified** - Professional reverse engineering of malware
- **Reverse engineering tools:** Ghidra, IDA Pro, x64dbg (experienced)
- **CTF experience** - Capture The Flag challenges (Multiple years of simple challenges, but foundational knowledge intact)
- **Binary analysis:** Comfortable reading assembly, understanding PE format, tracing execution
- **Scripting:** Python and PowerShell (day job usage)
- **Conceptual understanding:** Variables, loops, functions, control flow (high-level concepts)

**The Gap - What User NEEDS to Learn:**
- **C/C++ syntax and development** - Can read assembly, but can't write C/C++ code
- **Building executables and DLLs** - Need to understand toolchains, compilers, linkers
- **Game reverse engineering methodology** - Different from malware analysis:
  - Malware RE: "Look for malicious patterns" (threat hunting)
  - Game RE: "Look for functional patterns" (feature hunting)
  - Need to find UI code, save systems, game logic (not IOCs or suspicious APIs)
- **Creating user-facing tools** - Not just analysis, but building tools others can use
- **Memory management from developer perspective** - Allocating and manipulating, not just analysing

**Critical Insight:**
User can **analyse** code but needs to learn to **write** code. Shift from "reverse engineering analyst" to "game modding developer."

## Learning Path (Updated)

**Learning Path (in order):**
1. **Git Workflow** - COMPLETED
2. **C/C++ Development** - IN PROGRESS (current focus)
3. **Windows Internals & DLL Development** - UPCOMING (transferable to any Windows application)
4. **Game RE Fundamentals** - UPCOMING (practice on UT99 as training target)
5. **Building the This Means Warp Mod** - FUTURE (ultimate goal, subject to change)

### 1. Git Workflow - COMPLETED
- [x] Repository setup and configuration
- [x] Branch workflow (feature → develop → main)
- [x] Creating and switching branches
- [x] Committing changes with meaningful messages
- [x] Merging feature branches through develop to main
- [x] Pushing to GitHub with authentication (Personal Access Token)
- [x] Handling divergent branches with git pull
- [x] Understanding when to use proper workflow vs direct commits
- [x] Multi-machine authentication setup

### 2. C/C++ Development - IN PROGRESS
**Goal:** Learn to write C/C++ code, not just read assembly.

- [x] Development environment setup (gcc, g++, make already installed in WSL2)
- [x] First Hello World program (`practice/cpp/hello-world/helloworld.cpp`)
- [x] Compilation process understanding (preprocessing, compiling, assembly, linking)
- [x] Compiling to Intel-syntax assembly (`g++ -S -masm=intel`) for analysis
- [x] Functions with parameters and return values (`practice/cpp/add-two-numbers/add-two-numbers.cpp`)
- [x] Understanding x86-64 calling conventions (EDI, ESI for params; EAX for return)
- [x] User input with `std::cin >>`
- [x] If/else statements and conditional logic (`practice/cpp/if-number-loop/if-greater-smaller.cpp`)
- [x] Key bug discovered: `=` (assignment) vs `==` (comparison) - caught and fixed
- [x] Loops - all three types mastered:
  - [x] `while` loops - condition checked first (`practice/cpp/if-number-loop/if-greater-smaller.cpp`)
  - [x] `do-while` loops - condition checked after, guaranteed one execution (`practice/cpp/do-while-loop/do-while-loop.cpp`)
  - [x] `for` loops - best for counting/iteration with init, condition, update (`practice/cpp/for-loop/for-loop.cpp`)
- [x] Loop control - `break` to exit, `continue` to skip to next iteration
- [x] Input validation - `std::cin.fail()` to detect errors, `std::cin.clear()` to reset, `std::cin.ignore()` to flush buffer
- [x] String concatenation in output - chaining `<<` operators instead of `+` for mixed types
- [x] Arrays - fundamentals completed (`practice/cpp/arrays/arrays.cpp`):
  - [x] Declaration and initialisation (`int numbers[5] = {1, 2, 4, 8, 16}`)
  - [x] Zero-based indexing - valid indices 0 to N-1
  - [x] Memory layout - contiguous blocks, 4-byte spacing for int arrays
  - [x] Iteration with for loops
  - [x] Out-of-bounds access and undefined behaviour - intentionally triggered to see garbage stack values
  - [ ] sizeof operator for calculating array length (NEXT - resume next session)
- [ ] Pointers and pointer arithmetic - understanding memory addresses, array/pointer relationship
- [ ] Memory management (pointers, heap/stack from developer view)
- [ ] Creating DLLs and understanding linking
- [ ] Build systems (Makefiles, CMake, or similar)
- [ ] Debugging C/C++ code (not just binaries)

**Key Learning Discovery:**
User realised they can write C++ code, compile to assembly, and reverse engineer their own code to learn patterns. This creates a powerful learning loop: **write C++ → compile to assembly → analyse with RE skills → understand patterns → recognise in production software**.

### 3. Windows Internals & DLL Development - UPCOMING
**Goal:** Learn transferable skills for modifying any Windows application.

- [ ] Pointers and memory management (heap vs stack, allocation)
- [ ] Structs and custom data structures
- [ ] File I/O (reading/writing files programmatically)
- [ ] Building DLLs (shared libraries)
- [ ] Understanding process memory layout
- [ ] DLL injection techniques (CreateRemoteThread, AppInit_DLLs, etc.)
- [ ] Windows API basics (kernel32, user32 functions)
- [ ] PE file format understanding

### 4. Game RE Fundamentals - UPCOMING
**Goal:** Learn universal game modding techniques (using UT99 as practice target).

**Practice Target:** Unreal Tournament 99
- Chosen because: Large modding community, well-documented, simple by modern standards, no anti-tamper
- Purpose: Safe environment to learn techniques that transfer to any game
- Not the end goal, just a training dummy

**Transferable Skills to Learn:**
- [ ] Finding game state in memory (Cheat Engine techniques)
- [ ] Identifying function signatures and patterns
- [ ] Tracing execution flows without source code
- [ ] Understanding game loops and update cycles
- [ ] Function hooking (detours, trampolines)
- [ ] Memory patching techniques
- [ ] Finding strings → UI code → game logic
- [ ] Save file format analysis
- [ ] Instrumentation without crashing the application

### 5. Building the This Means Warp Mod - FUTURE

**Note:** This is the current ultimate goal, but may change as learning progresses and interests evolve. Skills learned are transferable to any game modding project.

**Specific Questions to Answer:**
1. How does the save system work?
2. Can saves be copied/moved?
3. Is it seeded or encrypted?
4. When can saves occur? (checkpoints only, or can we add quicksave?)
5. How to find menu code for adding a "Save" button?
6. How to hook and log game behavior?

**Implementation Steps:**
- [ ] Analyse This Means Warp save system
- [ ] Create DLL injector/loader
- [ ] Hook save system logic
- [ ] Implement reliable save/load
- [ ] Create user-friendly interface
- [ ] Test and refine

## Teaching Methodology for Future Claude Sessions

**IMPORTANT - How to teach the user:**

1. **Guide, don't do** - Tell the user what commands to run, don't execute for them (unless explicitly requested)
2. **Ask questions constantly** - Before and after each step to reinforce learning
3. **Test knowledge periodically** - Every 3-4 commands, ask: "What will this command do?" or "Why are we doing this?"
4. **Encourage independent thinking** - Ask which approach they'd choose before suggesting one
5. **Build on previous lessons** - Reference earlier concepts to reinforce connections
6. **Let them make mistakes** - If they suggest the wrong command, ask guiding questions rather than immediately correcting
7. **No pushover teaching** - User explicitly requested critical, honest feedback. Call out nonsense, redundant wording, or incorrect assumptions.
8. **Leverage existing knowledge** - User has GREM certification and RE experience. Don't explain basic RE concepts they already know.
9. **Focus on the gap** - Writing code, not analyzing it. Development, not just reverse engineering.
10. **Don't over-analyze assembly** - User is comfortable with assembly and doesn't need deep dives into every instruction. Use assembly as a learning tool when relevant, but prioritize C++ syntax learning.
11. **Practical application** - User prefers learning fundamentals before building tools ("no point making a tool if I don't know how to actually code in cpp")
12. **Minimal emojis** - User explicitly requested minimal emoji usage in responses and documentation.

## Branch Strategy

- **main**: Production-ready, stable code only
  - For solo learning: Can commit documentation directly when appropriate
  - For code changes: Use feature → develop → main workflow
- **develop**: Integration branch for testing features before production
- **feature/[name]**: Individual feature branches for isolated development

**Flexibility:** User understands when to use full workflow (code changes, teams) vs when to be pragmatic (documentation, solo work). Trust their judgment.

## Git Workflow Reference

See `git-notes.md` for complete command reference.

**Professional workflow:**
```
feature/name → develop → main
   (work)      (test)  (production)
```

Key commands mastered:
- `git checkout -b feature/name` - Create feature branch
- `git add`, `git commit -m "message"` - Save changes
- `git merge feature/name` - Integrate features
- `git push -u origin branch` - Upload to GitHub
- `git pull origin branch` - Download and merge remote changes
- `git config credential.helper store` - Save authentication

## User's Bash Shortcuts

The user has custom bash functions configured in `~/.bashrc`:

**compile-asm filename.cpp**
- Compiles C++ to both executable and Intel-syntax assembly
- User created this to quickly analyse their own compiled code
- When suggesting compilation, you can reference this shortcut

**gitpush "commit message"**
- Combines `git add -A`, `git commit -m`, and `git push origin main`
- Streamlined workflow for solo work on main branch
- User may use this instead of individual git commands

## Session Start Checklist for Future Claude

When resuming this project:
1. Read this entire file to understand context and methodology
2. **Read PROGRESS.md** - Check current session status, where we left off, and what's next
3. **Remember:** User is GREM certified with RE experience - don't explain basic RE concepts
4. **Focus:** User needs to learn C/C++ development, not reverse engineering
5. Check current branch: `git branch`
6. Check for uncommitted changes: `git status`
7. **Test previous knowledge** - Ask 1-2 questions about the last session's concepts before starting new material (PROGRESS.md has suggested questions)
8. Follow the teaching methodology above

## Knowledge Testing Examples

**Git questions:**
- "What branch should we create this feature from?"
- "What will `git status` show us right now?"
- "Why do we merge to develop before main?"
- "What's the difference between `git add` and `git commit`?"

**C/C++ questions:**
- "What's the difference between `=` and `==`?" (assignment vs comparison)
- "What's the difference between `<<` and `>>`?" (output vs input direction)
- "Which registers are used for the first two integer parameters in x86-64?" (EDI, ESI)
- "Where does a function's return value go?" (EAX/RAX)
- "Why do we need calling conventions?" (interoperability between compiled code)
- "What happens if `std::cin >>` fails when user enters invalid input?" (fail state, variable uninitialized)
- "Should compiled binaries be committed to git?" (no - only source code)
- "What's the difference between `while` and `do-while`?" (when condition is checked)
- "When would you use a `for` loop vs a `while` loop?" (counting/iteration vs conditional repetition)
- "What does `i++` do?" (increment i by 1, same as i = i + 1)
- "What's the difference between `i+=2` and `i=+2`?" (add 2 to i vs assign positive 2 to i)
- "How do you fix an infinite loop caused by `std::cin` failure?" (clear(), ignore(), then try again)
- "What's the difference between `break` and `continue`?" (exit loop vs skip to next iteration)
- "What's the difference between compiling and linking?" (upcoming)
- "What's the difference between the stack and the heap?" (upcoming)

**Array questions (upcoming):**
- "Why are arrays zero-indexed?"
- "What happens if you access `array[10]` when the array size is 5?"
- "How do you iterate over an array with a for loop?"
- "What's the relationship between arrays and pointers?"
- "How do you get the size of an array?"

**Game RE questions (future):**
- "How would you find the save game code if you don't know where it is?"
- "What's the difference between analysing malware and analysing game logic?"
- "How can you hook a function without crashing the game?"

## Common Scenarios Encountered

**Divergent Branches:** When local and remote repositories have different commits
- Caused by: Editing files on GitHub whilst also making local changes
- Solution: `git pull origin main` to merge remote changes, then push
- Lesson: Always pull before pushing to avoid conflicts

**Multi-machine setup:**
- Need to create new Personal Access Token for each machine
- Configure `credential.helper store` to save authentication
- Set up `user.name` and `user.email` globally

**Compiled outputs in git:**
- Common beginner mistake: committing compiled binaries, assembly files, and object files
- Only source code (`.cpp`, `.h`) should be in version control
- Compiled outputs (executables, `.o`, `.s` files) should be in `.gitignore`
- Build artifacts can always be regenerated from source
- Use `git rm` to remove mistakenly committed binaries, then add patterns to `.gitignore`

## Repository Structure

```
/Coding/
├── README.md                           # Public-facing project description
├── CLAUDE.md                           # This file - Claude Code instructions
├── git-notes.md                        # Git command reference
├── .gitignore                          # Ignore compiled outputs
└── practice/
    ├── github_commit_push/             # Git workflow learning exercises
    │   ├── hello.py
    │   └── goodbye.py
    └── cpp/                            # C++ learning exercises
        ├── programming.md              # C++ learning notes
        ├── hello-world/
        │   ├── helloworld.cpp          # First C++ program
        │   └── readme.md               # Notes on Hello World
        ├── add-two-numbers/
        │   ├── add-two-numbers.cpp     # Function with parameters/return
        │   └── readme.md               # Notes on functions
        ├── if-number-loop/
        │   ├── if-greater-smaller.cpp  # While loop with input validation
        │   └── readme.md               # Notes on while loops
        ├── do-while-loop/
        │   ├── do-while-loop.cpp       # Do-while loop example
        │   └── readme.md               # Notes on do-while loops
        ├── for-loop/
        │   ├── for-loop.cpp            # For loop counting examples
        │   └── readme.md               # Notes on for loops
        └── arrays/
            ├── arrays.cpp              # Array fundamentals and undefined behaviour
            └── readme.md               # Notes on arrays
```

## Important Notes

- **Language choice:** C/C++ (matches target games, user preference over Rust for now)
- **Target game:** This Means Warp (save system modification)
- **User strength:** Reverse engineering, binary analysis, understanding code
- **User gap:** Writing code, building tools, C/C++ development
- **Teaching style:** Critical, honest, no hand-holding - user explicitly requested this
- **British English:** Always use British spelling and conventions

## Next Session Goals

**Immediate next steps:**
1. **Arrays - sizeof operator** - Resume from where we left off
   - **Question to answer:** What will `sizeof(numbers)`, `sizeof(int)`, and `sizeof(numbers)/sizeof(int)` return?
   - Understanding why `sizeof(array)` gives total bytes, not element count
   - Calculating array length programmatically: `sizeof(numbers) / sizeof(numbers[0])`
   - Using calculated length in for loops instead of hardcoding `i < 5`
   - Multi-dimensional arrays (`int grid[3][3]`) if time allows
2. **Pointers** - Understanding memory addresses and pointer arithmetic (natural follow-up to arrays)
3. **Different data types** - char, float, string, bool (can introduce alongside arrays/pointers)
4. **More practice** - Combine arrays, loops, and different data types

**Current progress:**
- Completed all three loop types (while, do-while, for)
- Completed input validation for handling non-numeric input
- **Completed array fundamentals** - declaration, zero-indexing, memory layout, iteration, undefined behaviour
- Examined contiguous memory layout in assembly (4-byte spacing for int arrays)
- Intentionally triggered out-of-bounds access to observe undefined behaviour
- One working array program demonstrating basics
- **Next:** sizeof operator to avoid hardcoding array length

**Why sizeof matters:**
- Makes code more maintainable (change array size once, loops update automatically)
- Essential for understanding how C++ views arrays vs pointers
- Leads naturally into pointer arithmetic and array/pointer relationship

**Upcoming tasks (transferable skills focus):**
1. Arrays and pointers - understand memory layout
2. Structs and custom data structures
3. Build simple file I/O tool (reads/writes files - applicable to save file analysis)
4. Create first DLL (transferable to any Windows application)
5. Practice on UT99 (safe environment to apply skills)
6. Eventually: Apply everything to This Means Warp (or whatever game interests you by then)

---

**Remember:** User is transitioning from "reading assembly" to "writing C++". Focus on development skills, not analysis skills.
