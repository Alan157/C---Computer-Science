#include<stdio.h>
#include<stdlib.h>



#define N 5
typedef  enum { FALSE, TRUE } BOOL;
BOOL Int_Sum(void *, void *, void *);
BOOL Float_Sum(void *, void *, void *);
BOOL Sum( BOOL(*f)(void *,void *,void *), void **p_num, void *number);

int main()
{ 
	int num[] = {3,5,23,5,6}, i, value;
	float  fnum[] = {3.5,5.0,2.3,5.8,6.2}, fvalue;
	void *p_num[N];
	




	printf("\nPlease enter an integer number ");
	scanf("%d", &value);
	if( Sum (   ) == TRUE)
   		printf("There is such sum\n");
	else
  		printf("There is no such sum\n");

	







	printf("\nPlease enter a float number ");
	scanf("%f", &fvalue);
	if( Sum (   ) == TRUE)
   		printf("There is such sum\n");
	else
  		printf("There is no such sum\n");
}



BOOL Int_Sum(void *a, void *b, void *c)
{
  if( *(int*)a + *(int*)b == *(int*)c)
    	return TRUE;
  return FALSE;
}

BOOL Float_Sum(void *a, void *b, void *c)
{
  if( *(float*)a + *(float*)b == *(float*)c)
    	return TRUE;
  return FALSE;
}

