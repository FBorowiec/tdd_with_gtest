# **Git, Github and Pull Requests**

_"Any code of your own that you haven't looked at for six or more months might as well have been written by someone else."_ - Eagleson's law

## **Motivation**

To have a great pull request, we need to have a great list of commits. Therefore, it is important how we define a great commit.

### **Commit’s content**

A commit should only contain what it needs. It is better to commit whenever you get something done regularly. It would help you in case you need to revert some of the commits or cherry-pick any commit to other branches as well.

Don’t wait until everything is done to commit, neither to commit every line of code you write.

### **Small Pull Requests**

Making smaller pull requests is the #1 way to speed up your review time. Because they are so small, it’s easier for the reviewers to understand the context and reason with the logic. It’s easy to make big pull requests. It’s difficult to make small, logical ones that are quick to review, push, and achieve velocity with. But in the meantime, it’s definitely worth time breaking down your issues or pull requests before you commit them in one massive push.

*One Issue — One PR:*

Avoid stacking up commits regarding different issues on a PR. Break it down into two or more PRs. It is always a good practice to create an issue and go parallel with that. Just like classes and modules, pull requests should do only one thing.

## **Tips and tricks for having a clean PR**

One Issue — One PR

Avoid stacking up commits regarding different issues on a PR. Break it down into two or more PRs. It is always a good practice to create an issue and go parallel with that. A useful thing might be unstaging everything that has been commited and re-commit in clean single commits chunks of code that go well together. Then the reviewers might look at the commit and have a clean liner view of the evolution of the branch.

To unstage all modifications on a branch:

```cpp
git reset $(git merge-base origin/master $(git branch --show-current))
```

### **Title**

Make a self-explanatory title describing what the pull request does.

### **Description**

Detail with what was changed, why it was changed, and how it was changed.

### **Perfect pull request size**

[A study of a Cisco Systems programming team](https://smartbear.com/learn/code-review/best-practices-for-peer-code-review/) revealed that a review of 200–400 LOC over 60 to 90 minutes should yield 70–90% defect discovery.

With this number in mind, a good pull request should not have more than 250 lines of code changed

### **How to modify a specified commit**

You can use git rebase. For example, if you want to modify commit `bbc643cd`, run

```bash
git rebase --interactive 'bbc643cd^'
```

Please note the caret `^` at the end of the command, because you need actually to rebase back to the commit before the one you wish to modify.

In the default editor, modify `pick` to `edit` in the line mentioning `bbc643cd`.

Save the file and exit: git will interpret and automatically execute the commands in the file. You will find yourself in the previous situation in which you just had created commit `bbc643cd`.

At this point, `bbc643cd` is your last commit and you can easily amend it: make your changes and then commit them with the command:

```bash
git commit --all --amend --no-edit
```

After that, type:

```bash
git rebase --continue
```

to return back to the previous HEAD commit.

**WARNING**: Note that this will change the `SHA-1` of that commit as well as all children - in other words, this rewrites the history from that point forward. You can break repositories doing this if you push using the command `git push --force`.

### **Other _git_ tips**

To recursively update a ws:

```cpp
git submodule foreach 'git pull --rebase'
```
