#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ Unsafe and deprecated; may cause compilation error in C11 or later.
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0';
                for (int j=i-1;j<strlen(str);j++)
                {
                    printf("%c",str[j]);
                }
                printf("e-%d",i-1);    
                break;        
            }
        }
        if (str[0]!='0') // @@ Logical error: missing code to output the base (mantissa) for numbers starting with non-zero digit; also no handling for integer inputs.
        {
            if (str[i]=='.')
            {
                
                printf("e%d",i-1); // @@ Error: prints exponent without the base part; base must be printed before "e".
            }
        }
    }
}