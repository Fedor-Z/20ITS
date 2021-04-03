#include <iostream>

#define SENTENCE_ENDS ".?!"
using namespace std;

void probel(char* dest, const char* source)
{
    for (; (*dest = *source); ++source, ++dest)
    {
        if (*source != ' ')
            continue;
        *(dest++) = *source;
        for (; *source == ' '; ++source)
            ;
        *dest = *source;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    FILE* text;
    const char* filename = "C:/Users/dimaa/Desktop/DmitrySuvorov/20ITS/Suvorov/Dmitry Suvorov Lab 5/text.txt";
    char result_string[100];
    text = fopen(filename, "r");

    if (text == NULL)
    {
        printf("Не могу открыть файл '%s'", filename);
        return 0;
    }


    printf("Редактированный текст из файла: \n\n");

    while (fgets(result_string, sizeof(result_string), text))
    {
        probel(result_string, result_string);

        char* p;
        int inSentence;

        for (inSentence = 0, p = result_string; *p != '\0'; ++p)
        {
            if (strchr(SENTENCE_ENDS, *p))
                inSentence = 0;
            else if (isspace(*p)) {}
            else {
                if (!inSentence)
                    *p = toupper(*p);
                inSentence = 1;
            }
        }//Для выражения после точки


        if (result_string[strlen(result_string) - 1] == '\n')
        {
            result_string[strlen(result_string) - 1] = '\0';
            int r = 0;
            while (result_string[r] != '\0')
            {
                if (result_string[r] == '.')
                {
                    if (result_string[r + 1] == ' ')
                    {
                        if ((result_string[r + 2] >= 97) && (result_string[r + 2] <= 122))
                        {
                            result_string[r + 2] = toupper(result_string[r + 2]);
                            r++;
                        }
                        else r++;
                    }

                    if ((result_string[r + 1] >= 97) && (result_string[r + 1] <= 122))
                    {
                        result_string[r + 1] = toupper(result_string[r + 1]);
                        r++;
                    }
                    else r++;
                }
                else r++;
            }
        };//Для комбинации после точки и пробела

        printf("%s\n", result_string);
    }
    fclose(text);
}