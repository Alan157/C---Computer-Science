#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

typedef struct {
	char* name;
	unsigned long ID;
	int grade;
	char flag; // Y == NEW PROG , N == OLD PROG
	char hw[6];
	char finalg;
}Student;

typedef struct {
	Student* arr;
	int num;
}Universitey;

void Error_Msg(char* str);
/*
Function name:Error_Msg
Input:string
Output:void
Function Algorithm:prints a string and exits.
		*/
	
int main() {
	FILE* in, * out;
	Universitey uni;
	Student temp, * tempbuffer;
	int i, counter, j, flag = 1;
	int option, option2 = NULL;
	char tempname[100];

	//Menu Instructions
	printf("Hello,\n Instructions-\n You have 6 options to choose:\n");
	printf("'1'-Reads the students data from the input file.\n");
	printf("'2'-Writes the students data to an output file.\n");
	printf("'3'-Calculates the final students grade.\n");
	printf("'4'-Shows the students statistical data.\n");
	printf("'5'-Shows the students 'Blacklist' (those who hasn't submitted at least three homework assignments).\n");
	printf("'6'-Closes the program.\n");
	printf("First of all you must choose option '1' first in order to proceed.\n\n");
	printf("Please choose your option:");
	rewind(stdin);
	scanf("%d", &option);

	//a loop to hold the user until he selects a for the first time
	while (option != 1 && option!=6) {
		printf("Error!!\n First of all you must choose option '1' first in order to proceed.\n Or option '6' to end the program\n");
		rewind(stdin); 
		printf("Please choose your option:");
		rewind(stdin);
		scanf("%d", &option);
	}


	


	if (option == 1) {
		//**~~~~~~~~~~~~option 1~~~~~~~~~~~~**
		uni.num = 1;
		uni.arr = NULL;
		if (!(in = fopen("input.txt", "r")))Error_Msg("The input file is wrong");
		while (fscanf(in, "%s %lu %d %s %c", tempname, &temp.ID, &temp.grade, temp.hw, &temp.flag) != EOF) {

			tempbuffer = uni.arr; //to save the adress of the prev memo allocation (to free incase realloc fail)

			uni.arr = (Student*)realloc(uni.arr, (uni.num * sizeof(Student)));

			if (uni.arr == NULL)
			{
				for (i = 0; i < uni.num - 1; i++)
					free(uni.arr[i].name); //free the memo allocated name

				free(tempbuffer); //the whole students array
				Error_Msg("Memo allocation failed! aborting");
			}

			if ((uni.arr[uni.num - 1].name = (char*)malloc((strlen(tempname) + 1) * sizeof(char))) == NULL) { //dynamic allocate the name
				free(uni.arr);
				Error_Msg("Memo allocation failed! aborting");
			}
			strcpy(uni.arr[uni.num - 1].name, tempname);


			uni.arr[uni.num - 1].ID = temp.ID;


			uni.arr[uni.num - 1].grade = temp.grade;


			temp.hw[5] = NULL;
			strcpy(uni.arr[uni.num - 1].hw, temp.hw);

			uni.arr[uni.num - 1].flag = temp.flag;

			uni.num++; //student-1 counter
		}

		fclose(in);
	
		//calculate if the final binary grade is 1 or 0 		
		for (i = 0; i < uni.num - 1; i++)
		{
			counter = 0;

			for (j = 0; j < 5; j++)
				if (uni.arr[i].hw[j] == '1') counter++;

			if (counter > 2) uni.arr[i].finalg = '1';
			else uni.arr[i].finalg = '0';

		}
	}

	if (!(out = fopen("output.txt", "w")))Error_Msg("The output file is wrong");
	
	while (option != 6) {

		//**~~~~~~~~~~~~option 2~~~~~~~~~~~~**
		if (option == 2) {

			fprintf(out, "\nOption: 2 \n\n");

			for (i = 0; i < uni.num - 1; i++) {
				fprintf(out, "Student %d: ", i + 1);
				fprintf(out, "%s %lu %d %c %c \n", uni.arr[i].name, uni.arr[i].ID, uni.arr[i].grade, uni.arr[i].finalg, uni.arr[i].flag);
			}

		
			flag = 1;

		}


		//**~~~~~~~~~~~~option 3~~~~~~~~~~~~**
		if (option == 3) {

			int* finalarr;
			fprintf(out, "\nOption: 3 \n\n");
			fprintf(out, "BEFORE:\n");



			for (i = 0; i < uni.num - 1; i++) {
				fprintf(out, "Student %d: ", i + 1);
				fprintf(out, "%s %lu %d %c %c \n", uni.arr[i].name, uni.arr[i].ID, uni.arr[i].grade, uni.arr[i].finalg, uni.arr[i].flag);
			}



			fprintf(out, "\nAFTER:\n");
			if ((finalarr = (int*)malloc(sizeof(int) * uni.num)) == NULL) //a dynamic allocated array to a save the final grades calc
			{
				
			for (i = 0; i < uni.num - 1; i++)
				free(uni.arr[i].name);

					free(uni.arr);
					Error_Msg("Memo allocation failed! aborting");
				
			}

			for (i = 0; i < uni.num-1; i++)
			{
				//to check if the student is eligible to receive the lab grade bonus
				if (uni.arr[i].finalg=='1'&& uni.arr[i].grade >= 55)
				{
					if(uni.arr[i].flag == 'Y')
						finalarr[i] = (double)uni.arr[i].grade * 0.80 + 20;
					else if(uni.arr[i].flag == 'N')
						finalarr[i] = (double)uni.arr[i].grade * 0.90 + 10;
				}
				
				else
				{
					finalarr[i] = uni.arr[i].grade;
				}
				
				
			}


			for (i = 0; i < uni.num - 1; i++) {
				fprintf(out, "Student %d: ", i + 1);
				fprintf(out, "%s %lu %d %c final: %d \n", uni.arr[i].name, uni.arr[i].ID, uni.arr[i].grade, uni.arr[i].finalg,finalarr[i]);
				
			}

		
			free(finalarr);
			flag = 1;

		}

		
		//**~~~~~~~~~~~~option 4~~~~~~~~~~~~**
		if (option == 4) {

			char prog = 'z';
			float sum = 0, avg, sd;
			int max, min, counter=0;

			printf("For which program? (Y/N) :");
			rewind(stdin);
			scanf("%c", &prog);
			

				fprintf(out, "\nOption: 4 \n\n");

				//avg calc
				for (i = 0; i < uni.num - 1; i++)
				{
					if (uni.arr[i].flag == prog) {
						sum += (float)uni.arr[i].grade;
						counter++; // only need to count once since the number of students won't change.
					}
				}

				avg = (sum / (float)(counter));

				sum = 0;
				//Standard Deviation calc
				for (i = 0; i < uni.num - 1; i++)
				{
					if (uni.arr[i].flag == prog)
						sum += pow((uni.arr[i].grade - avg), 2);
				} // no need to count again

				sum /= (float)(counter);
				sum = sqrt(sum);
				sd = sum;

				//calc min
				//finding the first student that is included in the chosen option(Y/N) and setting it as min
				for (i = 1; i < uni.num - 1; i++)
				{
					if (uni.arr[i].flag == prog)
					{
						min = uni.arr[i].grade;
						break;
					}
				}
				for (i = 1; i < uni.num - 1; i++)
				{
					if (uni.arr[i].flag == prog)
						if (uni.arr[i].grade < min)
							min = uni.arr[i].grade;
				}


				// calc max
				//finding the first student that is included in the chosen option(Y/N) and setting it as max
				for (i = 1; i < uni.num - 1; i++)
				{
					if (uni.arr[i].flag == prog)
					{
						max = uni.arr[i].grade;
						break;
					}
				}
				for (i = 1; i < uni.num - 1; i++)
				{
					if (uni.arr[i].flag == prog)
						if (uni.arr[i].grade > max)
							max = uni.arr[i].grade;
				}

				fprintf(out, "Exam average grades for %c program: %.2f\nStandard Deviation is: %.2f\nNumber of students: %d\nRange,%d-%d\nNumber of students who study in program %c : %d \n", prog, avg, sd, uni.num - 1, max, min, prog, counter);





				flag = 1;
			
		}

		
		//**~~~~~~~~~~~~option 5~~~~~~~~~~~~**
		if (option == 6) {
			
			fprintf(out, "\nOption: 5 \n\n");
			fprintf(out, "Blacklisted Students:\n");
			for (i = 0; i < uni.num - 1; i++)
			{
	
				if (uni.arr[i].finalg == '0') //0 meants that student is in the black list
				{
					fprintf(out, "%s %lu\n", uni.arr[i].name, uni.arr[i].ID);
				}
			}
			

			
			flag = 1;

		}

		



		//error case 
		if (flag == 0 && ( option < 2 || option > 6)) printf("You have chosen a wrong option! Error!\n\n");
		flag = 0;
		printf("Please choose your option:");
		rewind(stdin);
		scanf("%d", &option);

	}



	//**~~~~~~~~~~~~option 6~~~~~~~~~~~~**
	fprintf(out, "\nOption: 6 \n\n");
	fprintf(out,"\nEnd Of Program!");

	fclose(out);
	return 0;


}



void Error_Msg(char* str)
{
	printf("\n%s", str);
	exit(1);
}