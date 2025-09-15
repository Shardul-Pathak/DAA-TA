# Q2) Largest Rectangle in Histogram

## Problem Statement
Given an array of integers `heights` representing the histogram's bar heights where the width of each bar is 1, return the area of the largest rectangle in the histogram.

## Explanation
Each bar in the histogram has a height. We need to find the largest rectangular area that can be formed by combining adjacent bars.  
This can be solved efficiently using a stack to keep track of bars and calculate areas.

## Example
**Input:**  
```
N = 6
heights[] = {2, 1, 5, 6, 2, 3}
```

**Output:**  
```
10
```
