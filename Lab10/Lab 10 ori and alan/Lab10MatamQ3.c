#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define  N  5
typedef enum { FALSE, TRUE } BOOL;

void Insert(BOOL(*f)(void*, void*), void* Element, void** Parray);
BOOL Int_Comp(void* FirstElement, void* SecondElement);
BOOL IsFull();


int CurrentCount = 3;  /*global variable - only for the first ADT lab!Please,don't use!*/


int main()
{
	int Array[N] = { 1,4,23 }, Value, i;
	void* PArray[N];                        /*pointers array*/

	for (i = 0; i < N; i++) {
		PArray[i] = Array + i;
	}
	printf("Enter numbers, -999 to stop");
	scanf("%d", &Value);

	while (Value != -999)
	{
		if (!IsFull())
		{
			Array[CurrentCount] = Value;
			Insert(Int_Comp, &Array[CurrentCount], PArray);  /*call the general function*/
			scanf("%d", &Value);
		}
		else
		{
			printf("The array is full");
			break;
		}
	}
	printf("\n Your sorted array is:\n");             /*print the array in sorted order*/
	for (i = 0; i < CurrentCount; i++)
		printf(" %d ", *(int*)PArray[i]);

	return 0;
}



BOOL IsFull()
{
	if (CurrentCount == N)
		return TRUE;
	return FALSE;
}


BOOL Int_Comp(void* FirstElement, void* SecondElement)
{
	if (*(int*)FirstElement > * (int*)SecondElement)
		return TRUE;
	return FALSE;
}


void Insert(BOOL(*f)(void*, void*), void* Element, void** Parray) {
	
	int i = 0, j;

	while (f(Element, Parray[i]) == TRUE) 	i++; //once we finish the loop the i represent the index of the element that our element is greater then him. and the element need to be placed in the i+1 place.
	
	for (j = CurrentCount; j >= i+1; j--) {
		Parray[j] = Parray[j - 1];
	}
	Parray[i]= Element;
	CurrentCount++; //we increase the size of the current array.
	
	

	
}