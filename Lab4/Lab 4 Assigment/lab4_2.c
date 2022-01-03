#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Get_Lost(char *);
void Find(FILE *,char *course);

int main()
{
	char course[4];
	FILE *file;
	file = fopen("Stud.txt", "rt"); 
	if(file == NULL) 
          Get_Lost("Cannot open file");
	printf("\nEnter the name of course,up to 3 letters");
	scanf("%s",course);
	Find(file,course);
	fclose(file);
        return 0;
}


void Get_Lost(char *s)
{ 
   puts(s);  
   exit(1);
}