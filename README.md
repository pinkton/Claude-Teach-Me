# Claude-Teach-Me

Learning C/C++ to create low-level modifications for games that struggle on modern OSes or have abandoned features. Currently targeting **"This Means Warp"** - specifically its unreliable multiplayer save system.

## Project Goal

Create tools for debugging and modifying legacy games to work better on modern operating systems. This includes DLL injection, application loaders, and game logic modification to add features that don't exist or are poorly implemented.

**Current Target:** [This Means Warp](https://store.steampowered.com/app/1269300/This_Means_Warp/) - A roguelike FTL-style space game with a save system that needs improvement.

## Current Status

**Background:** GIAC GREM certified with experience in reverse engineering (Ghidra, IDA, x64dbg) and CTF challenges. Comfortable reading assembly and analysing binaries, but need to shift from malware analysis to game modding and develop C/C++ coding skills.

**Gap:** The shift from "threat hunting" (malware analysis) to "feature hunting" (game reverse engineering), and moving from reading assembly to writing C/C++ code for building user-facing tools.

**Learning Journey:**
- ✅ **COMPLETED:** Git workflow mastered (branching, merging, pushing to GitHub)
- ✅ **COMPLETED:** C/C++ fundamentals (functions, loops, conditionals, input validation)
- ✅ **COMPLETED:** Arrays (memory layout, iteration, undefined behaviour)
- ✅ **COMPLETED:** Pointers (fundamentals, arithmetic, array relationship, type sizes)
- 🔄 **IN PROGRESS:** Structs (definition, member access, memory layout, offsets)
- 🎯 **GOAL:** Create save system modification for This Means Warp

## Why This Matters

Many games, especially indie or older titles, have features that are abandoned by publishers or poorly implemented. This project is about:
- Learning how games work at a low level
- Creating tools that benefit the gaming community
- Understanding reverse engineering of professional software (not just malware)
- Building practical, user-friendly modifications

## Technology Stack

- **Language:** C/C++ (matches target games, good for low-level work)
- **Tools:** Ghidra, IDA Pro, x64dbg (already familiar)
- **Target:** Windows executables, DLL injection, memory manipulation

## Learning Path

1. **Git Workflow** - Completed
   - Branching strategy (feature → develop → main)
   - GitHub integration and authentication
   - Professional workflow habits

2. **C/C++ Development** - In Progress
   - Syntax and language fundamentals
   - Building executables and DLLs
   - Memory management from developer perspective
   - Creating user-facing tools

3. **Game-Specific Reverse Engineering** - Upcoming
   - Finding game features (not malicious code)
   - Tracing UI elements and game logic
   - Understanding save systems and file formats
   - Instrumentation and logging without crashes

4. **Building the Mod** - Future
   - DLL injection for This Means Warp
   - Hooking save system logic
   - Implementing reliable save/load functionality
   - Creating user-friendly interface

## Repository Structure

```
/Coding/
├── README.md                           # This file
├── CLAUDE.md                           # Instructions for Claude Code sessions
├── PROGRESS.md                         # Session-by-session progress tracker
├── git-notes.md                        # Git command reference
├── .gitignore                          # Ignore compiled outputs
├── git_commands_lessons/               # Git workflow learning exercises
│   └── github_commit_push/
│       ├── hello.py
│       └── goodbye.py
└── cpp/                                # C++ learning exercises
    ├── programming.md                  # C++ learning notes
    ├── hello-world/
    │   └── helloworld.cpp              # First C++ program
    ├── add-two-numbers/
    │   └── add-two-numbers.cpp         # Function with parameters/return
    ├── if-number-loop/
    │   └── if-greater-smaller.cpp      # While loop with input validation
    ├── do-while-loop/
    │   └── do-while-loop.cpp           # Do-while loop example
    ├── for-loop/
    │   └── for-loop.cpp                # For loop counting examples
    ├── arrays/
    │   ├── arrays.cpp                  # Array fundamentals
    │   ├── arrays-loop.cpp             # Additional array iteration
    │   └── buffer-overflow-array.cpp   # Undefined behaviour demonstration
    ├── pointers/
    │   ├── integer-pointers.cpp        # Pointer fundamentals
    │   └── character-pointers.cpp      # Char pointer arithmetic
    └── structs/
        └── structs.cpp                 # Struct fundamentals and memory layout
```

## Git Workflow Reference

See [git-notes.md](git-notes.md) for a complete reference of git commands used in this project.

**Professional workflow:**
```
feature/name → develop → main
   (work)      (test)  (production)
```

## Bash Shortcuts

Custom bash functions added to `~/.bashrc` to streamline common development tasks:

### compile-asm
Compiles C++ source to both executable and Intel-syntax assembly in one command:
```bash
compile-asm filename.cpp
```

This runs:
- `g++ -masm=intel filename.cpp -o filename` (creates executable)
- `g++ -S -masm=intel filename.cpp` (generates assembly file)

**Use case:** Quickly compile and generate assembly for reverse engineering analysis of your own code.

### gitpush
Stages, commits, and pushes changes to main in one command:
```bash
gitpush "your commit message"
```

This runs:
- `git add -A` (stages all changes)
- `git commit -m "message"` (commits with message)
- `git push origin main` (pushes to remote)

**Use case:** Streamlined workflow for quick commits when working solo on main branch.

## Teaching Methodology

This repository uses Claude Code as an interactive teacher. The learning approach:
- **Guide, don't do** - Understanding through doing, not watching
- **Question-driven** - Frequent questions to reinforce concepts
- **Critical thinking** - No pushover teaching, honest feedback required
- **Self-correction** - Encouraged to think through problems and correct mistakes
- **Practical application** - Real projects, not just theory

## About

**Author:** pinkton
**Learning Partner:** Claude Code (AI)

This is a public learning repository. All AI-generated files should be prefixed with `AI-*` to distinguish from user-created work. The goal is to document the journey from reverse engineering analyst to game modding developer.

**For questions or disputes:** Please reach out - I'm learning and documenting the process publicly!

## Next Steps

**C/C++ Development (In Progress):**
- [x] Set up C/C++ development environment
- [x] Build first "Hello World" C++ program
- [x] Learn functions with parameters and return values
- [x] Understand if/else statements and user input
- [x] Learn loops (while, for, do-while)
- [x] Input validation and error handling
- [x] Arrays and memory layout
- [x] Pointers fundamentals (declaration, dereferencing, arithmetic)
- [x] Start structs (definition, member access, offsets)
- [ ] Complete structs (offsetof, padding, arrays of structs)
- [ ] Memory management (heap vs stack)
- [ ] Dynamic memory allocation (new/delete)
- [ ] Build simple file I/O tool
- [ ] Create simple DLL

**Game Modding (Future):**
- [ ] DLL injection techniques
- [ ] Analyse This Means Warp save system
- [ ] Prototype save system hook

---

*This repository is part of a learning journey - expect frequent updates as skills develop!*
