#include <stdio.h>
#include <math.h>
#include <windows.h>

/*Харламов К.Д. 
Вариант 1*/

int func(int trsl[], int count);
int func2(int trsl[], int count);

int main() {
	char ascii[10] = { '0','1','2','3','4','5','6','7','8','9' };
	unsigned char input[3];
	int trsl[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int count = 0, check = 0, binary = 0;
	int layer = 0, type = 0, bitrate = 0, cs = 0;
	printf("Write value in range of [0;255]:\n");
	scanf_s("%3c", input);
	if (input[2] == '\n' && input[1]!='\n') {
		input[2] = input[1];
		input[1] = input[0];
		input[0] = '0';
	}
	else if(input[1] == '\n'){
		input[2] = input[0];
		input[1] = '0';
		input[0] = '0';
	}
	while (check != 1) {
		if (input[0] == ascii[count]) {
			binary = trsl[count] * 100;
			check = 1;
			break;
		}
		count++;
	}
	count = 0;
	check = 0;
	while (check != 1) {
		if (input[1] == ascii[count]) {
			binary = binary + trsl[count] * 10;
			check = 1;
			break;
		}
		count++;
	}
	check = 0;
	count = 0;
	while (check != 1) {
		if (input[2] == ascii[count]) {
			binary = binary + trsl[count];
			check = 1;
			break;
		}
		count++;
	}
	check = 0;
	count = 0;

	while (check != 8) {
		if (count == 0) {
			if (trunc(binary / (128 / pow(2, check))) == 1) {
				count = binary % (int)(128 / pow(2, check));
				trsl[check] = 1;
				check++;
			}
			else {
				trsl[check] = 0;
				check++;
			}
		}
		else {
			if (trunc(count / (128 / pow(2, check))) == 1) {
				count = count % (int)(128 / pow(2, check)); 
				trsl[check] = 1;
				check++;
			}
			else {
				trsl[check] = 0;
				check++;
			}
		}

	}
	printf("Value in binary format: ");
	for (int e = 0; e < 8; e++) {
		printf("%d", trsl[e]);
	}
	//layers
	for (int i = 0; i < 2; i++) {
		switch (trsl[i]) {
		case 0: {
			if (trsl[i + 1] !=1 && i != 1) {
				layer = 0;
				printf("\nLayer: Layer I\n");
				i = 2;
				break;
			}
			else {
				layer = 1;
				printf("\nLayer: Layer II\n");
				i = 2;
				break;
			}
		}
		case 1: {
			if (trsl[i + 1] == 1 && i != 1) {
				layer = 3;
				printf("\nLayer: Reversed layer\n");
				i = 2;
				break;
			}
			else if (trsl[i + 1] == 0 && i != 1) {
				layer = 2;
				printf("\nLayer: Layer III\n");
				i = 2;
				break;
			}
		}
		}
	}
	//type
	if (trsl[2] == 0) {
	printf("Type - CBR\n");
	printf("Bitrate info:\n");
	if (trsl[3] == 0) printf("Mode - mono\n");
	else printf("Mode - stereo\n");
	if (func2(trsl, 4) == 0) printf("Bitrate - 32 kbps");
	if (func2(trsl, 4) == 1) printf("Bitrate - 48 kbps");
	if (func2(trsl, 4) == 2) printf("Bitrate - 64 kbps");
	if (func2(trsl, 4) == 3) printf("Bitrate - 96 kbps");
	if (func2(trsl, 4) == 4) printf("Bitrate - 128 kbps");
	if (func2(trsl, 4) == 5) printf("Bitrate - 192 kbps");
	if (func2(trsl, 4) == 6) printf("Bitrate - 256 kbps");
	if (func2(trsl, 4) == 7) printf("Bitrate - 320 kbps");
}
	else {
		printf("Type - VBR\n");
		if (func(trsl, 3) == 0) printf("Range: 32-48 kbps\n");
		if (func(trsl, 3) == 1) printf("Range: 64-96 kbps\n");
		if (func(trsl, 3) == 2) printf("Range: 128-192 kbps\n");
		if (func(trsl, 3) == 3) printf("Range: 256-320  kbps\n");
		if (func(trsl, 5) == 0) printf("Mode: stereo\n");
		if (func(trsl, 5) == 1) printf("Mode: joint stereo\n");
		if (func(trsl, 5) == 2) printf("Mode: dual channel\n");
		if (func(trsl, 5) == 3) printf("Mode: sigle channel\n");
		}

	}

	int func(int trsl[], int count) {
		switch (trsl[count]) {
		case 0: {
			if (trsl[count + 1] == 0) return 0; 
			else return 1; 
			}
		case 1: {
			if (trsl[count + 1] == 0) return 2; 
			else return 3; 
			}
		}
	}

	int func2(int trsl[], int count) {
		switch (trsl[count]) {
		case 0: {
			if (trsl[count+1] == 0) {
				if (trsl[count + 2] == 0) return 0;
				else return 1;
			}
			else if (trsl[count+1] == 1) {
				if (trsl[count + 2] == 0) return 2;
				else return 3;
			}
		}
		case 1: {
			if (trsl[count + 1] == 0) {
				if (trsl[count + 2] == 0) return 4;
				else return 5;
			}
			else if (trsl[count + 1] == 1) {
				if (trsl[count + 2] == 0) return 6;
				else return 7;
			}
		}
		}
	}
	


