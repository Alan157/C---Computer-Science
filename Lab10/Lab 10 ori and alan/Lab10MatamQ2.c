#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef  enum { FALSE, TRUE } BOOL;
BOOL Int_Sum(void*, void*, void*);
BOOL Float_Sum(void*, void*, void*);
BOOL Sum(BOOL(*f)(void*, void*, void*), void** p_num, void* number);//function the recive a pointer to a function that return ture/false and gets 3 void pointers. also recives a pointer to a pointers array and a pointer to a number.


int main()
{
	int num[] = { 3,5,23,5,6 }, i, value;
	float  fnum[] = { 3.5,5.0,2.3,5.8,6.2 }, fvalue;
	void* p_num[N], * target;



	

	printf("\nPlease enter an integer number ");
	scanf("%d", &value);
	target = &value; //we put the targted value into a void* just to do more, we can also send the adress of &fvalue.
	for (i = 0; i < N; i++) {
		p_num[i] = num+i;
	}
	
	if (Sum(Int_Sum,p_num,target) == TRUE)
		printf("There is such sum\n");
	else
		printf("There is no such sum\n");






	printf("\nPlease enter a float number ");
	scanf("%f", &fvalue);
	target = &fvalue; //we put the targted value into a void* just to do more, we can also send the adress of &fvalue.
	for (i = 0; i < N; i++) {
		p_num[i] = fnum + i;
	}
	if (Sum(Float_Sum, p_num, target) == TRUE)
		printf("There is such sum\n");
	else
		printf("There is no such sum\n");
}



BOOL Int_Sum(void* a, void* b, void* c)
{
	if (*(int*)a + *(int*)b == *(int*)c)
		return TRUE;
	return FALSE;
}

BOOL Float_Sum(void* a, void* b, void* c)
{
	if (*(float*)a + *(float*)b == *(float*)c)
		return TRUE;
	return FALSE;
}

BOOL Sum(BOOL(*f)(void*, void*, void*), void** p_num, void* number) {

	int i, j;

	for (i = 0; i < N - 1; i++) //the last element in the array is already checked with the whole array so its not necessary to check it. 
		for (j = i + 1; j < N; j++) //loop for b
		{
			if (f(p_num[i], p_num[j], number) == TRUE)
				return TRUE;
		}
	


	
	
	return FALSE;

			
		

			
}