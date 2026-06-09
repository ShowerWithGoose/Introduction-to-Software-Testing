#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str);
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ Syntax error: ternary operator parsed incorrectly due to precedence; missing parentheses cause "lvalue required" compilation error.
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
                
                printf("e%d",i-1); // @@ Logical error: prints exponent but missing the base (the significant digits before the exponent). Should also output the base in scientific notation.
            }
        }
    }
}