#ifndef _lab8q3func
#define _lab8q3func
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 16

typedef struct Item {
	int num;
	struct Item* next;
}Item;
typedef struct Que {
	Item* head, * tail;
	int size;      //a current number of items
}Queue, * PQue;

void Enqueue(PQue Q, int   new_elem);   //add a new member to list of the queue 
int Dequeue(PQue Q, int* del_value);     //delete member from the queue and  return the deleted value  using int *del_value

#endif