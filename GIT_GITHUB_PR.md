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

I personally like to take a break once the work on a branch is done and review everything that has been writOne Issue — One PR

Avoid stacking up commits regarding different issues on a PR. Break it down into two or more PRs. It is always a good practice to create an issue and go parallel with that.ten so far. A useful thing might be unstaging everything that has been commited and re-commit in clean single commits chunks of code that go well together. Then the reviewers might look at the commit and have a clean liner view of the evolution of the branch.

To unstage all modifications on a branch:

```cpp
git reset $(git merge-base master BRANCH)
```

### **Title**

Make a self-explanatory title describing what the pull request does.

### **Description**

Detail with what was changed, why it was changed, and how it was changed.

### **Perfect pull request size**

[A study of a Cisco Systems programming team](https://smartbear.com/learn/code-review/best-practices-for-peer-code-review/) revealed that a review of 200–400 LOC over 60 to 90 minutes should yield 70–90% defect discovery.

With this number in mind, a good pull request should not have more than 250 lines of code changed

### **Other _git_ tips**

To recursively update a ws:

```cpp
git submodule foreach 'git pull --rebase'
```
