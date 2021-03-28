#include "my.h"
int tretiybit(unsigned char x)
{
	int y;
	y = (x & 1);
	return y;
}
int dvoichncod(unsigned char x)
{
	unsigned char a[8];
	unsigned char b[8];
	for (int i = 7; i >= 0; i--)
	{
		a[i] = x % 2;
		x = x / 2;
	}
	for (int i = 0; i < 8; i++)
	{
		b[i] = a[i];
	}
	int r = 0;
	for (int i = 0; i < 8; i++) r = r * 10 + b[i];
	return r;
}
int Nullbit(unsigned char x)
{
	int y;
	y = (x & 1);
	return y;
}
int Sex(unsigned char x)
{
	int y;
	y = ((x & 128) >> 7);
	return y;
}
int Age(unsigned char x)
{
	int y;
	y = ((x & 96) >> 5);
	return y;
}
//Функции для male:
int Profession(unsigned char x)
{
	int y;
	y = ((x & 24) >> 3);
	return y;
}
int Clothes_style(unsigned char x)
{
	int y;
	y = ((x & 6) >> 1);
	return y;
}
//Функции для female:
int Hair_Length(unsigned char x)
{
	int y;
	y = ((x & 16) >> 4);
	return y;
}
int Clothes_style_female(unsigned char x)
{
	int y;
	y = ((x & 12) >> 2);
	return y;
}
int Married(unsigned char x)
{
	int y;
	y = ((x & 2) >> 1);
	return y;
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	unsigned char cs = 0;
	unsigned char sc = 0;
	int x = 0;
	int q, j, c, o, p, u, r, k, i, l, n;
	printf("Введите число от 0 до 255: ");
	scanf_s("%d", &x);
	if ((x <= 255) && (x >= 0))
	{
		c = x;
	}	
	else
	{
		printf("Неверно введено число\n");
		return 0;
	}
		
	sc = Nullbit(x);
	j = dvoichncod(c);//перевод в двоичный код.
	printf("Результат: ");
	printf("%d\n", j);
	q = Sex(x);//пол.
	printf("Sex: ");
	if (q == 0) 
	{
		printf("male\n"); o = 0; 
	}
	else 
	{
		printf("female\n"); o = 1; 
	}
	p = Age(x);//возраст.
	printf("Age: ");
	if (p == 0) printf("child\n");
	if (p == 1) printf("teenager\n");
	if (p == 2) printf("adult\n");
	if (p == 3) printf("senior\n");
	if (o == 0)//для male
	{
		u = Profession(x);
		printf("Profession: ");
		if (u == 0) printf("Plumber\n");
		if (u == 1) printf("President\n");
		if (u == 2) printf("Student\n");
		if (u == 3) printf("Tutor\n");
		r = Clothes_style(x);
		printf("Clothes style: ");
		if (r == 0) { printf("sport\n"); }
		if (r == 1) { printf("classic\n"); }
		if (r == 2) { printf("business\n"); }
		if (r == 3) { printf("hippie\n"); }
	}
	else//для female
	{
		k = Hair_Length(x);
		printf("Hair Length: ");
		if (k == 0)
		{ 
			printf("short\n");
		}
		else
		{
			printf("long\n");
		}
		i = Clothes_style_female(x);
		printf("Clothes style: ");
		if (i == 0) printf("sport\n");
		if (i == 1) printf("classic\n");
		if (i == 2) printf("business\n");
		if (i == 3) printf("hippie\n");
		l = Married(x);
		printf("Married: ");
		if (l == 0) 
		{
			printf("no\n");
		}
		else 
		{
			printf("yes\n"); 
		}
	}
	
	cs = 0;
	for (int f = 5; f <= 7; f++)//Контрольная сумма для age и sex.
	{
		n = ((x & (1 << f)) >> f);
		cs = cs ^ n;
	}
	if (sc == cs)
	{
		printf("Потерь нет.");
	}
	else
	{
		printf("Имеются потери, внимание!!!");
	}
}