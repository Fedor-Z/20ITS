

#include <stdio.h>
#include < string.h >
int sch()//счет символов в txt
{
    FILE* fp;
    int num = 0;
    fp = fopen("C:/Users/alexm/Desktop/Visual Studio/20ITS/Makh/Laba 5/input.txt", "r");
    while (fgetc(fp) != EOF)
    {
        num++;
    }
    fclose(fp);
    return num;
}
int sch1()//счет символов в bin
{
    FILE* fp;
    int num = 0;
    fp = fopen("C:/Users/alexm/Desktop/Visual Studio/20ITS/Makh/Laba 5/input.txt", "rb");
    while (fgetc(fp) != EOF)
    {
        num++;
    }
    fclose(fp);
    return num;
}
int word() //поиск конкретных слов
{
    FILE* fp, *fp1;
    int num = 0, num1=0, num2=0;
    char str[] = "never", str1[] = "let", str2[] = "give";
    char r [100];
    char *t;
    fp = fopen("C:/Users/alexm/Desktop/Visual Studio/20ITS/Makh/Laba 5/input.txt", "r");
    while (fgets(r, sizeof(r), fp)!=NULL)
    {
        t = strstr(r, str);
        if (t != 0)
        {
            num++;
        }
        t = strstr(r, str1);
        if (t != 0)
        {
            num1++;
        }
        t = strstr(r, str2);
        if (t != 0)
        {
            num2++;
        }
    }
    fclose(fp);
    printf("never %d \n", num);
    printf("let %d \n", num1);
    printf("give %d \n", num2);
    fp1= fopen("C:/Users/alexm/Desktop/Visual Studio/20ITS/Makh/Laba 5/output.txt", "w");
    fprintf(fp1,"never %d \n", num);
    fprintf(fp1,"let %d \n", num1);
    fprintf(fp1,"give %d \n", num2);
    return 0;
}


int main()
{
    int num, num1;
    num = sch();
    printf("%d\n", num);
    num1 = sch1();
    printf("%d\n", num1);
    word();
}
