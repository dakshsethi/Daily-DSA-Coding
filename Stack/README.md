## Stack
Stack is a linear data structure that follows a particular order in which the operations are performed. It works on the principle of LIFO(Last In First Out).

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