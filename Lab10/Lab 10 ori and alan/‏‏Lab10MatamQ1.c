#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double sum_square(int m, int n, float(*f)(int a)); //function that receive 2 integers and a pointer to a function that return float and receives 1 integer

float func1(int x);
float func2(int x);

int main() {
	printf("The sum of func2: %.5lf\n", sum_square(2, 13, func2));
	printf("The sum of func1: %.5lf\n", sum_square(1, 10000, func1));

	return 0;
}

float func1(int x) { return 1.0 / x; }
float func2(int x) { return x / 5.0; }

double sum_square(int m, int n, float(*f)(int a)) {
	
	double sum = 0; //the function return double
	float temp; //we use it to receive the float value from each function
	int i;

	for (i = m; i <= n; i++) {
		temp = f(i); //we send a number between m<=i<=n
		temp *= temp; //f^2
		sum += temp; 
	}
	
	return sum; 

}