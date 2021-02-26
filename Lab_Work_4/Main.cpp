#include <stdio.h>
#include <math.h>
#include <windows.h>

/*Харламов К.Д. 
Вариант 1*/

int DecodeSmallValue(int trsl[], int count);
int DecodingBigValue(int trsl[], int count);
int bitrate(int binar);

int main() {
	char ascii[10] = { '0','1','2','3','4','5','6','7','8','9' };
	unsigned char input[3];
	int trsl[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int count = 0, iter = 0, binary = 0;
	int layer = 0, cs = 0;
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
	for (count; count < 10; count++) {
		if (input[0] == ascii[count]) {
			binary = trsl[count] * 100;
			break;
		}
	}
	count = 0;
	for(count; count<10;count++) {
		if (input[1] == ascii[count]) {
			binary = binary + trsl[count] * 10;
			break;
		}
	}
	count = 0;
	for(count; count < 10; count++) {
		if (input[2] == ascii[count]) {
			binary = binary + trsl[count];
			break;
		}
	}
	count = 0;

	for (iter; iter < 8; iter++) { //заменить на for
		if (count == 0) {
			if (trunc(binary / (128 / pow(2, iter))) == 1) {
				count = binary % (int)(128 / pow(2, iter)); //сам перевод числа в двоичный формат
				trsl[iter] = 1;
			}
			else {
				trsl[iter] = 0;
			}
		}
		else {
			if (trunc(count / (128 / pow(2, iter))) == 1) {
				count = count % (int)(128 / pow(2, iter)); 
				trsl[iter] = 1;
			}
			else {
				trsl[iter] = 0;
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
	/*for (int i = 0; i < 8; i++) {
		binary = trunc(binary / (128 / pow(2, i)));
		printf("%d", binary);
	}*/
	//type
	
	bitrate(binary);
	
	/*if (trsl[2] == 0) {
	printf("Type - CBR\n");
	printf("Bitrate info:\n");
	//переделать bitrate через маски
	if (trsl[3] == 0) printf("Mode - mono\n");
	else printf("Mode - stereo\n");
	if (DecodingBigValue(trsl, 4) == 0) printf("Bitrate - 32 kbps");
	if (DecodingBigValue(trsl, 4) == 1) printf("Bitrate - 48 kbps");
	if (DecodingBigValue(trsl, 4) == 2) printf("Bitrate - 64 kbps");
	if (DecodingBigValue(trsl, 4) == 3) printf("Bitrate - 96 kbps");
	if (DecodingBigValue(trsl, 4) == 4) printf("Bitrate - 128 kbps");
	if (DecodingBigValue(trsl, 4) == 5) printf("Bitrate - 192 kbps");
	if (DecodingBigValue(trsl, 4) == 6) printf("Bitrate - 256 kbps");
	if (DecodingBigValue(trsl, 4) == 7) printf("Bitrate - 320 kbps");
}
	else {
		printf("Type - VBR\n");
		if (DecodeSmallValue(trsl, 3) == 0) printf("Range: 32-48 kbps\n");
		if (DecodeSmallValue(trsl, 3) == 1) printf("Range: 64-96 kbps\n");
		if (DecodeSmallValue(trsl, 3) == 2) printf("Range: 128-192 kbps\n");
		if (DecodeSmallValue(trsl, 3) == 3) printf("Range: 256-320  kbps\n");
		if (DecodeSmallValue(trsl, 5) == 0) printf("Mode: stereo\n");
		if (DecodeSmallValue(trsl, 5) == 1) printf("Mode: joint stereo\n");
		if (DecodeSmallValue(trsl, 5) == 2) printf("Mode: dual channel\n");
		if (DecodeSmallValue(trsl, 5) == 3) printf("Mode: sigle channel\n");
		}*/

	}

	int DecodeSmallValue(int trsl[], int count) {
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

	int DecodingBigValue(int trsl[], int count) {
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
	 
	int bitrate(int binar){
			int transl = 0; // 7 - 111
			//Bitrate mode
			int mode = binar;
			transl = binar << 3;
			transl = binar >> 7;
			if (transl == 1) {
				printf("Type - VBR\n");
				binar = binar << 3;
				binar = binar >> 4;
				//range
				binar = binar >> 2;
				transl = binar & 0x3;
					if(transl==0) printf("Range: 32-48 kbps\n");
					if(transl==1) printf("Range: 64-96 kbps\n");
					if(transl==2) printf("Range: 128-192 kbps\n");
					if(transl==3) printf("Range: 256-320  kbps\n");
				//mode
					mode = mode << 5;
					mode = mode >> 6;
					transl = mode & 0x3;
					if (transl == 0) printf("Mode: stereo\n");
					if (transl == 1) printf("Mode: joint stereo\n");
					if (transl == 2) printf("Mode: dual channel\n");
					if (transl == 3) printf("Mode: sigle channel\n");
			}
			else {
				printf("Type - CBR\n");
				binar = binar << 4;
				binar = binar >> 5;
				transl = binar & 0x7;
				//Вывод bitrate 
				for (int e = 0; e < 8; e++) {
					if (transl == e) {
						if (e < 3) transl = 32 + e * 16;
						else if (e >= 3 && e < 5) transl = e * 32;
						else transl = 64 * e - 32 * (e - (trunc(e / 2) - 1)); //дотестить на числах 6 и 7
						printf("Bitrate - %d kbps", transl);
						break;
					}
				}
			}
			return 0;
		}

	/*
	52
		Value in binary format : 00110100
		Layer : Layer I
		Type - VBR
		Range : 128 - 192 kbps
		Mode : dual channel

		250
Value in binary format: 11111010
Layer: Reversed layer
Type - VBR
Range: 256-320  kbps
Mode: joint stereo

1
Value in binary format: 00000001
Layer: Layer I
Type - CBR
Bitrate info:
Mode - mono
Bitrate - 32 kbps
		*/