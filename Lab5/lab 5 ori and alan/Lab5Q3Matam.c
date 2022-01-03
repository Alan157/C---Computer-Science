#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 8 //for 8bit


void BinPrint(unsigned char ch);
/*
Function name:BinPrint
Input:char
Output:void
Function Algorithm: prints the binary representation of a number
		*/

unsigned char check_ms(unsigned char ch);
/*
Function name:check_ms
Input:unsigned char
Output:unsigned char
Function Algorithm: checks if the mab is 1
		*/
unsigned char change_bit(unsigned char ch,int n);
/*
Function name:change_bit
Input:unsigned char,int 
Output:unsigned char
Function Algorithm: changes the n bit (from the left)
		*/
int main()
{
	unsigned char num1 = 102, num2 =102;
	int n;

	printf("\nThe first part :");
	printf("\nThe number is %d   ", num1);
	BinPrint(num1);
	num1 = check_ms(num1);
	printf("\nThe new number is: %d   ", num1);
	BinPrint(num1);

	printf("\n\nThe second part :");
	printf("\nThe number is %d   ", num2);
	BinPrint(num2);
	printf("\nEnter a number of the bit to change(1-8):");
	scanf("%d", &n);
	num2 = change_bit(num2, n);
	printf("\nThe new number is: %d   ", num2);
	BinPrint(num2);     /*Binary representation of number*/
	return 0;
}



void BinPrint(unsigned char ch)
{
	int i;
	unsigned char mask = 1;
	mask <<= N-1; 
	

	for (i = 0; i < N; i++) {
		int temp = 0;

		if (ch & mask) 
			temp = 1;  //if the bit in the n place is 1 we print 1

		printf("%d", temp);
		ch <<= 1;

	}
}

unsigned char check_ms(unsigned char ch) {

	unsigned char mask = 1;
	mask <<= N - 1; //mask to check msb sign.

	if (!(mask & ch)) //if the msb is zero we add 1 to ch.
		ch |= mask;

	return ch;
}

unsigned char change_bit(unsigned char ch, int n) {
	//11111....N=0.1111 - AND IF ITS 1 ->0
   //00000.....N=1.0000 - OR IF ITS 0 ->1
	
	unsigned char OrMask=1, AndMask;

	OrMask <<= n;
	AndMask = ~OrMask;
	
	if ((ch & OrMask) == OrMask) //this means that the bit in the n place is 1 
	{
		ch &= AndMask; //now the bit in the n place is 0
	}
	// if failed it means that the bit in the n place is 0
	else ch |= OrMask; //now the bit in in the n place is 1 
	
	return ch;
}
