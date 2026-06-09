#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char ch[200];
    int i,j,num;
    scanf("%s",ch);
    if(ch[0]=='0')
    {
        for(i=2;ch[i]=='0';i++);
        printf("%c",ch[i]);
        if(ch[i+1]=='\0')
        {
            printf("e-");
            printf("%d",i-1);
        }
        else
        {
            printf(".");
            for(j=i+1;j<strlen(ch);j++)
            {
                printf("%c",ch[j]);
            }
            printf("e-");
            printf("%d",i-1);
        }
    }
    else if(ch[1]=='.')
    {
        for(i=0;i<strlen(ch);i++)
        {
            printf("%c",ch[i]);
        }
        printf("e0");
    }
    else
    {
        printf("%c.",ch[0]);
        for(i=1;i<strlen(ch);i++)
        {
            if(ch[i]=='.')
            {
                num=i-1;
            }
            else
                printf("%c",ch[i]);
        }
        printf("e%d",num);
    }
    return 0;
}

