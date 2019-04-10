// C-implementation of stack 
#include "stack.h" 
  
// function to create a stack of given capacity. 
Stack* createStack(unsigned capacity){
	Stack* stack = (Stack*) malloc(sizeof(Stack)); 
    stack->capacity = capacity; 
    stack->top = -1;
    stack->array = (Bracket*) malloc(stack->capacity * sizeof(Bracket));
    return stack; 
}

// Stack is full when top index is equal to capacity-1
int isFull(Stack* s){
	return s->top == s->capacity - 1;
}

// Stack is empty when top is equal to -1 (or head of the list is NULL)
int isEmpty(Stack* s){
	return s->top == -1;
}

// Function to add an item to stack.  
void push(Stack* s, Bracket bk){
	if (!isFull(s))
		s->array[++(s->top)] = bk;
	// as in the main program, let's not add error handling
}

// Function to remove an item from stack and return it. 
Bracket pop(Stack* s){
	return s->array[(s->top)--];
}    
  
