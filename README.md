# itu-dsa-2024-midterm
This repository contains solutions for the ITU DSA Summer School midterm.

**Note**: These implementations are not optimized for safety or performance.
They reflect exactly what I wrote during the exam - without using a debugger
or even test-compiling the code. I deliberately avoided risky or
overcomplicated solutions and focused on writing the simplest, most reliable
versions to minimize mistakes under exam pressure.


## Folder Structure
- `.h` files contain function declarations for each question.
- `module_q*.c` files include implementation code for the corresponding
  questions.
- `q*.c` files contain test functions that verify the correctness of the
  implementations in `module_*.c`.
- The actual solutions are in the `module_*.c` files.

## Building
You can build and run test binaries using GNU Make.
- Use make `run_q<question_id>` to build and run the test binary for a question.
- Use make `run_debug_q<question_id>` to build with debug info and run it in a
  debugger.

Examples:
```sh
make run_q1          # Builds and runs q1
make run_debug_q4    # Builds q4 in debug mode and runs it with gdb
```


# Questions
## Q1–2
```c
typedef struct Node {
	char label;
	struct Node *next;
} NODE;
```

### Q1 (15 pts)
```c
void add_to_list(NODE **list_head, char data);
```
- `*node` is nullable. Initialize a `NODE` as the head if needed.

### Q2 (15 pts)
```c
NODE **adj_matrix_to_list(int **adj_matrix, int node_count, char *node_labels);
```
Write a function for converting a graph from adjacency matrix representation to
adjacency list representation using.

#### Example:
```c
node_count = 5;
node_labels = { 'A', 'B', 'C', 'D', 'E' };
adj_matrix = {
    {0, 0, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
}
```
Returns a list of nodes like:
```c
[ NODE * ] -> D
[ NODE * ] -> C -> E
[ NODE * ] -> B -> C -> D
[  NULL  ]
[ NODE * ] -> C
```

## Q3–5
### Q3 (10 pts)
Implement a doubly linked list for pancakes.

### Q4 (10 pts)
```
void flip(...);
```
Implement a `flip` function that flips the first `k` pancakes.

### Q5 (10 pts)
Implement a `sort` function that orders the pancakes in ascending size.

## Q6 (10 pts)
- Implement a recursive string reversal function. Deduce its parameters.
- What is the time complexity of your function?

## Q7 (10 pts)
- Implement a function that finds the length of the longest sublist
  with the same consecutive elements in an array.
- Example: for `{1, 1, 8, 8, 8, 8, 8, 1, 3, 3}`, the function should
  return `5` because there are five consecutive `8`s.

## Q8–9
```c
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} Node;
```

## Q8 (10 pts)
- Write a C function to count the number of nodes in a tree.

## Q9 (10 pts)
- Write a C function to delete all leaf nodes.
- You may return the modified root.
