#include <stdio.h>
#include <math.h>

//Var - 1

int main() {
	unsigned char input = 0;
	int count = 0, iter = 0, binary = 0;
	int layer = 0, transl = 0;
	printf("Write value in range of [0;255]:\n");
	scanf_s("%d", &binary);
	if (binary > 255 || binary < 0) {
		printf("Write correct value!");
		return 1;
	}
	input = binary;
	printf("Value in binary format: ");
	for (int i = 7; i >= 0; i--) {
		transl = input >> i;
		transl = transl & 1;
		printf("%d", transl);
	}
	//layers
	transl = input >> 6;
	transl = transl & 3;
	switch (transl) {
	case 0:{
		printf("\nLayer: Layer I\n");
		break;
	}
	case 1: {
		printf("\nLayer: Layer II\n");
		break;
	}
	case 2: {
		printf("\nLayer: Layer III\n");
		break;
	}
	case 3: {
		printf("\nLayer: Reversed layer\n");
		break;
	}
	default: break;
	}
	transl = input; 
	//type
	transl = transl << 2; 
	transl = transl >> 7;
	transl = transl & 1; 
	iter = transl; //type for CS
	if (transl == 1) {
		transl = binary;
		printf("Type - VBR\n");
		transl = transl << 3; //bitrate info
		transl = transl >> 4;
		transl = transl & 15;
		//range
		transl = transl >> 2;
		if (transl == 0) printf("Range: 32-48 kbps\n");
		if (transl == 1) printf("Range: 64-96 kbps\n");
		if (transl == 2) printf("Range: 128-192 kbps\n");
		if (transl == 3) printf("Range: 256-320  kbps\n");
		//mode
		transl = binary;
		transl = transl << 5;
		transl = transl >> 6;
		transl = transl & 0x3;
		if (transl == 0) printf("Mode: stereo\n");
		if (transl == 1) printf("Mode: joint stereo\n");
		if (transl == 2) printf("Mode: dual channel\n");
		if (transl == 3) printf("Mode: sigle channel\n");
	}
	else {
		printf("Type - CBR\n");
		//mode
		transl = binary;
		transl = transl << 3;
		transl = transl >> 7;
		transl = transl & 1;
		if (transl == 0) printf("Mode: mono\n");
		if (transl == 1) printf("Mode: stereo\n");
		//Bitrate info
		transl = binary;
		transl = transl << 4;
		transl = transl >> 5;
		transl = transl & 0x7;
		for (int e = 0; e < 8; e++) {
			if (transl == e) {
				if (e < 3) transl = 32 + e * 16;
				else if (e >= 3 && e < 5) transl = e * 32;
				else transl = 64 * e - 32 * (e - (trunc(e / 2) - 1)); 
				printf("Bitrate - %d kbps\n", transl);
				break;
			}
		}
	}
	//CS
	count = binary;
	if (iter == 0) { //type - CBR
		count = (count >> 4) & 1; 
		for (int i = 3; i > 0; i--) {
			transl = binary >> i;
			transl = transl & 1;
			count = count ^ transl;
		}
	}
	else { //type - VBR
		count = (count >> 4) & 1;
		for (int i = 3; i > 0; i--) {
			transl = binary >> i;
			transl = transl & 1;
			count = count ^ transl;
		}
	}
	if (count == 1) printf("CS: OK\nInformation trusferred succefully!");
	else printf("CS: ERROR\nResend data!");
	}
	 