// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	st = perenos + 1;				//st - ����� ����� �������� ��������� 
	fseek(fp1, 0, SEEK_SET);		//��������� ������ � ������,�������� ������� �� 9 ���� ������������ ������ �����
	if (fp2 != NULL)
	{
		for (int i = 0; i < st; i++)
		{
			fgets(n, 26, fp1);			//���������� � ������
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
				printf("%c: %i\n", r, m[r]); // %i ���������� ����� �����  %������ char
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
			else printf("������!\n");
		}
	}
	else printf("������! ���� ����������\n");
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
			c = fgetc(fp1);		//����������� ��������� ���������� �� ����� 
			if (c == ' ') probel++;
			if (c == '\t') tabul++;
			if (c == '\n') per++;
		} while (c != EOF);
		fprintf(fp2, "��������: %d\n ����� ���������: %d , ��������� �� ����� ������: %d , ", probel, tabul, per);
		printf("����� ��������: %d\n", probel);
		printf("����� ���������: %d", tabul);
		printf(" ����� ��������� �� ����� ������ : %d,", per);
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

