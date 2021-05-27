// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
#pragma warning(disable : 4996)
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDKDDKVer.h>
#include <string>
#include "Input.txt"
#include "Output.txt"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
int letters()
{
	char n[26] = { 0 };
	char m[123] = { 0 };
	int st = 0;
	int perenos = 0;
	FILE* fp1 = fopen("D:/Inf/laba55/laba55/laba55/Input.txt", "r");
	FILE* fp2 = fopen("D:/Inf/laba55/laba55/laba55/Output.txt", "w+");
	st = perenos + 1;				//st - число строк учитывая последнюю 
	fseek(fp1, 0, SEEK_SET);		//переводим курсор в начало,изменить позицию на 9 байт относительно начала файла
	if (fp2 != NULL)
	{
		for (int i = 0; i < st; i++)
		{
			fgets(n, 26, fp1);			//закидываем в массив
			int len = strlen(n);			//size of strok 
			for (int k = 0; k < len && n[k] != '\0'; k++) // \0 end of strok 
			{
				if ((n[k] >= 'a' && n[k] <= 'z') || (n[k] >= 'A' && n[k] <= 'Z')) m[n[k]]++;
				else continue;
			}
		}
		for (char r = 'a'; r <= 'z'; r++)
		{
			if (m[r] != 0)
			{
				printf("%c: %i\n", r, m[r]); // %i десятичное целое число  %символ char
				fprintf(fp2, "%c: %i\n", r, m[r]);
			}
		}
		for (char r = 'A'; r <= 'Z'; r++)
		{
			if (m[r] != 0)
			{
				printf("%c: %i\n", r, m[r]);
				fprintf(fp2, "%c: %i\n", r, m[r]);
			}
			else printf("Ошибка!\n");
		}
	}
	else printf("Ошибка! Файл отсутсвует\n");
	fclose(fp1);
	fclose(fp2);
	return 1;
}

int poisk()
{
	int tabul = 0;
	int probel = 0;
	int per = 0;
	char c;
	FILE* fp1 = fopen("D:/Inf/laba55/laba55/laba55/Input.txt", "r");
	FILE* fp2 = fopen("D:/Inf/laba55/laba55/laba55/Output.txt", "w+");
	if (fp1 != NULL)
	{
		do
		{
			c = fgetc(fp1);		//посимвольно считываем информацию из файла 
			if (c == ' ') probel++;
			if (c == '\t') tabul++;
			if (c == '\n') per++;
		} while (c != EOF);
		fprintf(fp2, "Пробелов: %d\n Число табуляций: %d , Переходов на новую строку: %d , ", probel, tabul, per);
		printf("Число пробелов: %d\n", probel);
		printf("Число табуляций: %d", tabul);
		printf(" Число переходов на новую строку : %d,", per);
		return 0;

	}

	fclose(fp1);
	fclose(fp2);
}
	int main()
	{
		char* locale = setlocale(LC_ALL, "");
		int letters();
		int poisk();
		return 0;
	}

