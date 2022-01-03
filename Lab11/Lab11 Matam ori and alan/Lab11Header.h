#ifndef _Lab11Imp
#define _Lab11Imp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node STACKNODE, *PSTACKNODE; //pointer to a  general structure
 
typedef enum{FALSE,TRUE}BOOL; //to check if is empty or not 


//General functions decelerations 

void push(void* key, PSTACKNODE* stack); // a function to add to the head of a one way linked list.

void pop(PSTACKNODE* stack, void(*free_data)(void*)); // a function to remove from the head of a one way linked list.

BOOL isempty(PSTACKNODE stack); // check if the "stack" or the list is empty.

void* top(PSTACKNODE stack); // return the adress to the data value inside the head of the linked list 








#endif