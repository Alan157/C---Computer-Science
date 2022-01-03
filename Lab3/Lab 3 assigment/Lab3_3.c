#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 4
typedef struct //Complex number structure Z=X+YI when r=Real part of Z and i=Imaginary part of Z.
{
	double r, i;

}Complex;

float CRadius(Complex);
void Error_Msg(char* str);
void InputAndWriteToFile(FILE *f);
int CheckFile(FILE *f,float m);



int main()
{
	
	FILE *f;
	
	
	InputAndWriteToFile(f);
        

	printf("\nThere are %d big numbers\n",CheckFile(f,4));
        return 0;
}


void Error_Msg(char* str)
{
   printf("\n%s",str);
   exit(1);
}

float CRadius(Complex z) {
	float r = sqrt(pow(z.r, 2) + pow(z.i, 2)); // calcs the radius size of Z.
	return r;
}