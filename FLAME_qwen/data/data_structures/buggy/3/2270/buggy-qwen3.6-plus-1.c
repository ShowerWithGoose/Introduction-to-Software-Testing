#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char str[100001];

int main()
{
    scanf("%s",&str); // @@ Incorrect argument type for scanf; &str is char (*)[100001], but %s expects char *, which causes a type mismatch compilation error.
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
                printf("%c",str[i]); // @@ Missing a = i; and goto e; causes incorrect exponent calculation and improper control flow when the first non-zero digit is the last character.
            }
        }
        e:
        printf("e-");
        printf("%d",a-1);
    }
    else
    {
        printf("%c.",str[0]); // @@ Unconditionally prints a decimal point, violating the output format requirement that integer bases must not contain a decimal point.
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
        printf("%d",a-1); // @@ If the input lacks a decimal point, a remains 0, resulting in an incorrect exponent of -1 instead of 0.
    }
    
    return 0;
}