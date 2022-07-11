# Detect Loop in a Linked List
Given a linked list, check if the linked list has loop or not. Below diagram shows a linked list with a loop. 
![Loop in a Linked List](https://www.geeksforgeeks.org/wp-content/uploads/2009/04/Linked-List-Loop.gif)

#### Approach
Traverse the list one by one and keep putting the node addresses in a Hash Table. At any point, if NULL is reached then return false, and if the next of the current nodes points to any of the previously stored nodes in  Hash then return true.

**Time Complexity: O(N)**
**Space Complexity: O(N)**