#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 10000
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

char a[MAX];
int i, len, mark=0;
int main()
{
    scanf("%s", a);
    len=strlen(a);
    if(a[0]=='0'&&a[1]=='.')
    {
        for(i=0;i<len;i++)
        {
            if(a[i]=='0')
                mark++;
            if(a[i]!='0'&&a[i]!='.')
                break;
        }
        printf("%c", a[i]);
        i++;
        if(i!=len)
        {
            printf(".");
            for(;i<len;i++)
                printf("%c", a[i]);
        }
        printf("e-%d", mark);
    }
    else
    {
        printf("%c.", a[0]);
        for(i=1;i<len;i++)
        {
            if(a[i]!='.')
            {
                printf("%c", a[i]);
                mark++;
            }
            else
            {
                i++;
                break;
            }
        }
        for(;i<len;i++)
            printf("%c", a[i]);
        printf("e%d", mark);
    }
	return 0;
}

