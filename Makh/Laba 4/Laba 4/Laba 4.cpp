// Laba 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>

int dvo(int a)
{
	int bin = 0, j = 1;
	while (a)
	{
		bin += (a % 2) * j;
		j *= 10;
		a /= 2;
	}
	return bin;
}

int main()
{
	int a, b;
	scanf_s("%d", &a);
	b = dvo(a);
	printf("%d", b);
}