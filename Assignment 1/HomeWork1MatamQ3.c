#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Clock
{
	int hour, minute;
} clock_t;

void print_time(int);
int main()
{
	clock_t c;
	int a_minutes = 0;
	printf("Enter time and minutes to add: ");
	scanf("%d %d %d",&c.hour,&c.minute,&a_minutes);

	printf("\nThe time is : ");
	print_time(c.hour);
	printf(":");
	print_time(c.minute);

	c.minute = c.minute + a_minutes;
	while (c.minute > 60)
	{
		c.minute -= 60;
		c.hour += 1;
	}

	

	printf("\nThe new time is: ");
	print_time(c.hour);
	printf(":");
	print_time(c.minute);




}
void print_time(int n)
{
	if (n <= 9)
		printf("0%d", n);
	else
		printf("%d", n);
}