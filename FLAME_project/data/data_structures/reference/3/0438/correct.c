#include<stdio.h>
#include<stdlib.h>
int getPoint(char str[]);
int getFirstNum(char str[]);

int main()
{
    char num[110];
    gets(num);
    int point = getPoint(num);
    int first = getFirstNum(num);
    // printf("p:%d f:%d", point, first); 
    for (int i = 0; num[first+i] != '\0'; i++)
    {
        if (i == 1)
        {
            printf(".");
        }
        if (num[first+i] == '.')
        {
            continue;
        }
        printf("%c", num[first+i]);
    }

    printf("e%d", point <= first ? point-first : point-first-1);
    
    // system("pause");
    return 0;
}

int getPoint(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.')
        {
            return i;
        }
    }
    
    return -1;
}

int getFirstNum(char str[])
{
    int i;
    for (i = 0; str[i] != '\0' && (str[i] == '.' || str[i] == '0'); i++);
    return i;
}
