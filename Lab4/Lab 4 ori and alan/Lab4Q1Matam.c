#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX 256
typedef struct
{
	char code[10];
	char* name;


}Book;

typedef struct
{
	char name[MAX];
	int num_books;
	Book* arr;


}Library;

void Get_Lost(char* str);
/*
Function name:Get_Lost
Input:char*
Output:void
Function Algorithm: prints a string and exits the program
		*/
void input_book(Book* B, FILE* in);
/*
Function name: input_book
Input: book*, file*
Output: void
Function Algorithm: reads from a txt file a book format
		*/
void input_library(Library* L, FILE* in);
/*
Function name:input_library
Input:library* , file*
Output:void
Function Algorithm: reads from a txt file a library format
		*/
void output_book(Book* B, FILE* out);
/*
Function name:output_book
Input:book*,file*
Output:void
Function Algorithm: write a book format to a txt file
		*/
void output_library(Library* L, FILE* out);
/*
Function name: output_library
Input: library*, file *
Output:void
Function Algorithm: write a library format to a txt file
		*/

int main()
{
	FILE* in, * out;
	Library Libr;
	int i;

	if (!(in= fopen("input.txt", "rt"))) 
		Get_Lost("The input file is wrong");

	input_library(&Libr, in);
	fclose(in);

	if (!(out = fopen("output.txt", "wt")))
		Get_Lost("The output file is wrong");

	output_library(&Libr, out);
	fclose(out);

	for (i = 0; i < Libr.num_books; i++) //free each book name that was dynamic allocated
		free(Libr.arr[i].name);
	free(Libr.arr); //free the whole book array in the library structure.

		return 0;
}


void Get_Lost(char* str)
{
	printf("\n%s", str);
	exit(1);
}



void input_book(Book* B, FILE* in) { 
	char tempname[MAX]; //this is a temp string to save the name to get the length to the dynamic allocation
	fscanf(in, "%s %s", B->code,tempname);
	
	B->name = (char*)malloc((strlen(tempname) + 1) * sizeof(char)); //memo allocate string in the structure name field
	if (B->name == NULL) {
		Get_Lost("Memo allocate failed");
	}
     strcpy(B->name,tempname); //copy the name to the name field in the book structure.
	
}

void input_library(Library* L, FILE* in) {
	int i;
	fscanf(in, "%s %d", L->name, &L->num_books);
	L->arr= (Book*)malloc((L->num_books) * sizeof(Book)); //memo allocate Book array in the structure book arr field
	if (L->arr == NULL) {
		Get_Lost("Memo allocate failed");
	}
	for (i = 0; i < L->num_books; i++) { //reads each book to the library area
		input_book(&L->arr[i], in);                  
	}
	
}

void output_book(Book* B, FILE* out) {
	fprintf(out, "%-10s %s\n", B->code, B->name); //%-10s for correct formatting 
}


void output_library(Library* L, FILE* out) {
	int i;

	fprintf(out, "%s\n", L->name);
	for (i = 0; i < L->num_books; i++){
		output_book(&L->arr[i], out); //call output_book to write each book from the library to the txt.

	}

}
