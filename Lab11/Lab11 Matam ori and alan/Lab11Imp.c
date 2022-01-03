#include "Lab11Header.h"

//general structure deceleration (node in a one way linked list)
struct node
{
	void* data;
	struct node* next;
};

//implementation of all the general functions 

void* top(PSTACKNODE stack)
{

	return (stack->data); //send the address
}

void push(void* key, PSTACKNODE* stack)
{
	PSTACKNODE newnode;
	newnode = (PSTACKNODE)malloc(sizeof(STACKNODE)); //create new node we assume that memo allocation succeeded
	newnode->data = key;
	newnode->next = (*stack); //we head to the head
	(*stack) = newnode; //update the head
}

void pop(PSTACKNODE* stack, void(*free_data)(void*)) {

	PSTACKNODE oldnode;
	oldnode = (*stack);
   (*stack) = (*stack)->next;
   free_data(oldnode->data); //use the pointer to the function to free general memo.
   free(oldnode);
   oldnode = NULL;
}

BOOL isempty(PSTACKNODE stack)
{
	return (stack == NULL) ? TRUE : FALSE; //if empty return 1 else 0

}

