#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char str[100001];

int main()
{
    scanf("%s",&str);
    int len = strlen(str);
    int a = 0;
    if(str[0]-'0'==0)
    {
        for(int i=2;i<len;i++)
        {
            if(str[i]!='0'&&str[i+1]!='\0')
            {
                printf("%c.",str[i]);
                a = i;
                for(int p=i+1;p<len;p++)
                {
                    printf("%c",str[p]);
                }
                goto e;
            }
            else if(str[i]!='0'&&str[i+1]=='\0')
            {
                printf("%c",str[i]);
            }
        }
        e:
        printf("e-");
        printf("%d",a-1); // @@ Error: When the input is "0.9", a is set to 2 (the index of '9'), so a-1 = 1, but the exponent should be -1. The exponent calculation is incorrect; it should be -(i-1) where i is the index of the first non-zero digit after the decimal point. Here, a-1 gives 1, resulting in "e--1" instead of "e-1".
    }
    else
    {
        printf("%c.",str[0]);
        for(int i=1;i<len;i++)
        {
            if(str[i]!='.')
            {
                printf("%c",str[i]);
            }
            else
            {
                a = i;
            }
        }
        printf("e");
        printf("%d",a-1);
    }
    
    return 0;
}