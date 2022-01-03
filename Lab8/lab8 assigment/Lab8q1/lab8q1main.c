#include "lab8q1func.h"



int main() {
	int i, flag = 1, popped = 0 , arr[NUM] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	PStack Manager = NULL, s;

	Manager = (PStack)malloc(sizeof(Stack));
	if(Manager == NULL){
		printf("no memo!");
		getch();
		exit(1);
	}
	Manager->size = 0;
	Manager->head = NULL;
	
	

	printf("Hello!,\nToday we will show you how a stack works!\n");
	printf("We will use this array for example:\n");
	for (i = 0; i < NUM; i++) //here we push all the numbers in the array
		printf("%d,", arr[i]);
	printf("\nWe 'Push' the numbers to the stack:");
	for (i = 0; i < NUM; i++) //here we push all the numbers in the array.
	{
		Push(Manager,arr[i]);
		printf("%d->", Manager->head->num);
		
	}

	printf("\nWe 'Pop' the numbers to the stack:");
	for (i = 0; (i < NUM)&&(flag==1); i++)
	{
		flag = Pop(Manager, &popped);
		if (flag == 1)
			printf("%d->",popped);
		
		
	}
	printf("\nAs you can see the stack works in a LIFO method,\nthe last number was pushed is the first to be popped.\n");
	free(Manager);
}