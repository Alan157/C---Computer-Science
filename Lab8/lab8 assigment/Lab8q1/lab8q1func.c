#include "lab8q1func.h"
void Push(PStack s, int new_elem) {
	//This functions is similar to add to head in a linked list function
	if (s->size < NUM) {


		Item* temp; // we create a temp item* to save pushed node and update the list manager
		if (temp == NULL) {
			printf("no memo!");
			getch();
			exit(1);
		}
		temp->next = s->head;
		temp->num = new_elem;
		s->head = temp;
		s->size++;
	}
	else printf("The stack is full!!");
}

int Pop(PStack s, int* del_value) {
	//this function is similar to delete from head in a linked list.
	Item* temp;
	temp = (Item*)malloc(sizeof(Item));
	if (temp == NULL) {
		printf("no memo!");
		getch();
		exit(1);
	}
	if (s->size > 0)
	{
		*del_value = s->head->num; //we return the popped value via a pointer.
		temp = s->head;
		s->head = s->head->next;
		free(temp); //we free the deleted node
		s->size--;
		return 1;
	}
	else {
		printf("The stack is empty!! cannot pop!");
		return 0;
	}
	

}
