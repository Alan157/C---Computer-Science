#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Error_Msg(char* str);
/*
Function name:Error_Msg
Input:string
Output:void
Function Algorithm: exits and display string.
		*/

int main()
{
	FILE* in, * out;
	char tempstr[17]; //each student information is stored in a 16 letters string 6for name 4for Section and 6 for 2 grades.
	char TargtedSection[5] = "Comp";
	

	if (!(in = fopen("Students.txt", "r")))Error_Msg("The input file is wrong");
	if (!(out = fopen("StudentsNew.txt", "w")))Error_Msg("The output file is wrong");

	while (fgets(tempstr,17,in)!=NULL ) { //we read each time 16 letters

		char tempSection[5]; //this is to temporary save the section name

		strncpy(tempSection, tempstr + 6, 4); //here we copy the section name of each student
		tempSection[4] = '\0';


		if (!strcmp(TargtedSection, tempSection)) //we compare if the student is in the targeted section. 
		{
			char tempName[7], tempGrade1[4], tempGrade2[4];
			float avg = 0;

			//here we take the student name and his 2 grades into a temp strings

			strncpy(tempName, tempstr, 6);
			tempName[6] = '\0';

			strncpy(tempGrade1, tempstr+10, 3);
			tempGrade1[3] = '\0';

			strncpy(tempGrade2, tempstr+13, 3);
			tempGrade2[3] = '\0';

			avg = (atoi(tempGrade1) + atoi(tempGrade2)) / 2.0; //we calc his avg

			fprintf(out, "%s %.2f\n", tempName,avg); //we write onto the output file.
		}
	}
		

	fclose(in);
	fclose(out);

	return 0;
}


void Error_Msg(char* str)
{
	printf("\n%s", str);
	exit(1);
}




