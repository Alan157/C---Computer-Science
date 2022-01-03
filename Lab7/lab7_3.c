#include<stdio.h>
#include<stdlib.h>

typedef struct Item
{
	int num;
	float price;
	struct Item* next;
}*PItem;

void Error_Msg(char*);
void AddNewItem(PItem *,PItem *,int ,int ,float );
void CreateList(PItem *,PItem *,FILE *);
void PrintItem(PItem );
void PrintList(PItem ,char*);
void WriteListToFile(PItem ,FILE *);
void DeleteList(PItem *);

int main()
{
	int a,n;
	float b;
	PItem head=NULL,tail=NULL;
	FILE *in=fopen("input_price.txt","rt");
	if(in == NULL)
            Error_Msg("input file is wrong");
	CreateList(&head,&tail,in);
	PrintList(head,"\nThe Old List:\n");
	printf("\n\nEnter a number and the price\n");
	scanf("%d%f",&a,&b);
	printf("\nEnter a place for the new item:");
	scanf("%d",&n);
	AddNewItem(&head,&tail,n,a,b);
	PrintList(head,"\nThe New List:\n");	
        fclose(in);



	WriteListToFile(head,in);
	DeleteList(&head);
	tail=NULL;
    	return 0;
}


void Error_Msg(char*msg)
{
	printf("\n%s",msg);
	exit(1);
}


void CreateList(PItem *head,PItem *tail, FILE *f)
{
	int a;
	float b;
	PItem temp;
	while(fscanf(f,"%d %f",&a,&b)==2)
        {
		temp=(PItem)malloc(sizeof(struct Item));
                if(temp == NULL)
                {
                   DeleteList(head); 
                   Error_Msg("Memmory!");
                }
		temp->num=a;
		temp->price=b;
		temp->next=NULL;
		if(*head==NULL)
			*head=temp;
		else
			(*tail)->next=temp;
		*tail=temp;
	}
}


void PrintItem(PItem node)
{
	printf("%d,%.1f-->",node->num,node->price);
}



void PrintList(PItem head,char* title)
{
	printf("%s",title);
	while(head)
        {
		PrintItem(head);
		head=head->next;
	}
}


void DeleteList(PItem *head)
{
	PItem tmp=*head;
	while(*head)
        {
		tmp=*head;
		*head=(*head)->next;
		free(tmp);
	}
}