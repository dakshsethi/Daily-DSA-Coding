# Implementing 2 Stacks in an Array
A simple way to implement two stacks is to divide the array in two halves and assign the half space to two stacks, i.e., use arr[0] to arr[n/2] for stack1, and arr[(n/2) + 1] to arr[n-1] for stack2 where arr[] is the array to be used to implement two stacks and size of array be n. 
The problem with this method is inefficient use of array space. A stack push operation may result in stack overflow even if there is space available in arr[]. For example, say the array size is 6 and we push 3 elements to stack1 and do not push anything to second stack2. When we push 4th element to stack1, there will be overflow even if we have space for 3 more elements in array.

**Complexity Analysis**: 
- **Time Complexity**: 
    - **Push operation : O(1)**
    - **Pop operation : O(1)**
- **Auxiliary Space: O(N)** 