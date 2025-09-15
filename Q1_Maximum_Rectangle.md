# Q1) Maximum Rectangle Area with all 1's

## Problem Statement
Given a row × col binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

## Explanation
The problem is to identify the largest possible rectangle that consists entirely of `1`s in the given binary matrix.  
This is an extension of the largest rectangle in a histogram problem — for each row, the matrix can be treated as the base of a histogram where each column accumulates height when consecutive `1`s are present.

## Example
**Input:**  
```
matrix = [
  [1,0,1,0,0],
  [1,0,1,1,1],
  [1,1,1,1,1],
  [1,0,0,1,0]
]
```

**Output:**  
```
6
```
