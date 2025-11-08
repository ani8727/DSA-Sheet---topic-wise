# Linked List Problems Series  

A structured roadmap to master **Linked List concepts** for interviews and DSA practice.  
Includes categorized problems (Easy, Medium, Hard) with explanations, techniques, viva questions, and revision notes.

---

## *Easy Problems*  

1. **About Singly Linked List**  
   - **Description:** Understand the structure of a singly linked list node (data + next pointer).  
   - **Technique:** Basic node creation and linking - (class or Structure).

2. **Search a Node**  
   - **Description:** Search a node by changing the `next` pointer until the desired value is found.  
   - **Technique:** Traversal and pointer adjustment; return node or -1 if not found.

3. **Reverse Linked List [L-206]**  
   - **Description:** Reverse the order of nodes in a singly linked list.  
   - **Technique:** Iterative pointer reversal or recursion.  

4. **Find Middle of Linked List [L-876]**  
   - **Description:** Find the middle node using two pointers moving at different speeds.  
   - **Technique:** **Tortoise and Hare (Slow–Fast Pointer)** algorithm.  

5. **Count Nodes in Linked List**  
   - **Description:** Count total nodes by simple traversal till the end.  
   - **Technique:** Basic traversal.  

---

## *Medium Problems*  

1. **Detect Cycle in Linked List [L-141]**  
   - **Description:** Check whether a linked list has a cycle.  
   - **Technique:** Floyd’s Cycle Detection (Slow & Fast pointer).  

2. **Find Start Node of Cycle [L-142]**  
   - **Description:** After detecting a cycle, find the node where the cycle begins.  
   - **Technique:** Reset one pointer to head and move both one step at a time.  

3. **Remove N-th Node from End [L-19]**  
   - **Description:** Remove the N-th node from the end of a list in one pass.  
   - **Technique:** Two-pointer approach; use dummy node for edge cases.  

4. **Merge Two Sorted Lists [L-21]**  
   - **Description:** Merge two sorted linked lists into one sorted list.  
   - **Technique:** Two-pointer merging (similar to merge sort step).  

5. **Odd Even Linked List [L-328]**  
   - **Description:** Rearrange nodes so that odd-indexed nodes appear before even-indexed nodes.  
   - **Technique:** Pointer re-linking using two separate chains (odd & even).  

6. **Reorder List [L-143]**  
   - **Description:** Reorder nodes from start and end alternately (L0 → Ln → L1 → Ln−1 ...).  
   - **Technique:** Find middle → Reverse second half → Merge both halves.  

7. **Delete Node (without head pointer) [L-237]**  
   - **Description:** Delete a node when only a pointer to that node is given.  
   - **Technique:** Copy next node’s data and skip it.  

---

## *Hard Problems*  

1. **Reverse Nodes in K-Groups [L-25]**  
   - **Description:** Reverse every K consecutive nodes in a linked list.  
   - **Technique:** Recursion + Group-wise reversal.  

2. **Flatten a Multi-Level Linked List [GFG]**  
   - **Description:** Flatten a linked list with child pointers into a single-level sorted list.  
   - **Technique:** Recursion or min-heap approach.  

3. **Copy List with Random Pointer [L-138]**  
   - **Description:** Clone a list where each node has a random pointer in addition to next.  
   - **Technique:** Hash map for mapping original to cloned nodes; or 3-pass in-place trick.  

