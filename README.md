[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/jkn9TuBQ)
# Game of Life Multi-Threaded Implementation
  
This code is a multi-threaded implementation of the Game of Life cellular automaton. It uses the pthreads library in C to divide the work of updating the grid between multiple threads.  
## Prerequisites  
  
This code requires the following to be installed on your system:
```
    gcc compiler
    pthreads library
```
## Compilation

To compile the code, run the following command:
```bash
gcc -o game_of_life game_of_life.c -lpthread
```
## Usage
  
To run the program, execute the compiled binary with the following command:
  
```bash
./game_of_life
```
The program will prompt you to enter the initial state of the grid, as well as the number of generations to simulate. After each generation, the program will print out the updated state of the grid.  
### Input
  
The initial state of the grid is entered as a series of 0s and 1s, separated by spaces. For example, to enter a 4x4 grid with a live cell in the top-left corner, you would enter the following:
  
```
1 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
```
### Output
  
After each generation, the program will print out the updated state of the grid. The grid is printed as a table, with each cell represented by a 0 (dead) or 1 (alive).  
## Implementation Details
### Data Structures
  
The code uses two-dimensional arrays to represent the current and new states of the grid. Each cell is either 0 (dead) or 1 (alive).
### Algorithm
  
The algorithm for updating the grid is as follows:

    For each cell in the grid, count the number of live neighbors.
    Based on the number of live neighbors and the current state of the cell, update the new state of the cell.
    Copy the new state of the grid to the current state of the grid.

To parallelize this algorithm, the grid is divided into equal-sized sections, with each thread responsible for updating a section of the grid. The number of threads is specified by the **NUM_THREADS** constant.
### Threading
  
Each thread is responsible for updating a section of the grid. The **grid_work** function takes a **thread_data_t struct** as an argument, which specifies the section of the grid to update. The struct also contains pointers to the current and new states of the grid.
  
To create the threads, the main function loops over the **NUM_THREADS** and creates a **thread_data_t struct** for each thread. It then calls pthread_create to create the thread, passing in a pointer to the struct as an argument.

After creating the threads, the main function loops over them and calls **pthread_join** to wait for each thread to finish. Finally, it copies the new state of the grid to the current state of the grid and prints out the updated state.
