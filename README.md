# CS_3502_Project_1

This is a two-part project for KSU course 3502 section 01. Part A is the [Multi-Threading.cpp] file and part B is the [Producer.cpp] and [Consumer.cpp] files. 


## Part A - Multi-Threading Implementation
This part of the project is a multi-threaded program that generates a random amount of threads to change the value of two shared integers. The threads are stopped from deadlocking through the use of a lock order

## Part B- Inter-Process Communication (IPC)
This part of the project uses named pipes to allow for communication between both of the programs. 

## Setup

### Windows Users:
To run part A of the project, it's required to have C++ to run the program. It's recommended to use an IDE such as CLion to run said program. Part B is not recommended for Windows users as it was developed for a Linux environment.

### Linux Users:
To run both parts of the project, please follow the steps below:
1. Ensure C++ is installed on the machine : sudo apt -get install g++
2. Make sure the machine can read, write, and execute the programs: chmod a+rwx "file-name"
3. Compile the programs: g++ -std=c++11 "file-name" -o "process name"
4. Part A only:
   - Run the program: ./"process name"
5. Part B only:
   - Create the named pipe: mkfifo my_pipe (it must be called my_pipe unless you change the pipe name in the files)
   - Run both programs using the pipe: ./"first process" | ./"second Process" (To run properly, please ensure that Producer.cpp is the first process and Consumer.cpp is the second process)
