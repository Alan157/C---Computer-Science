#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Item
{
	int num;
	struct Item* next;
}Item;

typedef struct List
{

	Item* head;
	Item* tail;
	int count;

}List;

void Error_Msg(char*);
/*
Function name:Error_Msg
Input: char*
Output:void
Function Algorithm:prints a string and exits
		*/
void AddAsFirst(Item*, List*);
/*
Function name: AddAsFirst
Input: item*, list*
Output: void
Function Algorithm: adds a node to the top of a linked list
		*/
void AddAsLast(Item*, List*);
/*
Function name: AddAsLast
Input: item*, list*
Output: void
Function Algorithm: adds a node to the end of a linked list
		*/
void MoveToAnotherList(List*, List*, List*);
/*
Function name: MoveToAnotherList
Input: 3 list*
Output: void
Function Algorithm: sorts between nodes
		*/
void CreateList(List*, FILE*);
/*
Function name: CreateList
Input:file*, list*
Output: void
Function Algorithm: create a list
		*/
void PrintItem(Item*);
/*
Function name: PrintItem
Input:item*
Output: void
Function Algorithm: print an item struct fields.
*/

void PrintList(List*, char*);
/*
Function name: PrintList
Input:List*, char*
Output: void
Function Algorithm: print an List of item struct
*/

void DeleteList(List*);
/*
Function name: DeleteList
Input:List*
Output: void
Function Algorithm: delete a linked list
*/

int main()
{
	List L, Posit, Negat;
	
	FILE* in = fopen("ThreeLists.txt", "rt");
	if (in == NULL)
		Error_Msg("input file is wrong");
	L.head = NULL;
	L.tail = NULL;
	L.count = 0;

	Posit.head = NULL;
	Posit.tail = NULL;
	Posit.count = 0;

	Negat.head = NULL;
	Negat.tail = NULL;
	Negat.count = 0;
	
	CreateList(&L, in);
	PrintList(&L, "\nMy List:\n");

	MoveToAnotherList(&L, &Posit, &Negat);
	PrintList(&Posit, "\n\nThe Positive List:\n");
	PrintList(&Negat, "\n\nThe Negative List:\n\n");
	
	fclose(in);

	DeleteList(&Posit);
	DeleteList(&Negat);
	return 0;
}



void Error_Msg(char* msg)
{
	printf("\n%s", msg);
	exit(1);
}

void CreateList(List* L, FILE* f)
{
	int value;
	Item* temp;
	while (fscanf(f, "%d", &value) == 1)
	{
		temp = (Item*)malloc(sizeof(struct Item));
		if (temp == NULL)
		{
			DeleteList(L);
			Error_Msg("Memory!");
		}

		temp->num = value;
		temp->next = NULL;
		if (L->head == NULL)
			L->head = temp;
		else
			L->tail->next = temp;
		L->tail = temp;
		L->count++;
	}
}


void PrintItem(Item* node)
{
	printf("%d--> ", node->num);
}


void PrintList(List* L, char* title)
{
	Item* temp = L->head;
	printf("%s", title);
	while (temp)
	{
		PrintItem(temp);
		temp = temp->next;
	}
	printf("\nThere are %d items in the list", L->count);
}

void AddAsFirst(Item* x, List* n) {
	
	if (n->head == NULL) //case for empty list
	n->tail = x;

	x->next = n->head; //add a node to a linklied list from the head(top)
	n->head = x;
	n->count++;
}




void AddAsLast(Item* x, List* n) {
	

	x->next = NULL;
	//we use tail to add x to the linked list end
	if (n->tail == NULL)  //case for an empty list.
		n->head = x;

	else
		n->tail->next = x;
		


	n->tail = x;
	n->count++; //we increased the size of the linked list so we update the counter.
} 

void DeleteList(List* l) {
	//delete list by removing node from the head and link him to the other node and free the head. also updating the new head
	while (l->head!= NULL)
	{
		Item* temp;

		temp = l-> head;
		l->head = l->head->next;
		free(temp);		
		l->count--;
	}
}

void MoveToAnotherList(List* main, List* Posit, List* Negat) {
	int i;
	Item* temp=NULL;
	
	
	while (main->head) {
		
		//we use temp item to isolate the node that we want to move.
		temp = main->head;
		main->head = main->head->next; //we save in temp the node and we overwrite the node.
		temp->next = NULL; //to send it as a node and not a list.

		if (temp->num >= 0)
		{
			AddAsLast(temp, Posit);
		}

		else 
			AddAsFirst(temp, Negat);
		
		main->count--;
	}
	

}