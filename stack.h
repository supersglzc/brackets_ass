#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

/*
There are two ways to implement a stack:

--Using array
--Using linked list
*/

//We are interested in brackets of 3 types: (), [], {}
enum BracketType {ROUND=0, SQUARE=1, CURLY=2};
 
//Our items are of type Bracket
typedef struct { 
    enum BracketType type;
    int position;
}Bracket;

// A structure to represent a stack node for a linked list
typedef struct StackNode 
{ 
    Bracket data; 
    struct StackNode* next; 
}StackNode; 

// A structure to represent a stack 
typedef struct  {       
    unsigned capacity;
	int top;	
    //TODO: depending on the implementation - fill-in the fields of a struct
    Bracket * array;
}Stack; 



// function to create a stack of given capacity. 
Stack* createStack(unsigned capacity);

// Stack is full when top index is equal to capacity-1
int isFull(Stack* stack);

// Stack is empty when top is equal to -1 (or head of the list is NULL)
int isEmpty(Stack* stack);

// Function to add an item to stack.  
void push(Stack* stack, Bracket item);

// Function to remove an item from stack and return it. 
Bracket pop(Stack* stack);     
#endif
