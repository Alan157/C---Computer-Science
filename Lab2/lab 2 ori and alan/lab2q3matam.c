#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define NUM 3 
typedef struct //Complex number structure Z=X+YI when r=Real part of Z and i=Imaginary part of Z.
{
	double r, i;

}Complex;

double CRadius(Complex z);
/*
Function name: CRadius
Input: Complex structure
Output: double
Function Algorithm: Calculates the radius of a complex number
		*/
Complex* CMax(Complex *a);
/*
Function name: CMax
Input: Complex structure array
Output: Complex structure
Function Algorithm: returns a pointer to the biggest complex number of the received array.
		*/

int main()
{
	Complex arr[NUM], *max; //max to store pointer that we receive from CMax function
	int i;

	printf("Enter 3 complex numbers:\n"); //build the complex number array.
		for (i = 0; i < NUM; i++)
			scanf("%lf %lf", &arr[i].r, &arr[i].i);
				
			
		max = CMax(arr); //calling CMax function to receive the biggest complex number in the array

		printf("The max complex number is %.2lf + %.2lfi\nThe radius of the max number is %.2lf",max->r,max->i, CRadius(*max));

		return 0;

}


double CRadius(Complex z) {
	double r = sqrt(pow(z.r, 2) + pow(z.i, 2)); // calcs the radius size of Z.
	return r;
}

Complex* CMax(Complex* a) {
	double arr[NUM] = { 0 }; //help array
	int i, maxi=0;
	for (i = 0; i < NUM; i++) // we build the help array with the radius size of all the complex numbers, we keep the same indexes of the original structure array.
	{
		arr[i] = CRadius(a[i]); //call the CRadius function to calculate the size
	}
	for (i=1;i<NUM;i++)
		if (arr[i] > arr[maxi]) maxi = i; //finds the max index
		
	return a + maxi; //returns pointer to the max complex number in the array using the maxi index.
		
}


