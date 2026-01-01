# Claude Context File

## Project: AI-User-Training

## IMPORTANT: Language Preference
**Please use British English in all responses:**
- British spelling (colour, organisation, realise, whilst, etc.)
- British terminology and conventions
- Metric units where applicable

## Public Repository Notice
This repository is **publicly accessible** on GitHub at: https://github.com/pinkton/Claude-Teach-Me-Github
- Do not include sensitive information
- User is learning and documenting the process publicly
- AI-generated files are prefixed with `AI-*` to distinguish from user-created work

## Project Purpose
This is a **learning repository** for understanding git workflow and programming fundamentals.

**Learning Path (in order):**
1. **Git Workflow** ← Currently here (completed)
2. **Programming Fundamentals** ← Next step
3. **Game Modding Tools** ← Long-term goal (many steps away)

The ultimate goal is creating tools for legacy game modifications, but mastering fundamentals comes first.

## Teaching Methodology for Future Claude Sessions
**IMPORTANT - How to teach the user:**
1. **Guide, don't do** - Tell the user what commands to run, don't execute for them (unless explicitly requested)
2. **Ask questions constantly** - Before and after each step to reinforce learning
3. **Test knowledge periodically** - Every 3-4 commands, ask: "What will this command do?" or "Why are we doing this?"
4. **Encourage independent thinking** - Ask which approach they'd choose before suggesting one
5. **Build on previous lessons** - Reference earlier concepts to reinforce connections
6. **Let them make mistakes** - If they suggest the wrong command, ask guiding questions rather than immediately correcting

## Current Progress

### Git Workflow - COMPLETED ✓
- [x] Repository setup and configuration
- [x] Branch workflow (main → develop → feature)
- [x] Creating and switching branches
- [x] Committing changes with meaningful messages
- [x] Merging feature branches through develop to main
- [x] Pushing to GitHub with authentication
- [x] Handling divergent branches with git pull
- [x] Understanding when to use proper workflow vs direct commits

### Programming Fundamentals - NOT STARTED
- [ ] Variables and data types
- [ ] Control flow (if/else, loops)
- [ ] Functions and modules
- [ ] File operations
- [ ] Error handling
- [ ] Object-oriented basics

### Game Modding Tools - FUTURE GOAL
- [ ] Understanding game file formats
- [ ] Binary file manipulation
- [ ] Creating user-friendly tools
- (Many prerequisite steps needed first)

## Branch Strategy
- **main**: Production-ready, stable code only (never push broken code here)
- **develop**: Integration branch for testing features before production
- **feature/[name]**: Individual feature branches for isolated development

## Git Workflow Mastered
The user has successfully completed the full professional workflow:
```
feature/name → develop → main
   (work)      (test)  (production)
```

Key commands learned:
- `git checkout -b feature/name` - Create feature branch
- `git add`, `git commit -m "message"` - Save changes
- `git merge feature/name` - Integrate features
- `git push -u origin branch` - Upload to GitHub
- `git pull origin branch` - Download and merge remote changes

## Common Scenarios Encountered
**Divergent Branches:** When local and remote repositories have different commits
- Caused by: Editing files on GitHub whilst also making local changes
- Solution: `git pull origin main` to merge remote changes, then push
- Lesson: Always pull before pushing to avoid conflicts

## Session Start Checklist for Future Claude
When resuming this project:
1. Read this entire file to understand context
2. Check current branch: `git branch`
3. Check for uncommitted changes: `git status`
4. Ask the user what they want to work on today
5. **Test previous knowledge** - Ask 1-2 questions about the last session's concepts before starting new material
6. Follow the teaching methodology above

## Knowledge Testing Examples
Periodically ask questions like:
- "What branch should we create this feature from?"
- "What will `git status` show us right now?"
- "Why do we merge to develop before main?"
- "What's the difference between `git add` and `git commit`?"
