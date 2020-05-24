# How to use

- include `stack.h` into the program.
- create the stack: `stack s;`
- initialize the stack by setting `top` = NULL: `initialize_stack(&s);`
- push an element: `push(s, 5);`
- peek the stack top: `peek(s);`
- pop an element: `int data = pop(s);`

## Stack APIs

Sl No | Function                       | Notes
------|--------------------------------|----------------------------------------------------------------------------------
1     | void initialize_stack(stack *) | create the stack and initialize the stack top
2     | void push(stack *, int)        | add an element into the stack
3     | int pop(stack *)               | delete an element from the stack, if the stack is empty then it returns `INT_MIN`
4     | void pop_all(stack *)          | delete all elements from the stack
5     | int peek(stack *)              | display the stack top
6     | void peek_all(stack *)         | display all elements of the stack
