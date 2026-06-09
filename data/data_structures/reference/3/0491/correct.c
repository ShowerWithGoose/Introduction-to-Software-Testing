#include<stdio.h>
#include<string.h>
char s[200];
int i,j,k;
int main()
{
    scanf("%s",s);
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '.')
        {
            j = i;
        }
    }
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] != '0'&& s[i] != '.')
        {
            k = i;
            printf("%c",s[i]);
            if(s[i+1] != '\0')
            {
                printf(".");
            }
            for(i = k + 1; s[i] != '\0'; i++)
            {
                if(s[i] != '.')
                    printf("%c",s[i]);
            }
            s[i+1] = '\0';
        }
    }
    int num = j - k;
    printf("e");
    if(num < 0 || num == 0)
        printf("%d",num);
    else if(num > 0)
        printf("%d",num - 1);
    return 0;
}

