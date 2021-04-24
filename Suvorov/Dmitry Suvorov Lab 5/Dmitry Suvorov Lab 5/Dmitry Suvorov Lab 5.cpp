#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#define SENTENCE_ENDS ".?!"
using namespace std;

void probel(char* dest, const char* source, int i)
{
	for (; (*dest = *source); ++source, ++dest)
	{
		if (*source != ' ')continue;
		*(dest++) = *source;

		for (; *source == ' '; ++source);

		*dest = *source;
		if (*source == (char)34 || *source == (char)39) {
			memcpy(dest, source, i);
			source = source + i; //пропускаем элементы в кавычках
			dest = dest + i - 1; //убираем лишний элемент с конца
		}
	}
}

int sprint(char* str, char* kav, int k)
{
	int pos = strcspn(str, kav); //ищем 1 скобку
	int i = pos;
	str[pos] = 32; //записываем пробел
	pos = strcspn(str, kav); //ищем вторую скобку
	str[i] = *kav;
	k = pos + 1;
	return k;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	FILE* text;
	const char* filename = "C:/Users/dimaa/Desktop/DmitrySuvorov/20ITS/Suvorov/Dmitry Suvorov Lab 5/text.txt";
	char result_string[100];
	text = fopen(filename, "r");

	char* kavv = (char*)malloc(1 * sizeof(char));
	char* apostr = (char*)malloc(1 * sizeof(char));
	*apostr = 39;
	*kavv = 34;
	int point = 0;
	int lenght = 0;

	if (text == NULL)
	{
		printf("Не могу открыть файл '%s'", filename);
		return 0;
	}

	printf("Редактированный текст из файла: \n\n");

	while (fgets(result_string, sizeof(result_string), text))
	{

		if (strlen(result_string) != 0)
		{
			int r = 0;
			while (result_string[r] != '\0')
			{

				if (result_string[r] == *kavv) {
					lenght = r;
					r = sprint(result_string, kavv, r);
					lenght = r - lenght;
				}
				if (result_string[r] == *apostr) {
					lenght = r;
					r = sprint(result_string, apostr, r);
					lenght = r - lenght;
				}

				if (result_string[r] == '.' || point != 0)
				{
					while (result_string[r + 1] == ' ') r++; //пропускаем пробелы

					if ((result_string[r + 1] >= 97) && (result_string[r + 1] <= 122) && (result_string[r + 1] != *kavv) && (result_string[r + 1] != *apostr))
					{
						result_string[r + 1] = toupper(result_string[r + 1]);
						point = 0;
					}

				}
				r++;
			}
		};

		probel(result_string, result_string, lenght);
		printf("%s", result_string);
	}
	fclose(text);
}

//Не знаю как на GitHub адресовать вам сообщение, поэтому я оставлю это здесь :)  Я сам с Бора, и мне во вторник очень трудно ехать в ВУЗ 
//ради сдачи одной лабы по информатике, надеюсь вы всё ещё проверяете Git и увидите моё сообщение. Если проверите, напишите мне сообщением здесь, или на почту. Спасибо
