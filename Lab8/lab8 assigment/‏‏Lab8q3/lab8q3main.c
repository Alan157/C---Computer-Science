#include "lab8q3func.h"

int main() {
	int i, flag = 1, popped = 0, arr[NUM] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	PQue Manager = NULL, s;

	Manager = (PQue)malloc(sizeof(Queue));
	if (Manager == NULL) {
		printf("no memo!");
		getch();
		exit(1);
	}
	Manager->size = 0;
	Manager->head = NULL;
	Manager->tail = NULL;



	printf("Hello!,\nToday we will show you how a queue works!\n");
	printf("We will use this array for example:\n");
	for (i = 0; i < NUM; i++) //here we print all the numbers in the array
		printf("%d,", arr[i]);
	printf("\nWe 'Enqueue' the numbers in a queue:");
	for (i = 0; i < NUM; i++) //here we Enqueue all the numbers in the array.
	{
		Enqueue(Manager, arr[i]);
		printf("%d->", arr[i]);

	}

	printf("\nWe 'Dequeue' the numbers to the queue:");
	for (i = 0; (i < NUM) && (flag == 1); i++)
	{
		flag = Dequeue(Manager, &popped);
		if (flag == 1)
			printf("%d->", popped);


	}
	printf("\nAs you can see the queue works in a FIFO method,\nthe last number was pushed is the last to be Dequeued.\n");
}