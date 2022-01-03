#ifndef _lab8q1func
#define _lab8q1func
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 16

typedef struct Item {
	int num;
	struct Item* next;
}Item;

typedef struct Stack {
	Item* head;
	int size;         //a current number of items
}Stack, *PStack;

void Push(PStack s, int   new_elem);    
/*
Function name:Push
Input: stack*, int
Output: void
Function Algorithm:add a new member to list of the stack
		*/
int Pop(PStack s, int* del_value);   
/*
Function name:Pop
Input: stack*, int*
Output: int
Function Algorithm: delete member from the stack and  return the deleted value  using  int * del_value
		*/











#endif