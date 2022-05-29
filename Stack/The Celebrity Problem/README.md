# The Celebrity Problem
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
**Note:** Follow 0 based indexing.
 

**Example 1:**
```txt
Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity.
```

**Example 2:**
```txt
Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.
```

## Explanantion:
### Method 1: This uses Graph to arrive at the particular solution.

**Approach:**
Model the solution using graphs. Initialize indegree and outdegree of every vertex as 0. If A knows B, draw a directed edge from A to B, increase indegree of B and outdegree of A by 1. Construct all possible edges of the graph for every possible pair [i, j]. There are NC2 pairs. If a celebrity is present in the party, there will be one sink node in the graph with outdegree of zero and indegree of N-1. 
 

**Algorithm:** 
- Create two arrays indegree and outdegree, to store the indegree and outdegree
- Run a nested loop, the outer loop from 0 to n and inner loop from 0 to n.
- For every pair i, j check if i knows j then increase the outdegree of i and indegree of j
- For every pair i, j check if j knows i then increase the outdegree of j and indegree of i
- Run a loop from 0 to n and find the id where the indegree is n-1 and outdegree is 0

**Time Complexity: O(N^2)**
**Space Complexity: O(N)** 

### Method 2:
**Approach :** 
- If A knows B, then A can’t be a celebrity. Discard A, and B may be celebrity.
- If A doesn’t know B, then B can’t be a celebrity. Discard B, and A may be celebrity.
- Repeat above two steps till there is only one person.
Ensure the remained person is a celebrity. (What is the need of this step?)

**Algorithm:** 
- Create a stack and push all the id’s in the stack.
- Run a loop while there are more than 1 element in the stack.
- Pop top two element from the stack (represent them as A and B)
- If A knows B, then A can’t be a celebrity and push B in stack. Else if A doesn’t know B, then B can’t be a celebrity push A in stack.
- Assign the remaining element in the stack as the celebrity.
- Run a loop from 0 to n-1 and find the count of persons who knows the celebrity and the number of people whom the celebrity knows. if the count of persons who knows the celebrity is n-1 and the count of people whom the celebrity knows is 0 then return the id of celebrity else return -1.

**Time Complexity: O(N)**
**Space Complexity: O(N)** 