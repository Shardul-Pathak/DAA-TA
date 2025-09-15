# Q3) Number of Distinct Substrings in a String Using Trie

## Problem Statement
Implement a program that takes a string `S` as input and returns the number of distinct substrings of the given string, including the empty substring. Use a **Trie** data structure to accomplish this.

## Explanation
- A substring `B` of string `A` can be obtained by deleting zero or more characters from the start and end of `A`.  
- Two substrings are distinct if at least one character differs at some position.  
- The Trie can be used to store substrings and count unique paths to determine distinct substrings.

## Example
**Input:**  
```
S = "abab"
```

**Output:**  
```
8
```

**Explanation:**  
All possible distinct substrings of `"abab"` are:  
`"", "a", "b", "ab", "ba", "aba", "bab", "abab"`
