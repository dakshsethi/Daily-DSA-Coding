# Insertion in a Linked List
A node can be added in three ways:
1) At the front of the linked list  
2) After a given node. 
3) At the end of the linked list.

### Add a node at the front: (4 steps process) 
The new node is always added before the head of the given Linked List. And newly added node becomes the new head of the Linked List. For example, if the given Linked List is 10->15->20->25 and we add an item 5 at the front, then the Linked List becomes 5->10->15->20->25. Let us call the function that adds at the front of the list is push(). The push() must receive a pointer to the head pointer, because push must change the head pointer to point to the new node.
![Add Node To Front](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_at_start.png)
We have a pointer to the head and we can directly attach a node and change the pointer. So the Time complexity of inserting a node at head position is O(1) as it does a constant amount of work.

### Add a node after a given node: (5 steps process) 
We are given a pointer to a node, and the new node is inserted after the given node. 
![Add Node After Given Node](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_middle.png)
Time complexity of insertAfter() is O(n) as it depends on n where n is the size of the linked list, Space complexity: O(1) since using constant space to modify pointers

### Add a node at the end: (6 steps process)
The new node is always added after the last node of the given Linked List. Since a Linked List is typically represented by the head of it, we have to traverse the list till the end and then change the next to last node to a new node.
![Add Node At The End](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_last.png)
Time complexity of append is O(n) where n is the number of nodes in the linked list. Since there is a loop from head to end, the function does O(n) work. 
This method can also be optimized to work in O(1) by keeping an extra pointer to the tail of the linked list.