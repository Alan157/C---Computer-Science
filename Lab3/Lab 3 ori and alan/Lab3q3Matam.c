#define _CRT_SECURE_NO_WARNINGS
#define N 4
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct //Complex number structure Z=X+YI when r=Real part of Z and i=Imaginary part of Z.
{
	float r, i;

}Complex;

float CRadius(Complex z);
/*
Function name: CRadius
Input: complex structure
Output: float number
Function Algorithm: calcs the radius of the complex number given
		*/
void Error_Msg(char* str);
/*
Function name:Error_Msg
Input: string
Output:void
Function Algorithm: prints an error msg and exits the program.
		*/
void InputAndWriteToFile(FILE* f);
/*
Function name: InputAndWriteToFile
Input: file
Output: void
Function Algorithm: recives n complex numbers and writes them to the given text file togther with their radius
		*/
int CheckFile(FILE* f, float m);
/*
Function name:CheckFile 
Input: file and float number
Output: int number
Function Algorithm: runs over the file and returns the number of complex numbers that have a bigger radius then "m" .
		*/


int main()
{

	FILE* f;

	f = fopen("complex_number.txt", "wt"); //open to write only
	if (f == NULL) {
		Error_Msg("Error We couldn't open complex_number.txt "); //check if we succeeded to open the txt file.
		return 1;
	}
	
	InputAndWriteToFile(f);

	fclose(f);


	printf("\nThere are %d big numbers\n", CheckFile(f, 4));
	return 0;
}


void Error_Msg(char* str)
{
	printf("\n%s", str);
	exit(1);
}

float CRadius(Complex z) {
	float r = sqrt(pow(z.r, 2) + pow(z.i, 2)); // calcs the radius size of Z.
	return r;
}

void InputAndWriteToFile(FILE* f) {
	int i;
	Complex arr[N]; //array of structure complex numbers
	printf("Enter %d complex numbers:\n", N);
	for (i = 0; i < N; i++)
	{
		scanf("%f%f" ,&arr[i].r, &arr[i].i);// we recive from the user the complex number and we get the real and image part of the number
		fprintf(f, "%.1f %.1f %.1f\n", arr[i].r, arr[i].i, CRadius(arr[i])); //we write on the txt file the real part image part and the radius using the function Cradius.
	}
	

}

int CheckFile(FILE* f, float m) {
	int i, counter = 0;

	f = fopen("complex_number.txt", "rt");// we open the file in read only
	if (f == NULL) {
		Error_Msg("Error We couldn't open complex_number.txt "); //check if we succeeded to open the txt file.
		return 1;
	}

	fseek(f, 2 * sizeof(float), SEEK_SET); //using fseek function to put the pointer to the third float (first radius) 
		for(i=1;i<N;i++){
			float temp;
			temp = getc(f)-48.0; //when we use getc we recive the ASCII number of the digit and we decrease 48 to display as a number
		
			if(temp > m) counter++; //we count the radiuses that bigger then the recived "m"
			fseek(f, 2 * sizeof(float), SEEK_CUR); //using fseek function agian we jump 2 sizeof(float) bytes from the current posting to the next raduis
		}
		
		fclose(f);

		return counter;
	
	
}
