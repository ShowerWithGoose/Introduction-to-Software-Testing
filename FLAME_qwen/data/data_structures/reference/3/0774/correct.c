#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 10000
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

char s[MAX];
int i, len, mark=0;
int main()
{
    scanf("%s", s);
    len=strlen(s);
    if(s[0]=='0'&&s[1]=='.')
    {
        for(i=0;i<len;i++)
        {
            if(s[i]=='0')
                mark++;
            if(s[i]!='0'&&s[i]!='.')
                break;
        }
        printf("%c", s[i]);
        i++;
        if(i!=len)
        {
            printf(".");
            for(;i<len;i++)
                printf("%c", s[i]);
        }
        printf("e-%d", mark);
    }
    else
    {
        printf("%c.", s[0]);
        for(i=1;i<len;i++)
        {
            if(s[i]!='.')
            {
                printf("%c", s[i]);
                mark++;
            }
            else
            {
                i++;
                break;
            }
        }
        for(;i<len;i++)
            printf("%c", s[i]);
        printf("e%d", mark);
    }
	return 0;
}

