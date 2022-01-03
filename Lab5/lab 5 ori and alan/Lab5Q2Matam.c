#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 32 //for 32 bit int unsigned

int Bit_Count(unsigned int x);
/*
Function name: Bit_Count
Input: unsigned int
Output: int
Function Algorithm: using mask to find the "1" numbers in the binary number representation of x;
		*/
void Bin_Print(unsigned int x);
/*
Function name: Bit_Print
Input: unsigned int
Output: void
Function Algorithm: using mask to print the binary representation of the x
		*/
int main()
{
	unsigned int x;

	printf("Enter a number:");
	scanf("%d", &x);
	printf("There are %d bits equal to one in %d\n", Bit_Count(x), x);
	printf("The binary representation of %d is ", x);
	Bin_Print(x);

	return 0;
}


int Bit_Count(unsigned int x)
{
	int counter = 0;
	unsigned int mask = 1;

	while (x != 0) {
		unsigned int temp = x;

		if (temp & mask) //mask is 000000000.....01 so we sort of doing num%10 to find if its 1 or 0 
			counter++; 
		
		x>>=1;
	}

	
	return counter;
}



void Bin_Print(unsigned int x)
{
	int i;
	unsigned int mask = 1;
	mask <<= N - 1; //the mask is 10............00000

	for (i = 0; i < N; i++) {
		int temp = 0;

		if (x & mask) //if the result of x*mask is not 0 its meants that the MSB is 1
			temp = 1;

		printf("%d", temp);
			x <<= 1;
		
	}
}