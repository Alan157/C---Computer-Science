#include<stdio.h>

#define N 5


void Int_Sum(void *sum,void *num)
{
 *(int*)sum += *(int*)num;
}


void Int_Sub(void *sum ,void *num)
{
 *(int*)sum -= *(int*)num;
}


void Init(void *p)
{
 *(int*)p = 0;
}


int Int_Comp(void *a, void *b)
{
 if( *(int*)a == *(int*)b )
   return 1;
 return 0;
}


int Do_It(void *sum,void** array,void (*p_Init)(void *),void(*p_Sum)(void*,void*),void(*p_Sub)(void*,void*),int(*p_Comp)(void*,void*))
{
 
}


int main()
{
 int num[] = {5,8,23,20,23}, i, answer;
 void *p_num[N];

 





 answer = Do_It(&answer,p_num,Init,Int_Sum,Int_Sub,Int_Comp);
 if(answer == 1)
   printf("The answer is 'Yes'");
 else
   printf("The answer is 'No'");

return 0;
}

