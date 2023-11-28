#include <stdio.h>
double fun(int num)
{
	if (num == 0 || num == 1)
	{
		return 1.0;
	}
	else
	{
		return num * fun(num - 1);
	}
}
int main()
{
	double sum = 1.0;
	int n, i;
	scanf_s("%d", &n);
	for (i = 1;i <= n;i++)
	{
		sum += 1.0 / fun(i);
	}
	printf("%.8lf", sum);
}