﻿#include <stdio.h>

int ssa(unsigned char x)

{

	int i;

	unsigned char bin;

	for (i = 7; i >= 0; i--)

	{

		bin = (x >> i) & 1;

		printf("%d", bin);

	}

	printf("\n");

	return 0;

}

int decd(unsigned char a)

{

	int x, x1 = 0;

	for (int i = 4;i >= 1;i--) 

	{

		x1 = x1 ^ a >> i & 1;

	}

	x = a >> 0 & 1;

	printf("Data accuracy:\n");

	

		if (x1 == x)

		{

			printf(" True\n");

		}

		else

		{

			printf(" False\n");

		}

	x = a >> 6 & 3;

	printf("Layer:\n");

	switch (x)

	{

	case 0:

		printf(" Layer 1\n");

		break;

	case 1:

		printf(" Layer 2\n");

		break;

	case 2:

		printf(" Layer 3\n");

		break;

	case 3:

		printf(" Reserved\n");

		break;

	default:

		break;

	}

	x = a >> 5 & 1;

	printf("Type:\n");

	switch (x)

	{

	case 0:

		printf(" Constant Bitrate (CBR)\n");

		printf("Mode:\n");

		x = a >> 4 & 1;

		switch (x)

		{

		case 0:

			printf(" Mono\n");

			break;

		case 1:

			printf(" Stereo\n");

			break;

		default:

			break;

		}

		printf("Bitrate:\n");

		x = a >> 1 & 7;

		switch (x)

		{

		case 0:

			printf(" 32kpbs\n");

			break;

		case 1:

			printf(" 48kpbs\n");

			break;

		case 2:

			printf(" 64kpbs\n");

			break;

		case 3:

			printf(" 96kpbs\n");

			break;

		case 4:

			printf(" 128kpbs\n");

			break;

		case 5:

			printf(" 192kpbs\n");

			break;

		case 6:

			printf(" 256kpbs\n");

			break;

		case 7:

			printf(" 320kpbs\n");

			break;

		default:

			break;

		}

		break;

	case 1:

		printf(" Variable Bitrate (VBR)\n");

		printf("Range:\n");

		x = a >> 3 & 3;

		switch (x)

		{

		case 0:

			printf(" 32-48kbps\n");

			break;

		case 1:

			printf(" 64-96kbps\n");

			break;

		case 2:

			printf(" 128-192kbps\n");

			break;

		case 3:

			printf(" 256-320kbps\n");

			break;

		default:

			break;

		}

		printf("Mode:\n");

		x = a >> 1 & 3;

		switch (x)

		{

		case 0:

			printf(" Stereo\n");

			break;

		case 1:

			printf(" Joint stereo\n");

			break;

		case 2:

			printf(" Dual channel\n");

			break;

		case 3:

			printf(" Single channel\n");

			break;

		default:

			break;

		}

		break;

	default:

		break;

	}

	return 0;

}

int main()

{

	unsigned char p;

	scanf_s("%hhu", &p);

	ssa(p);

	decd(p);

}
