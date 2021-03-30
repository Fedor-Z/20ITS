

#include <stdio.h>

int main()
{
    FILE* fp=NULL;
    int num=0;
    fp = fopen("C:/Users/alexm/Desktop/Visual Studio/20ITS/Makh/Laba 5/input.txt", "r+");
    while (fgetc(fp)!=EOF)
    {
        num++;
    }
    printf("%d", num);
    //fclose(fp);
}
