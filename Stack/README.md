## Stack
Stack is a linear data structure that follows a particular order in which the operations are performed. It works on the principle of LIFO(Last In First Out).


|#|Question|Time Complexity|
|-|-|-|
|1|[Implementation using Array](./Implementation%20using%20Array/)||
|2|[Valid Parenthesis](./Valid%20Parenthesis/)|O(N)|
|3|[Reverse String](./Reversing%20String/)|O(N)|
|4|[Implement 2 Stacks in Array](./Implementing%202%20Stack%20in%20Array/)|O(N)|
|5|[getMin() in O(1) time and O(1) extra space](./GetMin()%20in%20TC%3DO(1)%20%26%20SC%3DO(1)/)|O(1)|
|6|[Next Greater Element](./Next%20Greater%20Element/)|O(N)|

### Algorithm for push:

```cpp
begin
 if stack is full
    return
 endif
else  
 increment top
 stack[top] assign value
end else
end procedure
```

### Algorithm for pop:

```cpp
begin
 if stack is empty
    return
 endif
else
 store value of stack[top]
 decrement top
 return value
end else
end procedure
```