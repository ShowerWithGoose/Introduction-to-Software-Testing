#include<stdio.h>


int main()
{
    char str[105] = "\0";
    int i,j;
    gets(str);


    if (str[0] == '0')
    {
        for (i = 2;str[i] == '0';i ++)
            ;
        printf("%d", str[i]-'0');
        if (str[i+1] == '\0')
        {
            printf("e-%d", i-1);
        }
        else
        {
            printf(".");
            for (j = i+1;str[j] != '\0';j ++)
            {
                printf("%d", str[j]-'0');
            }
            printf("e-%d", i-1);
        }
    }
    else
    {
        printf("%d.", str[0]-'0');
        for (i = 1;str[i] != '.';i ++)
        {
            printf("%d", str[i]-'0');
        }
        for (j = i+1;str[j] != '\0';j ++)
        {
            printf("%d",str[j]-'0');
        }
        printf("e%d", i-1);
    }

    return 0;
}



