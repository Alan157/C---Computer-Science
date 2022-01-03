#include "Lab11Header.h"

//implementation of the private functions
void free_char(void* elem) //function to free element
{
	free(elem);
}


int main() {
	PSTACKNODE stack = NULL; 
	char key,*c;
	puts("Enter characters, separated by space. Press enter to stop\n");
	do
	{
		key = getchar();
		_flushall();
		c = (char*)malloc(sizeof(char));
		*c = key;
		push(c, &stack);
	} while (key != '\n');

	puts("Here are the characters in reverse order:\n");

	while (!isempty(stack))
	{
	      
		printf("%c", *(char*)top(stack)); //casting to receive the specific data type
		pop(&stack,free_char); //we send a pointer to the function
	}

	return 0;
}