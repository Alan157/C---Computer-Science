#include "lab8q3func.h"

void Enqueue(PQue Q, int new_elem) {

	Item* temp;
	temp = (Item*)malloc(sizeof(Item));
	if (temp==NULL)
	{
		printf("no memo");
		getch();
		exit(1);
	}

	temp->num = new_elem;
	if (Q->size<NUM) {
		
		if (Q->head) //case if not empty
		{
			temp->next = NULL;
			Q->tail->next = temp;
			Q->tail = temp;
		}
		else //if empty update tail..
		{
			Q->head = temp;
			Q->tail = temp;
		}
		Q->size++;
	}
	else
		printf("The Que is full.\n");
}
int Dequeue(PQue Q, int* del_value) {     //delete member from the queue and  return the deleted value  using int *del_value
	Item* temp;
	temp = Q->head;

	if (Q->size>0) {
		*del_value = temp->num;
		
		Q->head = Q->head->next;
	
		free(temp); //we free head
		Q->size--;
		return 1;

	}
	else {
		printf("Queue is empty!");
		return 0;
	}
	
}
