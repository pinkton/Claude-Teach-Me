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

## Project Purpose
This is a **learning repository** for developing C/C++ skills to create game modification tools, specifically targeting legacy games that struggle on modern operating systems or have abandoned features.

**Current Target:** [This Means Warp](https://store.steampowered.com/app/1269300/This_Means_Warp/) - Roguelike space game with an unreliable multiplayer save system.

**Ultimate Goal:** Create DLL injection tools and game logic modifications to implement a reliable save system.

## User Background - IMPORTANT

**Existing Skills:**
- ✅ **GIAC GREM certified** - Professional reverse engineering of malware
- ✅ **Reverse engineering tools:** Ghidra, IDA Pro, x64dbg (experienced)
- ✅ **CTF experience** - Capture The Flag challenges (4 years ago, but foundational knowledge intact)
- ✅ **Binary analysis:** Comfortable reading assembly, understanding PE format, tracing execution
- ✅ **Scripting:** Python and PowerShell (day job usage)
- ✅ **Conceptual understanding:** Variables, loops, functions, control flow (high-level concepts)

**The Gap - What User NEEDS to Learn:**
- ❌ **C/C++ syntax and development** - Can read assembly, but can't write C/C++ code
- ❌ **Building executables and DLLs** - Need to understand toolchains, compilers, linkers
- ❌ **Game reverse engineering methodology** - Different from malware analysis:
  - Malware RE: "Look for malicious patterns" (threat hunting)
  - Game RE: "Look for functional patterns" (feature hunting)
  - Need to find UI code, save systems, game logic (not IOCs or suspicious APIs)
- ❌ **Creating user-facing tools** - Not just analysis, but building tools others can use
- ❌ **Memory management from developer perspective** - Allocating and manipulating, not just analyzing

**Critical Insight:**
User can **analyze** code but needs to learn to **write** code. Shift from "reverse engineering analyst" to "game modding developer."

## Learning Path (Updated)

**Learning Path (in order):**
1. ✅ **Git Workflow** - COMPLETED
2. 🔄 **C/C++ Development** - IN PROGRESS (current focus)
3. ⏳ **Game-Specific Reverse Engineering** - UPCOMING
4. ⏳ **Building the This Means Warp Mod** - FUTURE

### 1. Git Workflow - COMPLETED ✓
- [x] Repository setup and configuration
- [x] Branch workflow (feature → develop → main)
- [x] Creating and switching branches
- [x] Committing changes with meaningful messages
- [x] Merging feature branches through develop to main
- [x] Pushing to GitHub with authentication (Personal Access Token)
- [x] Handling divergent branches with git pull
- [x] Understanding when to use proper workflow vs direct commits
- [x] Multi-machine authentication setup

### 2. C/C++ Development - IN PROGRESS 🔄
**Goal:** Learn to write C/C++ code, not just read assembly.

- [ ] Development environment setup (compiler, IDE, toolchain)
- [ ] C/C++ syntax fundamentals (the user knows concepts, needs language specifics)
- [ ] Building and compiling executables
- [ ] Memory management (pointers, heap/stack from developer view)
- [ ] Creating DLLs and understanding linking
- [ ] Build systems (Makefiles, CMake, or similar)
- [ ] Debugging C/C++ code (not just binaries)

### 3. Game-Specific Reverse Engineering - UPCOMING ⏳
**Goal:** Shift from malware analysis to game modding methodology.

- [ ] Finding game features (not malicious code)
  - Tracing user input → code path
  - Finding strings → UI code
  - Monitoring file I/O → save systems
- [ ] Understanding save file formats
  - Is it encrypted/seeded?
  - Can it be copied?
  - When can saves occur?
- [ ] Instrumentation without breaking the game
  - Hooking and logging safely
  - Understanding game state
- [ ] Finding UI elements and menu code

### 4. Building the This Means Warp Mod - FUTURE ⏳

**Specific Questions to Answer:**
1. How does the save system work?
2. Can saves be copied/moved?
3. Is it seeded or encrypted?
4. When can saves occur? (checkpoints only, or can we add quicksave?)
5. How to find menu code for adding a "Save" button?
6. How to hook and log game behavior?

**Implementation Steps:**
- [ ] Analyze This Means Warp save system
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

## Session Start Checklist for Future Claude

When resuming this project:
1. Read this entire file to understand context
2. **Remember:** User is GREM certified with RE experience - don't explain basic RE concepts
3. **Focus:** User needs to learn C/C++ development, not reverse engineering
4. Check current branch: `git branch`
5. Check for uncommitted changes: `git status`
6. Ask the user what they want to work on today
7. **Test previous knowledge** - Ask 1-2 questions about the last session's concepts before starting new material
8. Follow the teaching methodology above

## Knowledge Testing Examples

**Git questions:**
- "What branch should we create this feature from?"
- "What will `git status` show us right now?"
- "Why do we merge to develop before main?"
- "What's the difference between `git add` and `git commit`?"

**C/C++ questions (upcoming):**
- "What's the difference between the stack and the heap?"
- "Why do we need to free memory we allocate?"
- "What's a pointer and why are they important?"
- "What's the difference between compiling and linking?"

**Game RE questions (future):**
- "How would you find the save game code if you don't know where it is?"
- "What's the difference between analyzing malware and analyzing game logic?"
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

## Repository Structure

```
/Coding/
├── README.md                    # Public-facing project description
├── CLAUDE.md                    # This file - Claude Code instructions
├── git-notes.md                 # Git command reference
└── practice/
    └── github_commit_push/      # Git workflow learning exercises
        ├── hello.py
        └── goodbye.py
```

## Important Notes

- **Language choice:** C/C++ (matches target games, user preference over Rust for now)
- **Target game:** This Means Warp (save system modification)
- **User strength:** Reverse engineering, binary analysis, understanding code
- **User gap:** Writing code, building tools, C/C++ development
- **Teaching style:** Critical, honest, no hand-holding - user explicitly requested this
- **British English:** Always use British spelling and conventions

## Next Session Goals

When resuming:
1. Set up C/C++ development environment
2. Write first "Hello World" in C++
3. Understand compilation and linking
4. Build towards creating a simple DLL
5. Eventually: analyze This Means Warp and begin modding

---

**Remember:** User is transitioning from "reading assembly" to "writing C++". Focus on development skills, not analysis skills.
