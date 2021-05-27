#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MASS_STEP 5

void exchange(void* base, size_t nelem, size_t width, int (*fcmp)(const int, const int, const void*, const size_t));
void elemswap(const int a, const int b, void* base, const size_t width);
int double_cmp(const int a, const int b, const void* base, const size_t size);
int str_cmp(const int a, const int b, const void* base, const size_t size);

void num_sort(char* path);
void str_sort(char* path);


int main(int argvc, char* argvs[])
{
    setlocale(LC_ALL, "");

    if (argvc == 3) {
        if (!strcmp(argvs[2], "-n")) {
            num_sort(argvs[1]);
        }
        else
            if (!strcmp(argvs[2], "-s")) {
                str_sort(argvs[1]);
            }
            else
            {
                printf("Неверные аргументы\n Используте %s \"путь к файлу\" -n\\-s", argvs[0]);
                return -2;
            }
    }
    else {
        printf("Неверные аргументы\n Используте %s \"путь к файлу\" -n\\-s", argvs[0]);
        return -1;
    }
    return 0;
}


void num_sort(char* path)
{
    FILE* input_file = fopen(path, "r");
    if (!input_file)
    {
        printf("Не удалось открыть файл %s", path);
        exit(-3);
    }

    int mass_count = 0;
    int mass_size = MASS_STEP;

    double* mass = (double*)malloc(sizeof(double) * mass_size);
    if (!mass)
    {
        printf("Не удалось выделить память");
        exit(-3);
    }

    while (fscanf(input_file, "%lf\n", mass + mass_count) > 0)
    {
        mass_count++;

        if (mass_count >= mass_size)
        {
            mass_size += MASS_STEP;
            double* tmp = (double*)realloc(mass, sizeof(double) * mass_size);
            if (!tmp)
            {
                free(mass);
                fclose(input_file);
                printf("Не удалось выделить память");
                exit(-3);
            }
            mass = tmp;
        }
    }

    for (int i = 0; i < mass_count; i++)
        printf("%.2f ", mass[i]);

    exchange(mass, mass_count, sizeof(double), double_cmp);
    printf("\n");

    for (int i = 0; i < mass_count; i++)
        printf("%.2f ", mass[i]);

    free(mass);
    fclose(input_file);
}
void str_sort(char* path)
{
    FILE* input_file = fopen(path, "r");
    if (!input_file)
    {
        printf("Не удалось открыть файл %s", path);
        exit(-3);
    }

    int mass_count = 0;
    int mass_size = MASS_STEP;

    char** mass = (char**)malloc(sizeof(char*) * mass_size);
    if (!mass)
    {
        printf("Не удалось выделить память");
        exit(-3);
    }
    char buff[256] = { 0 };

    while (fscanf(input_file, "%s\n", buff) > 0)
    {
        mass[mass_count] = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
        if (!mass[mass_count])
        {
            printf("Не удалось выделить память");
            exit(-3);
        }
        strcpy(mass[mass_count], buff);

        mass_count++;

        if (mass_count >= mass_size)
        {
            mass_size += MASS_STEP;
            char** tmp = (char**)realloc(mass, sizeof(char*) * mass_size);
            if (!tmp)
            {
                free(mass);
                fclose(input_file);
                printf("Не удалось выделить память");
                exit(-3);
            }
            mass = tmp;
        }

    }

    for (int i = 0; i < mass_count; i++)
        printf("%s\n", mass[i]);

    exchange(mass, mass_count, sizeof(char**), str_cmp);
    printf("\n");

    for (int i = 0; i < mass_count; i++)
        printf("%s\n", mass[i]);

    for (int i = 0; i < mass_count; i++)
        free(mass[i]);

    free(mass);
    fclose(input_file);
}

void elemswap(const int a, const int b, void* base, const size_t width)
{
    char* mass_base = (char*)base;

    char* buff = (char*)malloc(width);
    if (!buff)
    {
        printf("Не удалось выделить память");
        exit(-3);
    }
    memcpy(buff, mass_base + (a * width), width);
    memcpy(mass_base + (a * width), mass_base + (b * width), width);
    memcpy(mass_base + (b * width), buff, width);
    free(buff);
}
int double_cmp(const int a, const int b, const void* base, const size_t size)
{
    return ((double*)base)[a] - ((double*)base)[b];
}
int str_cmp(const int a, const int b, const void* base, const size_t size)
{
    return strcmp(((char**)base)[a], ((char**)base)[b]);
}
void exchange(void* base, size_t nelem, size_t width, int (*fcmp)(const int, const int, const void*, const size_t))
{
    int j, i, min;
    for (j = 0; j < (int)nelem; j++)
    {
        min = j;
        for (i = j + 1; i < (int)nelem; i++)
        {
            if (fcmp(i, min, base, width) < 0)
            {
                min = i;
            }
        }
        if (min > j)
        {
            elemswap(j, min, base, width);
        }
    }
}