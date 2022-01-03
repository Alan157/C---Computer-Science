#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct std
{
	char code[11];
	char *name;
	char Dep[4];
	int marks[3];
	float avg;
	struct std* next;
}std;

void Error_Msg(char* str);
std* FromFileToList(std* head,FILE *in);
std* Delete_Stud(std* toDel,std* head);
std* DeleteList(std* head);
void PrintList(std* head);
std* FindMax(std* head);

int main()
{
	int i;
	FILE *f;
	std *Head=NULL, *temp;
	if((f=fopen("List.txt","rt")) == NULL)
           Error_Msg("input error");
	Head=FromFileToList(Head,f);

	printf("\nThe list is:");
	PrintList(Head);
	/*
	
	temp = FindMax(Head);
        printf("\n\nthe student with max average:\n");
	printf("%s %s %s ",temp->code,temp->name,temp->Dep);
        for(i=0;i<3;i++)
          printf(" %d ",temp->marks[i]);

	printf("\n\nThe list after change:");
	Head=Delete_Stud(FindMax(Head),Head);
	PrintList(Head);
	Head = DeleteList(Head);
	*/
        return 0;
}

void Error_Msg(char* str)
{
	printf("\n%s",str);
        exit(1);
}


/*

std* Delete_Stud(std* toDel,std* head)
{
  if(head == NULL)
    return NULL;

  if(toDel==head)
  {

  }
  else
  {

  }
  return head;
}
*/

std* FromFileToList(std* head, FILE* in) {
	std* temp;
	char tempname[256];

	temp = (struct Item*)malloc(sizeof(struct Item)); //making a new Node
	if (temp == NULL) {
		printf("no memo"); // if memo allocation failed
		getchar();
		exit(1);
	}

	while (fscanf(in, "%s %s %s %d %d %d", temp->code, tempname, temp->Dep, &temp->marks[0], &temp->marks[1], &temp->marks[2]) != EOF) {


		temp->name = (char*)malloc(sizeof(strlen(tempname) + 1));
		if (temp->name == NULL) Error_Msg("No Memo");
		strcpy(temp->name, tempname);
		temp->avg = (temp->marks[0] + temp->marks[1] + temp->marks[2]) / 3.0;



		temp->next = head; //the last node in the list, next=NULL (and every other iteration initialized to the next node)
		head = temp;

		temp = (struct Item*)malloc(sizeof(struct Item)); //making a new Node
		if (temp == NULL) {
			printf("no memo"); // if memo allocation failed
			getchar();
			exit(1);
		}

	}


}


void PrintList(std* head) {
	while (head != NULL) {
		printf("%s %s %s %d %d %d\n", head->code, head->name, head->Dep, head->marks[0], head->marks[1], head->marks[2]);
		head = head->next;
	}

}



//std* DeleteList(std* head);

//std* FindMax(std* head);