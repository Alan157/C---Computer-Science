#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char name[20];
	int grades[3];
}student;

void Error_Msg(char*);
/*
Function name:Error_Msg
Input:string
Output: void
Function Algorithm:prints a msg and exits the program
		*/
int InputData(student**, FILE*);
/*
Function name:InputData
Input: pointer to student array and pointer to the file.
Output: int.
Function Algorithm: returns the number of students.
		*/
void OutputData(int, student*, FILE*);
/*
Function name:OutputData
Input:int, pointer to a student structure and a pointer to a file.
Output: void
Function Algorithm: run over the file to check each student grades and keeps the highest between them.
		*/

int main()
{
	FILE* fp;
	student* arr;
	int size;
	if (!(fp = fopen("Students.txt", "rt")))
		Error_Msg("The input file is wrong");
	size = InputData(&arr, fp);
	fclose(fp);

	if (!(fp = fopen("Students.txt", "wt")))
		Error_Msg("The output file is wrong");
	OutputData(size, arr, fp);
	fclose(fp);
	free(arr);




	return 0;
}


int InputData(student** p_array, FILE* fp)
{
	student* arr;
	int i = 1;

	arr = (student*)malloc(sizeof(student));
	if (arr == NULL) {
		Error_Msg("No memory");
	}
	while (fscanf(fp, "%s %d %d %d", arr[i - 1].name, &arr[i - 1].grades[0], &arr[i - 1].grades[1], &arr[i - 1].grades[2]) != EOF)
	{
		arr = (student*)realloc(arr, (++i) * sizeof(student)); //reallocate new memo and one more spot.
		if (arr == NULL) { //check if memo allocation succeeded
			free(arr);
			Error_Msg("No memory");

		}
	}

	*p_array = arr;

	return i - 1;     /*return the number of students*/


}

void OutputData(int arr_size, student* arr, FILE* fp)
{
	int i, j;
	for (i = 0; i < arr_size; i++) { //for loop that runs all over the student structure array
		int tempmax = arr[i].grades[0];

		for (j = 1; j < 3; j++) { // here we run on each student grades to find the max
			if (arr[i].grades[j] > tempmax) tempmax = arr[i].grades[j];
		}
		fprintf(fp, "%s %d\n", arr[i].name, tempmax); //we write over the existed file the new grade (we keep the same name)

	}

}


void Error_Msg(char* msg)
{
	printf("\n%s", msg);
	exit(1);
}