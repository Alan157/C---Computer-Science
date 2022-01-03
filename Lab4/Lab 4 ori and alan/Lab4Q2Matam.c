#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char course[4];
	char ID[5];
	char name[17];

}Student;

void Get_Lost(char*);
/*
Function name:Get_Lost
Input:char*
Output:void
Function Algorithm:prints a string and exits the program;
		*/
void Find(FILE*, char* course);
/*
Function name:Find
Input:file*,Char*
Output:void
Function Algorithm: find students from same course.
		*/

int main()
{
	char course[4];
	FILE* file;
	file = fopen("Stud.txt", "rt");
	if (file == NULL)
		Get_Lost("Cannot open file");

	printf("\nEnter the name of course,up to 3 letters:");
	scanf("%s", course);
	Find(file, course);
	fclose(file);
	return 0;


}


void Get_Lost(char* s)
{
	puts(s);
	exit(1);
}

void Find(FILE* f, char* course)
{
	char binary[17], filename[8]; //binary to save the binary number. filename to make a new file name according to the course name.
	FILE* out;
	Student temp;


	strcpy(filename, course); //we make a new string that combined with the course name and .txt
	strcat(filename, ".txt\0");

	out = fopen(filename, "wt"); //we open a new text to write only.
	if (out==NULL)
		Get_Lost("Cannot open output file");

	while (!feof(f)) //while we didnt reach EOF
	{
		fgets(temp.course, 4, f); //gets the COURSE name
		fgets(temp.ID, 5, f); //gets the ID 
		fgets(temp.name, 17, f); //gets the STUDENT name
		if (!strcmp(temp.course, course))
		{
			int num;
			num = atoi(temp.ID); // converts the string to a integer
			_itoa(num, binary, 2); //converts the integer number to a binary number
			fprintf(out, "%s, %s, %s\n", binary, temp.name, temp.course); //writes to the txt
		}
		
	}
	
	fclose(out);
}
