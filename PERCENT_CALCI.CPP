#include <stdio.h>
//#include <conio.h>

int main()
{
	int h, e, m, s, t;
	float a;
	//clrscr();
	printf("Write your english marks out of 100: ");
	scanf("%d", &e);

	printf("Write your hindi marks: ");
	scanf("%d", &h);

	printf("Write your science marks: ");
	scanf("%d", &s);

	printf("Write your maths marks: ");
	scanf("%d", &m);

	t = h + e + s + m;
	printf("\nTotal marks out of 400 is %d", t);
	a = t/4;
	printf("\nTotal percentage is %.2f%% ", a);
	//getch();
	return 0;
}
