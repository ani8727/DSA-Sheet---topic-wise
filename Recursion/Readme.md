# 🌀 Recursion Problems Series  

A structured roadmap to master **Recursion concepts** for interviews and DSA practice.  
Includes categorized problems (Easy, Medium, Hard) with explanations, techniques, flow examples, and revision notes.

---

## *Easy Problems*  

1. **Understanding Recursion**  
   - **Description:** Learn the basic idea of recursion — when a function calls itself until a base condition is met.  
   - **Technique:** Identify the **base case**, **recursive case**, and **input change** in each problem.  

2. **Reverse Stack with Recursion**  
   - **Description:** Reverse a stack using only recursion (no loops).  
   - **Technique:**  
     - Pop all elements recursively.  
     - Insert popped element at the bottom recursively. 

3. **Tower of Hanoi (3 Rods)**  
   - **Description:** Move `n` disks from source rod to destination rod using helper rod.  
   - **Technique:**  
     - Move (n−1) disks → helper  
     - Move nth disk → destination  
     - Move (n−1) disks → destination 

4. **Factorial of a Number using Tail Recursion**  
   - **Description:** Calculate factorial of a number using tail recursion for optimization.  
   - **Technique:**  
     - `fact(n, acc) = fact(n-1, n*acc)`  
     - Base Case: `fact(0, acc) = acc` 

5. 
---

## *Medium Problems*  

1. **Reverse a String using Recursion**  
   - **Description:** Reverse a string without using loops.  
   - **Technique:**  
     - Print last character first → recurse for substring.  

2. **Check Palindrome using Recursion**  
   - **Description:** Check if a given string is palindrome recursively.  
   - **Technique:** Compare first and last characters, recurse on substring `(l+1, r-1)`.  

3. **Reverse a Stack using Recursion**  
   - **Description:** Reverse a stack using recursion and insert-at-bottom logic.  
   - **Technique:**  
     - Pop all elements recursively.  
     - Insert popped element at the bottom recursively.  

4. **Print All Subsets of a String**  
   - **Description:** Generate all subsets (power set) of a string.  
   - **Technique:** Include or exclude current character and recurse.  

5. **Sum of Digits of a Number**  
   - **Description:** Find the sum of digits of a number using recursion.  
   - **Technique:** `sum(n) = n%10 + sum(n/10)`  

---

## *Hard Problems*  

1. **Tower of Hanoi**  
   - **Description:** Move disks from source rod to destination rod using helper rod.  
   - **Technique:**  
     - Move (n−1) disks → helper  
     - Move nth disk → destination  
     - Move (n−1) disks → destination  

2. **Generate All Permutations of a String**  
   - **Description:** Print all permutations of a given string recursively.  
   - **Technique:** Fix one character and permute the rest recursively.  

3. **N-Queens Problem**  
   - **Description:** Place N queens on a chessboard such that none attack each other.  
   - **Technique:** Backtracking → check safety in rows, columns, and diagonals.  

4. **Sudoku Solver**  
   - **Description:** Fill Sudoku board recursively using backtracking.  
   - **Technique:** Try valid numbers; backtrack when invalid configuration occurs.  

5. **Subset Sum Problem**  
   - **Description:** Find subsets whose sum equals target.  
   - **Technique:** Include/exclude each number recursively.  

---

## *Key Recursion Concepts*  

| Concept | Description |
|----------|--------------|
| **Base Case** | Condition that stops recursion. |
| **Recursive Case** | Function calls itself with modified input. |
| **Stack Frame** | Each recursive call occupies a frame on call stack. |
| **Tail Recursion** | Recursive call is the last statement in the function. |
| **Backtracking** | Undo previous choice and try a different path. |

---

## *Recursion Patterns to Master*  

1. **Simple Recursion** → Factorial, Sum of Numbers  
2. **Two-way Recursion** → Subsets, Permutations  
3. **Tree Recursion** → Binary Tree Traversals  
4. **Backtracking** → Maze, Sudoku, N-Queens  
5. **Tail Recursion** → Optimized factorial or sum functions  

---

## *Complexity Overview*  

| Problem | Time Complexity | Space Complexity |
|----------|----------------|------------------|
| Sum, Factorial | O(n) | O(n) |
| Fibonacci (naïve) | O(2ⁿ) | O(n) |
| Reverse Stack | O(n²) | O(n) |
| Tower of Hanoi | O(2ⁿ − 1) | O(n) |
| Subsets/Permutations | O(2ⁿ) / O(n!) | O(n) |

---
