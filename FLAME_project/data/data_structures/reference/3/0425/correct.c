#include <stdio.h>
char a[102];
int main()
{
    int i,j;
    scanf("%s",a);
    if(a[0]=='0')
    {
        for(i=1;a[i+1]=='0';i++)
        {
        }
        printf("%c",a[i+1]);
        if(a[i+2]!=0)
        {
            printf(".");
            for(j=i+2;a[j]!=0;j++)
                printf("%c",a[j]);
        }
        printf("e-%d",i);
    }
    else
    {
        printf("%c.",a[0]);
        for(i=0;a[i+1]!='.';i++)
            printf("%c",a[i+1]);
        for(j=i+2;a[j]!=0;j++)
            printf("%c",a[j]);
        printf("e%d",i);
    }
    return 0;
}

