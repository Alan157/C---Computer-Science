#include<stdio.h>

#define N 5


void Int_Sum(void* sum, void* num)
{
	*(int*)sum += *(int*)num;
}


void Int_Sub(void* sum, void* num)
{
	*(int*)sum -= *(int*)num;
}


void Init(void* p)
{
	*(int*)p = 0;
}


int Int_Comp(void* a, void* b)
{
	if (*(int*)a == *(int*)b)
		return 1;
	return 0;
}


int Do_It(void* sum, void** array, void (*p_Init)(void*), void(*p_Sum)(void*, void*), void(*p_Sub)(void*, void*), int(*p_Comp)(void*, void*))
{
	int i;

	p_Init(sum); //initialize sum
	
	
	for (i = 0; i < N; i++) {
	
		if (p_Comp(sum, array[i])) return 1; // we check if we have a match between the sum until this point with the next element value
		(i % 2) ? p_Sub(sum, array[i]) : p_Sum(sum, array[i]); // if the index is odd we subtract else we add

	}

	return 0;


}


int main()
{
	int num[] = { 5,8,23,20,23 }, i, answer;

	void* p_num[N];

	for (i = 0; i < N; i++) {
		p_num[i] = &num[i]; //we initialize the general pointers array to the specific array elements. 
	}


	answer = Do_It(&answer, p_num, Init, Int_Sum, Int_Sub, Int_Comp);
	if (answer == 1)
		printf("The answer is 'Yes'");
	else
		printf("The answer is 'No'");

	return 0;
}

