# Git Command Reference

Quick reference for git commands used in this learning journey. Each command includes an example and brief explanation.

## Repository Basics

### `git init`
```bash
git init
```
**What it does:** Initialises a new git repository in the current directory. Creates a `.git` folder to track changes.

### `git status`
```bash
git status
```
**What it does:** Shows the current state of your working directory. Displays modified files, staged changes, and untracked files.

### `git add`
```bash
git add README.md
git add .
```
**What it does:** Stages files for commit. Use specific filenames to stage individual files, or `.` to stage all changes.

### `git commit`
```bash
git commit -m "Add authentication feature"
```
**What it does:** Saves staged changes as a snapshot in git history. The `-m` flag adds a commit message describing the changes.

### `git log`
```bash
git log
git log --oneline
git log --oneline -10
```
**What it does:** Displays commit history. Use `--oneline` for compact view, `-10` to limit to last 10 commits.

## Branching Workflow

### `git branch`
```bash
git branch
git branch feature/new-feature
```
**What it does:** Lists all branches (no arguments), or creates a new branch (with branch name).

### `git checkout`
```bash
git checkout main
git checkout -b feature/save-system
```
**What it does:** Switches to an existing branch, or creates and switches to a new branch with `-b` flag.

### `git merge`
```bash
git checkout develop
git merge feature/authentication
```
**What it does:** Combines changes from the specified branch into your current branch. Always checkout the target branch first.

**Example workflow:**
```bash
# Merge feature into develop
git checkout develop
git merge feature/new-feature

# Then merge develop into main
git checkout main
git merge develop
```

## Remote Repository (GitHub)

### `git remote add`
```bash
git remote add origin https://github.com/username/repo-name.git
```
**What it does:** Links your local repository to a remote repository on GitHub. Usually done once during initial setup.

### `git push`
```bash
git push origin main
git push -u origin feature/new-feature
```
**What it does:** Uploads your local commits to the remote repository. The `-u` flag sets up tracking for the branch.

### `git pull`
```bash
git pull origin main
```
**What it does:** Downloads changes from the remote repository and merges them into your current branch.

## Handling Divergent Branches

### Configure pull strategy
```bash
git config pull.rebase false
```
**What it does:** Tells git to use merge strategy when pulling (not rebase). Needed when local and remote have different commits.

### The divergent branch scenario
```bash
# You've made local commits
git add .
git commit -m "Local changes"

# Remote also has new commits (e.g., edited on GitHub)
git push origin main  # This fails!

# Solution: pull first to merge remote changes
git pull origin main  # Creates a merge commit
git push origin main  # Now succeeds
```

**Why it happens:** Local and remote repositories have diverged - both have commits the other doesn't have.

## Authentication

### Personal Access Token (PAT)
When git asks for password, use your GitHub Personal Access Token (not your account password).

### Save credentials
```bash
git config --global credential.helper store
```
**What it does:** Stores your credentials in `~/.git-credentials` so you don't need to enter them every time. Credentials are saved in plaintext in your home directory (not in the repository).

## Configuration

### Set identity
```bash
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```
**What it does:** Sets your identity for all git commits. Use `--global` for system-wide settings, or omit for repository-specific settings.

### View configuration
```bash
git config --global user.name
git config --global user.email
git config --list
```
**What it does:** Displays current git configuration settings.

## Professional Workflow Summary

```
feature/name → develop → main
   (work)      (test)  (production)
```

**The process:**
1. Create feature branch from develop: `git checkout develop && git checkout -b feature/name`
2. Make changes and commit: `git add . && git commit -m "message"`
3. Merge to develop for testing: `git checkout develop && git merge feature/name`
4. Test in develop branch
5. Merge to main when stable: `git checkout main && git merge develop`
6. Push to GitHub: `git push origin main`

**Key principle:** Protect main branch by using develop as an integration/testing layer.

## Common Patterns

### Starting a new feature
```bash
git checkout develop
git pull origin develop  # Make sure you're up to date
git checkout -b feature/my-feature
# ... make changes ...
git add .
git commit -m "Implement my feature"
git checkout develop
git merge feature/my-feature
```

### Syncing with remote
```bash
git status  # Check for local changes
git pull origin main  # Get remote changes
git push origin main  # Send local changes
```

### Quick commit and push
```bash
git add .
git commit -m "Brief description of changes"
git push origin main
```

## Tips

- **Commit messages:** Should be clear and describe WHY, not just WHAT changed
- **Branch names:** Use descriptive names like `feature/save-system` or `bugfix/crash-on-exit`
- **Pull before push:** Always pull remote changes before pushing to avoid conflicts
- **Small commits:** Commit frequently with small, logical changes rather than large monolithic commits
- **Check status:** Use `git status` liberally to understand current state

## Solo vs Team Workflows

**Solo (learning):**
- Can work directly on main for small changes
- Can skip develop for trivial updates
- Flexibility to break rules when it makes sense

**Team (professional):**
- Always use feature branches
- Always merge through develop
- Protect main branch (never push broken code)
- Follow workflow strictly

The professional workflow is about habits - practice it now so it's natural when working with others.
