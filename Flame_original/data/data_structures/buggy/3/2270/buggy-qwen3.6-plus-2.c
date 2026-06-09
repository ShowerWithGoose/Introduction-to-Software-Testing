#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char str[100001];

int main()
{
    scanf("%s",&str); // @@ Incorrect argument type for %s format specifier; &str is of type char (*)[100001], should be str which decays to char *
    int len = strlen(str);
    int a = 0;
    if(str[0]-'0'==0)
    {
        for(int i=2;i<len;i++) // @@ Declaring loop variable inside for initializer is not allowed in C89/ANSI C, causing compilation error on strict compilers
        {
            if(str[i]!='0'&&str[i+1]!='\0')
            {
                printf("%c.",str[i]);
                a = i;
                for(int p=i+1;p<len;p++) // @@ Same C89 compatibility issue: variable declaration in for loop initializer
                {
                    printf("%c",str[p]);
                }
                goto e;
            }
            else if(str[i]!='0'&&str[i+1]=='\0') // @@ Logical error: variable a is not updated here, leading to incorrect exponent calculation (a remains 0, prints e--1)
            {
                printf("%c",str[i]);
            }
        }
        e:
        printf("e-");
        printf("%d",a-1);
    }
    else
    {
        printf("%c.",str[0]);
        for(int i=1;i<len;i++) // @@ Same C89 compatibility issue: variable declaration in for loop initializer
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