# Longest Compound Word Finder
## Overview
This C++ program aims to identify the longest and second longest compound words from a list of words provided through standard input. It has combination of sorting, dynamic programming, and string manipulation techniques to efficiently detect compound words.

## Approach
The program takes the approach of sorting the words based on length and lexicographical order, and then checks for compound word possibilities by iterating over word substrings. It utilizes a dynamic programming array to keep track of
whether a substring is a compound word. By applying these techniques, the program efficiently finds the longest and second longest compound words within the provided list.

## Implementation
The implementation consists of a series of functions that handle input reading, sorting, compound word identification, and output display. The program uses standard C++ libraries and data structures to manage the words and their
properties.

# Time Complexity
According to me Time complextity of this code is 
- Best Time Complexity: O(n log n)
- Average Time Complexity: O(n log n + nm^2)
- Worst Time Complexity: O(n log n + nm^2)

Code Execution Flow
- Reading and storing the words from standard input.
- Sorting the words based on length and lexicographical order.
- Iterating through the sorted words and checking for compound word possibilities.
- Storing the longest and second longest compound words found.
- Displaying the results in the output.
