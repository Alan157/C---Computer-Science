#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	int nume, deno;
}Fraction;

void reduceme(Fraction*fr);
/*
Function name:reduce
Input: Fraction*
Output: void
Function Algorithm: gets a fraction and changes it to the reduces form (gcd=1)
		*/
int gcd(int mone, int mechana);
/*
Function name:gcd
Input: int,int
Output: int
Function Algorithm: receives 2 numbers and returns there gcd (greatest common divisor
		*/

int main() {
	Fraction arr[10];
	int i = 0, flag = 0, num = 0, whole = 0, signflag = 0;
	printf("Enter fractions(max 9) by pairs of integers(0 0 to finish):\n");
	while (i < 9 && flag!=1)
	{
		printf("%d (mone mehane): ", i + 1);
		scanf("%d %d", &arr[i].nume, &arr[i].deno);

		/*
		 We have 2 options for the fraction sign,
		1) numerator and denominator are both positive/negative -> fraction is positive 
		2) numerator and denominator are positive/negative -> fraction is negative
		
		we want to display the sign in the numerator, so in case that dominator is negative we multiply both in -1, 
		if both are negative we get a positive number else just the numerator is negative.
		
		*/
		if (arr[i].deno < 0) 
		{
				arr[i].nume *= -1;
				arr[i].deno *= -1;
		}


		while (arr[i].deno == 0 && arr[i].nume!=0) {
			printf("you are going to divide by zero please enter a new number:\n");
			scanf("%d %d", &arr[i].nume, &arr[i].deno);
			
		}
		if (arr[i].nume == 0 && arr[i].deno == 0) flag = 1;
		if (!flag)i++;
	}
	if (flag == 1 && i == 0)
	{
		printf("We didn't received any fraction, therefore the sum is zero\n");
			getch();
		exit(1);
	}
	num = i-1; // to handle case when we received 0 0 and save the number of elements -1;
	
	arr[9].deno = 1; //to initialize the fraction of our result	
	arr[9].nume = 0; 

	for (i = 0; i <= num; i++) {
		arr[9].deno *= arr[i].deno; // build the common denominator
	}

	for (i = 0; i <= num; i++) {
		arr[9].nume += (arr[i].nume)*(arr[9].deno/arr[i].deno); // build the common denominator
	}
	
	if (arr[9].nume < 0) {
		arr[9].nume *= -1; // if the enumerator is negative it means that the number is negative. we make it postive and we turn the sign flag on (signflag =1 means number is negative)
		signflag = 1;
	}

	while (arr[9].nume > arr[9].deno) {   // if the nume is greater then deno we have improper fraction
		whole++;		// we take the whole part of the fraction out
		arr[9].nume -= arr[9].deno;
	}
	
	if (arr[9].nume != 0)
	{
		reduceme(&arr[9]); //if the nume is not zero we want to make sure that the fraction is reduced to the minimum (gcd=1);

	}
	
	// print section many cases of diffrent situations (including positive and negative integers also if the whole part is 0, or both zero)

	for (i = 0; i < num;i++) {
		printf("%d/%d+", arr[i].nume, arr[i].deno); // here we print each number by itself
	}

	printf("%d/%d=", arr[num].nume, arr[num].deno); //for the last element

	if (signflag == 1) printf("-"); //here we put minus if the sign flag is on for =improper/proper faction= part

	printf("%d/%d=", (whole*arr[9].deno) +arr[9].nume, arr[9].deno); //prints the =improper/proper faction= part

	if (signflag == 1) printf("-"); //here we put minus if the sign flag is on for =whole and proper faction= part

	if (whole!=0 && arr[9].nume!=0) printf("%d and %d/%d", whole, arr[9].nume, arr[9].deno); //prints the =whole and proper faction= part

	if (whole == 0 && arr[9].nume != 0) {
		
		if (arr[9].nume == arr[9].deno) //if we receive a number that the nume=deno we just put 1.
			printf("1");

		else printf("%d/%d", arr[9].nume, arr[9].deno);
	}

	if (whole!= 0 && arr[9].nume == 0) printf("%d",whole);

	if (whole == 0 && arr[9].nume == 0) printf("0");

	return 0;

}
	
void reduceme(Fraction* fr) {
	
	int tempgcd=0; 
	while (tempgcd != 1)
	{
		tempgcd = gcd(fr->nume, fr->deno); //we send the nume and deno to gcd function until its 1
		fr->nume /= tempgcd;
		fr->deno /= tempgcd;
	}
}

int gcd (int mone, int mechana)
{
		int i, gcd=1;
		for (i = 1; i <= mone && i <= mechana; ++i)
		{
			// Checks if i is factor of both integers
			if (mone % i == 0 && mechana % i == 0)
				gcd = i;
		}

		return gcd;
	}



