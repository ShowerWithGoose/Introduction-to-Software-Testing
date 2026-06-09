#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
#define true 1
int main()
{
    char a[100];
    int i=0,j=0,k=0,l=0;
    gets(a);
    k=1;
    if(a[1]=='.')
    {
        if(a[0]=='0')
        {
            for(j=2;a[j]=='0';j++)
            {
                k++;
            }
            if(a[j+1]=='\0')
            {
                printf("%c",a[j]);
                for(j++;a[j]!='\0';j++)
                {
                    printf("%c",a[j]);
                }
                printf("e-%d\n",k);
            }
            else
            {
                printf("%c.",a[j]);
                for(j++;a[j]!='\0';j++)
                {
                    printf("%c",a[j]);
                }
                printf("e-%d\n",k);
            }
        }
        else
        {
            printf("%se0",a);
        }
    }
    else
    {
        for (i=0;a[i]!='\0'; i++)
        {
            if (a[i]=='.')
                break;
        }
        l=i-1;
        printf("%c.",a[0]);
        for(j=1;j<i;j++)
        {
            printf("%c",a[j]);
        }
        for(j=i+1;a[j]!='\0';j++)
        {
            printf("%c",a[j]);
        }
        printf("e%d",l);
    }
    return 0;
}


