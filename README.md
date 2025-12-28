*This project has been created as part of the 42 curriculum by fda-cruz*

## Description

push_swap is a sorting algorithm project that aims to sort a **stack** of integers, in ascending order, using a restricted set of operations and the smallest number of moves.

A **stack** is a data structure that follows the Last-In-First-Out (**LIFO**) principle, meaning that the last element added is the first one to be removed.

Two stacks are available:
 - **a**: Contains a random number of unique negative and/or positive integers;
 - **b**: Initially empty.

Only a limited set of stack operations (swap, push, rotate, and reverse rotate) is allowed
to perform the sorting.

## Operations

To achieve the sorting, we have eleven operations available:

- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one element or none.
 - sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one element or none.
 - ss : sa and sb at the same time.
 - pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
 - pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
 - ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
 - rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
 - rr : ra and rb at the same time.
 - rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
 - rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
 - rrr : rra and rrb at the same time.

## Technical Overview

The program is implemented in the following steps:

1. **Input Parsing**
Validates the input, ensures numbers are within integer range and checks for duplicates.

2. **Stack Initialization**
Stores the input values in stack **a**, while stack **b** starts empty.

3. **Coordinate Compression**
Input values are replaced by their relative ranks to simplify comparisons and chunkings. This will improve the algorithm efficiency.

4. **Sorting Strategy**

- *Small Input Size (3 - 5 Numbers)*
    Dedicated sorting operations to minimize the number of operations.
- *General Case (Turk Sort)*
    A chunk-based algorithm that splits the input into ranges and progressively moves elements between stacks **a** and **b**, using rotation costs to choose the most efficient operations.

## Instructions

### Compilation
To compile the program, simply write "make" in the terminal. The **push_swap** program will be available for usage.

### Execution
To run the program, pass a list of numbers:

./push_swap 2 1 3

The program will output a sequence of operations for the sorting of the list.

### Counting Operations
To count the number of operations:

./push_swap 2 1 3 | wc -l

### Checker
To validate the sorting, a checker can be used:

./push_swap 2 1 3 | ./checker 2 1 3

The checker will display **OK** if the sequence sorts the stack, **KO** otherwise, or **Error** on invalid input.

## Bonus

The bonus part of this project consists of implementing a custom **checker** program.

This program handles input parsing, validation and execution of the operations directly, following the same rules and constraints as defined in the subject.

## Resources

### Project Overview
- [*42 push_swap guide*](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap) — official project description and rules.

### Algorithm Concepts
- [*Turk Sort (Medium)*](https://medium.com/%40ayogun/push-swap-c1f5d2d41e97) — detailed explanation of a working Turk Sort approach for push_swap.

- [*Push_swap Turk Algorithm (GitHub)*](https://github.com/alx-sch/push_swap) — example implementation of the Turk Sort algorithm.

### Chunking / Block-based Sorting
- [*Bucket Sort (Wikipedia)*](https://en.wikipedia.org/wiki/Bucket_sort) — classic sorting algorithm illustrating the concept of dividing a list into buckets/chunks.

- [*Chunk-based push_swap*](https://github.com/kurval/42-push_swap) — repository showing a chunk-based sorting strategy. 

### Normalization / Coordinate Compression
- [*Coordinate Compression*](https://314programs.wordpress.com/2023/04/02/coordinate-compression) — explanation of mapping each value to its rank to simplify processing.

### Use of AI
AI tools (e.g., ChatGPT) were used to brainstorm strategies, clarify algorithm concepts, and help with documentation. All core implementation logic was written by the student.