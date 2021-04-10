#include <iostream>
#include <stdio.h>  
#include <math.h>  


void dvoichsyst(int dec)
{
	int step;
	step = 128;
	printf("Binary code of a number: ");
	for (int i = 1; i <= 8; i++)
	{
		if (dec >= step)
		{
			printf("1");
			dec -= step;
		}
		else
			printf("0");

		step /= 2;
	}
	printf("\n");
}


void vivod(int dec)
{
	int i;
	i = dec >> 7 & 1;
	switch (i)
	{
	case 0:
	{
		printf("\nSex: Male\n");
		printf("\nAppearance:");
		i = dec >> 1 & 3;
		switch (i)
		{
		case 0:
		{
			printf("\nClothes Style: Sport");
			break;
		}
		case 1:
		{
			printf("\nClothes Style: Classic");
			break;
		}
		case 2:
		{
			printf("\nClothes Style: Business");
			break;
		}
		case 3:
		{
			printf("\nClothes Style: Hippie");
			break;
		}
		default:
		{
			break;
		}
		}

		i = dec >> 3 & 3;
		switch (i)
		{
		case 0:
		{
			printf("\nProfession: Plumber\n");
			break;
		}
		case 1:
		{
			printf("\nProfession: President\n");
			break;
		}
		case 2:
		{
			printf("\nProfession: Student\n");
			break;
		}
		case 3:
		{
			printf("\nProfession: Tutor\n");
			break;
		}
		default:
		{
			break;
		}
		}
		break;
	}

	case 1:
	{
		printf("\nSex: Female\n");
		printf("\nAppearance:");
		i = dec >> 1 & 1;
		switch (i)
		{
		case 0:
		{
			printf("\nMarried: No");
			break;
		}
		case 1:
		{
			printf("\nMarried: Yes");
			break;
		}
		}

		i = dec >> 2 & 3;
		switch (i)
		{
		case 0:
		{
			printf("\nClothes Style: Sport");
			break;
		}
		case 1:
		{
			printf("\nClothes Style: Classic");
			break;
		}
		case 2:
		{
			printf("\nClothes Style: Business");
			break;
		}
		case 3:
		{
			printf("\nClothes Style: Hippie");
			break;
		}
		}

		i = dec >> 4 & 1;
		switch (i)
		{
		case 0:
		{
			printf("\nHair Length: Short\n");
			break;
		}
		case 1:
		{
			printf("\nHair Length: Long\n");
			break;
		}
		default:
		{
			break;
		}
		}

	}
	}

	i = dec >> 5 & 3;
	switch (i)
	{
	case 0:
	{
		printf("\nAge: Child");
		break;
	}
	case 1:
	{
		printf("\nAge: Teenager");
		break;
	}
	case 2:
	{
		printf("\nAge: Adult");
		break;
	}
	case 3:
	{
		printf("\nAge: Senior");
		break;
	}

	}
}

void cs(int dec)
{
	int i, k=0;
	i = dec >> 0 & 1;
	if (k = i)
	{
		printf("\n\nCS: %d", i);
	}
	else
	{
		printf("\n\nCS: %d", i);
	}


	int func = 0;
	i = dec << 0 & 1;
	for (int j = 4; j >= 0; j--)
	{
		func = func ^ dec >> j & 1;
	}

	printf("\nFinal Control Sum with XOR method issue: %d", func);

	if (func == (i & 1))
	{
		printf("\nXOR: No corrupted bits found.");
	}
	else
	{
		printf("\nXOR: Bug. The integrity of the information is violated.");
	}
}

int main()
{
	unsigned char dec;
	printf("Enter a number: ");
	scanf_s("%hhu", &dec);
	int n = dec;
	dvoichsyst(n);
	vivod(n);
	cs(n);
	printf("\n\n\n");
}