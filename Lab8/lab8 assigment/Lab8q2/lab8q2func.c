#include "lab8q2func.h"
void InitStack(PStack s, int size) {//initialization of a new stack with capacity of size elements

	s->top = -1;//Means empty

	s->Array = (int*)malloc(sizeof(int) * size);
	if (s->Array == NULL) {
		printf("No memo!!Error!");
		getch();
		exit(1);
	}
	s->size = size;
	s->count = 0;
}

void Push(PStack s, int   new_elem) { //add a new member to array of the stack 

	if (s->size != s->count)
	{
		s->Array[s->top + 1] = new_elem;
		s->top++;
		s->count++;

	}
	else
	printf("the stack is full!!");

}

int Pop(PStack s, int* del_value) { //delete member from the array of the stack and  return the deleted value  using  int * del_value
	if (s->top == -1) {
		printf("the stack is empty!");
		return 0;
	}
	else {
		*del_value = s->Array[s->top];
		s->top--;
		s->count--;


		return 1;
	}
}
