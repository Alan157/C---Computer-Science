#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Person
{
	char ID[10];
	char F_name[11];
	char L_name[16];
	int Age;
	char Addr[51];
}Person;

void Error_Msg(char*);
/*
Function name:Error_Msg
Input: string
Output: void
Function Algorithm: prints string using printf.
		*/
		

int main()
{
	Person temp;
	FILE* in, * out;
	in = fopen("the_first.txt", "rt"); // "r" is the default but we putted it anyway.
	if (in == NULL)
	{
		Error_Msg("Error we couldn't open the_first.txt, aborting"); //error msg if we failed to open the txt file.
		return 1;
	}

	out = fopen("the_second.txt", "wt"); // open to write only the_second file.
	if (out == NULL)
	{
		Error_Msg("Error we couldn't open the_second.txt, aborting"); //error msg if we failed to open the txt file.
		return 1;
	}
	// we read the information from the_first in the temp person to structure and then we write it .
	fscanf(in,"%s %s %s %d %s",temp.ID,temp.F_name,temp.L_name,&temp.Age,temp.Addr);
	fprintf(out,"ID:%s\nFull name:%s %s\nAge:%d\nAddress:%s",temp.ID, temp.F_name, temp.L_name,temp.Age, temp.Addr);

	fclose(in); // close the files.
	fclose(out);
	return 0;
}



void Error_Msg(char* msg)
{
	printf("\n%s", msg);
	exit(1);
}