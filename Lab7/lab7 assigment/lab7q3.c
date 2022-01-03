#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Item
{
	int num;
	float price;
	struct Item* next;
}*PItem;

void Error_Msg(char*);
/*
Function name:Error_Msg
Input: char*
Output:void
Function Algorithm:prints a string and exits
		*/
void AddNewItem(PItem*, PItem*, int, int, float);
/*
Function name:AddNewItem
Input: PItem*, PItem*, int, int, float
Output:void
Function Algorithm:ADD A NEW ITEM
		*/
void CreateList(PItem*, PItem*, FILE*);
/*
Function name : CreateList
Input : file*, list*
Output : void
Function Algorithm : create a list
*/
void PrintItem(PItem);
/*
Function name : PrintItem
Input : PItem
Output : void
Function Algorithm : print an item struct fields.
*/
void PrintList(PItem, char*);
/*
Function name: PrintList
Input:PItem, char*
Output: void
Function Algorithm: print an List of item struct
*/
void WriteListToFile(PItem, FILE*);
/*
Function name: PrintList
Input:PItem, char*
Output: void
Function Algorithm: copy the linked list to a file.
*/
void DeleteList(PItem*);
/*
Function name: DeleteList
Input:PItem*
Output: void
Function Algorithm: delete a linked list
*/
int ListLength(PItem q);
/*
Function name: ListLength
Input:PItem
Output: int
Function Algorithm: find the size of a linked list.
*/

int main()
{
	int a, n;
	float b;
	PItem head = NULL, tail = NULL;
	FILE* in = fopen("input_price.txt", "rt");
	if (in == NULL)
		Error_Msg("input file is wrong");
	CreateList(&head, &tail, in);
	PrintList(head, "\nThe Old List:\n");
	printf("\n\nEnter a number and the price\n");
	scanf("%d%f", &a, &b);
	printf("\nEnter a place for the new item:");
	scanf("%d", &n);
	AddNewItem(&head, &tail, n, a, b);
	PrintList(head, "\nThe New List:\n");
	fclose(in);



	WriteListToFile(head, in);
	DeleteList(&head);
	tail = NULL;
	return 0;
}


void Error_Msg(char* msg)
{
	printf("\n%s", msg);
	exit(1);
}


void CreateList(PItem* head, PItem* tail, FILE* f)
{
	int a;
	float b;
	PItem temp;
	while (fscanf(f, "%d %f", &a, &b) == 2)
	{
		temp = (PItem)malloc(sizeof(struct Item));
		if (temp == NULL)
		{
			DeleteList(head);
			Error_Msg("Memmory!");
		}
		temp->num = a;
		temp->price = b;
		temp->next = NULL;
		if (*head == NULL)
			*head = temp;
		else
			(*tail)->next = temp;
		*tail = temp;
	}
}


void PrintItem(PItem node)
{
	printf("%d,%.1f-->", node->num, node->price);
}


void PrintList(PItem head, char* title)
{
	printf("%s", title);
	while (head)
	{
		PrintItem(head);
		head = head->next;
	}
}

void DeleteList(PItem* head)
{
	PItem tmp = *head;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
void AddNewItem(PItem* head, PItem* tail, int n, int a, float b) {

	int i, size;
	PItem new, buffer = *head, temp; 

	size = ListLength(*head); //get the size of the linked list
	
	//create a new node to store the information.
	new = (PItem)malloc(sizeof(struct Item));
	if (new == NULL)
	{
		DeleteList(head);
		Error_Msg("Memmory!");
	}

	// initialize the new item to add.
	new->num = a;
	new->price = b;
	new->next = NULL;


	if (n != 1 &&n<size+1) { //cases for the linked list expect the ends.
		for (i = 1; i < n - 1; i++) {
			buffer = buffer->next; //bufffer = the node in the n-1 place
		}

		temp = buffer->next;
		buffer->next = new;
		new->next = temp;
	}
	
	if (n == 1) { //if we want to add as first
	
		new->next = buffer;
		*head = new;
	}

	if (n == size+1) { //add as last
		(*tail)->next = new;
		new->next = NULL;
	}

	if (n > size+1) //incase for out of range number we just print the old one agian and as the first and print error.
		printf("\nError! the size is %d not in range!!\n", size);
	

}

int ListLength(PItem q) {
	if (q == NULL) return 0;
	return 1 + ListLength(q->next);
}

void WriteListToFile(PItem head, FILE* out) {
	PItem buffer;
	buffer = head; //to save the pointer
	out = fopen("input_price.txt", "w");
	if (out == NULL)
		Error_Msg("input file is wrong");

	while (buffer)
	{
		fprintf(out, "%d %.2f ", buffer->num, buffer->price);
		buffer = buffer->next; //buffer ++;
	}

	fclose(out);
}