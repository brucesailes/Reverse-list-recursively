# Reverse List Recursively — C

A recursive array-reversal exercise written in C.

This project was created while working through the Codewars kata **“Reverse list recursively”**, currently ranked **8 kyu**.

## Codewars Challenge

- **Platform:** Codewars
- **Kata:** Reverse list recursively
- **Rank:** 8 kyu
- **Language:** C
- **Topic:** Recursion / Arrays / Fundamentals

## Objective

Write a function that reverses a list using recursion rather than an iterative loop.

Example:

```text
Original:
[1, 2, 3, 4, 5]

Reversed:
[5, 4, 3, 2, 1]
```

## Recursive Approach

The algorithm works by using two indexes:

```text
left
 ↓
[1, 2, 3, 4, 5]
             ↑
            right
```

The values at `left` and `right` are swapped.

```text
[5, 2, 3, 4, 1]
```

Then the indexes move inward:

```text
    left
      ↓
[5, 2, 3, 4, 1]
          ↑
        right
```

The process repeats recursively until the indexes meet or cross.

## Base Case

The recursion stops when:

```c
if (left >= right)
    return;
```

This means there are no more values that need to be swapped.

For an odd-sized array, the indexes eventually meet:

```text
[5, 4, 3, 2, 1]
       ↑
  left/right
```

For an even-sized array, the indexes eventually cross.

## Swapping Values

The swap uses a temporary variable:

```c
int temp = arr[left];

arr[left] = arr[right];

arr[right] = temp;
```

The temporary variable is necessary because assigning:

```c
arr[left] = arr[right];
```

overwrites the original value stored at `arr[left]`.

Saving it first allows that value to later be placed at `arr[right]`.

## Indexes vs Values

One of the most important concepts I learned from this challenge was the difference between an array index and the value stored at that index.

Given:

```c
int arr[] = {10, 20, 30, 40};
```

Then:

```c
int left = 0;
```

means:

```text
left = 0
```

But:

```c
arr[left]
```

means:

```text
arr[0] = 10
```

So:

```c
left
```

represents an **index**, while:

```c
arr[left]
```

represents the **value stored at that index**.

Another useful distinction is:

```c
left         // index
arr[left]    // value at that index
&arr[left]   // memory address of that value
```

## Recursive State

Instead of resetting the indexes during every function call, the indexes are passed into the recursive function:

```c
void reverse_arr(int *arr, int left, int right)
```

After each swap, recursion moves inward:

```c
reverse_arr(arr, left + 1, right - 1);
```

Conceptually:

```text
reverse(arr, 0, 4)

        ↓

swap indexes 0 and 4

        ↓

reverse(arr, 1, 3)

        ↓

swap indexes 1 and 3

        ↓

reverse(arr, 2, 2)

        ↓

base case reached
```

## Pointer Connection

When an array is passed to a function in C:

```c
void reverse_arr(int *arr, int left, int right)
```

`arr` points to the beginning of the array.

Array indexing is closely related to pointer arithmetic:

```c
arr[i]
```

is equivalent to:

```c
*(arr + i)
```

For example:

```c
arr[2]
```

and:

```c
*(arr + 2)
```

both access the value stored at index `2`.

## Concepts Practiced

This exercise helped reinforce:

- Arrays
- Array indexes
- Values vs indexes
- Pointer basics
- Passing arrays to functions
- Temporary variables
- Swapping values
- Recursive functions
- Recursive state
- Base cases
- Pointer arithmetic
- CMake
- Git and GitHub workflow

## Key Takeaway

The biggest lesson from this exercise was understanding the process rather than memorizing the solution.

A recursive array reversal can be reasoned about as:

```text
1. Check whether left and right have met or crossed.
2. Save the left value.
3. Move the right value to the left.
4. Move the saved value to the right.
5. Move left forward.
6. Move right backward.
7. Call the function again.
```

Understanding the distinction between:

```text
index → location
value → data stored at that location
address → where that data lives in memory
```

made the algorithm much easier to understand.

## Project Structure

```text
reverse_arr/
├── main.c
├── CMakeLists.txt
├── README.md
└── .gitignore
```

## Build

Using CMake:

```powershell
cmake -S . -B build
cmake --build build
```

Then run the generated executable from the build directory.

## Why I Saved This Project

This repository serves as a reference for my study of C, algorithms, recursion, and data structures.

The goal is not simply to collect completed programming problems, but to document the reasoning and concepts learned while solving them.
