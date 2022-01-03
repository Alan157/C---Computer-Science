#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stud //structure for student
{
	char* name;
	int marks[4];
	float avg;
}student;


student* Create_Class(int size);
/*
Function Name: Create_Class
Input : int (size)
Output : student structure array
Function Algorithm: builds a structure student array in length of "size", receives students name, marks and calls another function to update the average, uses for loops and memo dynamic allocation.
*/
void Avg_Mark(student* s);
/*
Function Name: Avg_Mark
Input : Pointer to a student
Output : void
Function Algorithm: Update the student average
*/
void Print_One(student* s);
/*
Function Name: Print_One
Input : Pointer to a student
Output : void
Function Algorithm: prints student name and is average 
*/

int main()
{
	int size, i;
	student* arr;
	printf("\nEnter the number of students:");
	scanf("%d", &size);
	
	arr = Create_Class(size); //receives students structure array

	for (i = 0; i < size; i++) { //check if the students avg is greater then 85, if it is prints the name and avg using print_one function.
		if (arr[i].avg > 85)
			Print_One(arr + i);
	}


	return 0;


}

student* Create_Class(int size)
{
	student* class; 
	int i,j;

	class = (student*)malloc(size * sizeof(student)); //dynamic memo allocation for a student structure array.
	if (class == NULL) { //checks if memo allocation failed.
		printf("memo allocation failed");
		getch();
		exit(1); //if failed exits.
	}

	for (i = 0; i < size; i++)
	{
		char tempname[50] = ""; // temp name size of 50 , as asked in question description 

		printf("\nEnter your name:");
		scanf("%s", tempname); 

		class[i].name = (char*)malloc((strlen(tempname) + 1) * sizeof(char)); //memo allocate string in the structure name field
		if (class[i].name == NULL) {
			printf("memo allocation failed"); //check if memo allocation failed
			getch();

			for (j = 0; j < i; j++) //if failed we need to free all the memo allocated until this point starting from the memo of the strings names in the structure array.
				free(class[j].name);

					free(class); //free the structure array
			exit(1);
		}

		strcpy(class[i].name, tempname); //using strcpy to put the temp name inside the memo allocated string of the i placed student.

		printf("\nEnter your marks:"); //receives the marks from the user.
		for (j = 0; j < 4; j++)
			scanf("%d", &class[i].marks[j]);
			
		 Avg_Mark(class+i); //update the avg of the certain student.
		
	}
	return class; //return the array.
}


void Avg_Mark(student* s)
{
	int j;
	float sum = 0;
	for (j = 0; j < 4; j++)
		sum += s->marks[j];

	s->avg = sum / 4.0; //put the calculated sum inside the certain student avg field.
}


void Print_One(student* s)
{
	printf("\nThe average of %s is %.1f", s->name, s->avg); //prints the name field and the avg field of the certain student structure.
}

