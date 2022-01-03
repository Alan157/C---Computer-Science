#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

struct Item
{
	int code;
	char name[11];
	struct Item *next;
};



int main()
{
	int i;
	struct Item *Head = NULL, *temp;
	for (i = 1; i <= N; i++) {

		temp = (struct Item*)malloc(sizeof(struct Item)); //making a new Node
		if (temp == NULL) {
			printf("no memo"); // if memo allocation failed
			getchar();
			exit(1);
		}

		printf("Enter a new code and name: ");
		scanf("%d %s", &temp->code, temp->name);

		temp->next = Head; //the last node in the list, next=NULL (and every other iteration initialized to the next node)
		Head = temp;

	}
	

	printf("\n\nThe List is:  "); //prints the list
	while (temp!=NULL) {
		printf("%d %s --> ", temp->code, temp->name);
		temp = temp->next;
	}

	while (Head) { //
		temp = Head;
		Head = Head->next;
		free(temp);

	}

	return 0;
}



