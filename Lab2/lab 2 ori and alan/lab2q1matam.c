#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

typedef struct //struct for point (two coordinates)
{
	double x, y;
}point;

typedef struct //struct for circle point and radius
{
	point center;
	double radius;
}circle;

int is_incircle(point p, circle c);
/*
Function name: is_incircle
Input: point and circle
Output: true - if the point in the circle or on the circle
		false - if the point is outside the circle.
Function Algorithm: Check if a point is within the circle range.
		*/
int main()
{
	point t;
	circle p;
	printf("Enter the coordinates of your point:");
	scanf("%lf %lf", &t.x, &t.y);
	printf("\nEnter the radius and the center of your circle:");
	scanf("%lf %lf %lf",&p.radius, &p.center.x, &p.center.y);

	is_incircle(t, p) ? printf("\nThe point is included in the circle") : printf("\nThe point is not included in the circle");

	return 0;
}

int is_incircle(point p, circle c) {
	double d1 = sqrt(pow((p.x - c.center.x), 2) + pow((p.y - c.center.y), 2)); // d1 is the distance of the point from the center of the circle if its bigger then the radius its means its not within the range.

	if (d1 <= c.radius) return 1;
	return 0;
}