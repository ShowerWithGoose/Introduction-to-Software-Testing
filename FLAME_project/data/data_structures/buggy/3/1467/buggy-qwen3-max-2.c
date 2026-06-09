#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [Use of unsafe and deprecated function 'gets'; also causes implicit declaration warning without including proper headers or using safer alternative like fgets]
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ [Ternary operator used as statement with assignment to possibly non-lvalue; the expression after ':' attempts to assign to str[i] which is fine, but the entire construct is invalid as a standalone statement in C because the ternary operator must evaluate to an rvalue, not control assignments this way]
                for (int j=i-1;j<strlen(str);j++)
                {
                    printf("%c",str[j]);
                }
                printf("e-%d",i-1);    
                break;        
            }
        }
        if (str[0]!='0')
        {
            if (str[i]=='.')
            {
                
                printf("e%d",i-1); // @@ [Missing output of the normalized base part before 'e'; only prints exponent, violating output format requirement]
            }
        }
    }
}