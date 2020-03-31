# CPTR 242: Homework Checkpoint Repository

Welcome to the Walla Walla University Sequential and Parallel Data Structures and Algorithms git repository for homework assignments.
Below you will find instructions on setting up that environment and keeping it up-to-date.

## Set-Up

Setting up your repository is a two-step process.
You must first fork your own version of the repository on the WWU Computer Science GitLab server and then set up your local environment.

### Forking the Repository

To set up a fork of this repository, click on the *fork* button on the original repository at <https://gitlab.cs.wallawalla.edu/cptr242/student242>.
Copy the URL of your forked repository by clicking the clipboard icon next to it.
The URL should look something like:

```text
git@gitlab.cs.wallawalla.edu:YourUsername/student242.git
```

### Setting Up Your Local Workspace

Use your favorite git client to clone your repository to your local workspace.
You can use terminal or download a [git client](https://git-scm.com/downloads/guis).
One option that cross platform is [gitkraken](https://www.gitkraken.com/).

Finally, to make sure that you can receive updates easily, by adding an upstream remote.
Use the following remote details:

```text
git@gitlab.cs.wallawalla.edu:cptr242/student242.git
```

If you are using a terminal, type the following command.

```sh
git remote add upstream git@gitlab.cs.wallawalla.edu:cptr242/student242.git
```

### Saving your Homework Assignment

You will need to _commit_ your changes to the repository and _push_ them to gitlab.
Review the cheat sheet for the specifics.

### Getting the next Homework Assignment

You will need to pull down the latest assignment using the following commands:

```sh
git pull --no-edit
git fetch upstream
git checkout master
git merge upstream/master -m "automerging"
```

## Git Cheat Sheet

A basic [cheat sheet](https://www.git-tower.com/blog/git-cheat-sheet/) for command on [git](https://git-scm.com/).
