# Pipex

## Project Description

Pipex is an interesting project which simulates the execution of Unix terminal commands located on the PATH variable with the help of C, it allows the user to use as many commands as desired and the here_doc functionality to not only use a file as input but also the standard input.

1. [Project Description](#Description)
2. [Install and run the project](#Install-and-usage)
3. [Code functionality summary](#How-it-works)

## Install and usage

* Clone repository
```
git clone https://github.com/marcosto29/pipex.git
```
* To compile program, run the following command:
```
make
```
* To execute, use the following command:
```
./pipex (File1 command1 cmd2 file1)
```

## How it works

The main goal of the program is to find and execute Unix commands submitted by the user. The specific approach developed allows the user to use two commands splitted by one pipe.

To achieve the desire program it uses the execve function, this can result on different problems since as written on the documentation, the process which calls execve will die to replace it with the new one. As mentioned this can result on data loss problems.

Because of this, the main process relies on different features given by the fork and pipe functions. With the correct use of these functions, the main process can behave like a tree, creating branches to execute different commands and taking the output of these executions by reading a communication pipe.

<p align="center">
  <img src = "https://github.com/marcosto29/pipex/blob/main/Images/Pipex%20flux.png" "Pipex flux">
</p>

### Pipe and Fork

As explained above, the main process uses the fork function to fork and create a sub-process with the exact state and information of the parent: variables, useful data, etc. This new child calls the execve function, dying without the risk of killing the parent.

Now, with one main process and one sub-process, the risk of killing the parent is solved. However, without proper communication, creating and running a child that will eventually die is useless. To address this issue, the parent creates a communication pipe before the fork. This pipe allows for simple communication with input and output data. Once the pipe is created and the fork is executed, the child closes the read end, and the parent closes the write end. This way, one of them can only write and one read, achieving the desired state: the child can share information with the parent.

<p align="center">
  <img width = "300" src = "https://github.com/marcosto29/pipex/blob/main/Images/Fork_and_pipe.png" "Fork and pipe">
</p>

### execve

With this hierarchy established, the child begins executing the code. It now has the command the user wants to execute and the initial or previous input for the command. According to the execve documentation, the arguments required to successfully call the function are: the path to the new program, the arguments, and the environment.

Normally, when calling a command in the terminal, the user doesn't type the full path, but simply calls the command name, and the terminal searches for it in the PATH variable. This program works exactly the same.

Once the child program begins executing, the first thing it does, like its parent, is create a pipeline and a branch to create another child program. This new child program is responsible of searching the command given in the PATH variable. To do this, it calls the which command.

### dup2

A final important feature of this program is the way it redirects standard input and output so that the result of a process's execution is not lost. The previously created pipelines are very important. Before calling the execve function, the dup2 function redirects the standard input and/or output to the pipelines. This way, the result of the execution is sent to the pipelines, making them accessible to the respective parents, who can then read them.

With all these features explained, now that the child program has the path to the command, it redirects the standard inputs again to the respective pipelines and calls execve, thus ending the process flow. The parent waits until the child program dies and continues the loop.

The parent continues the loop by closing the previous output pipe (since no one is going to write there anymore) and the previous input, and creating a new complete pipe, to continue the loop, the input will be the previous input pipe and the output pipe will be the new pipe.

| Initial            | Redirected  |
:-------------------------:|:-------------------------:
![](https://github.com/marcosto29/pipex/blob/main/Images/Original_pipe_input.png "original pipe input") | ![](https://github.com/marcosto29/pipex/blob/main/Images/New_pipe_input.png "Fork and pipe")
