#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10


int main()
{
	int i, Arr[SIZE] = { 3,5,10,1,2,7,6,9,0,8 }, **Parr;
	Parr = (int**)malloc(SIZE* sizeof(int*));
	for (i = 0; i < SIZE; i++)
	{
		Parr[i] = (int*)malloc(sizeof(int*));
	}
	if (*Parr == NULL) {
		exit(1); 
		getch();
		printf("Memo allocation failed");
	}
	for (i = 0; i < SIZE; i++)
	{
		Parr[i] = &Arr[i];
	
	}
	printf("My Array is: ");
	for (i = SIZE - 1; i >= 0; i--)
	{
		printf("%d,", *Parr[i]);
	}
	for (i = 0; i < SIZE; i++)
	free(Parr[i]);
		
	free(Parr);
   return 0;

}

