#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in modern C standards (C11 onwards), 'gets' has been removed entirely, leading to compilation error if compiler adheres strictly to standard]
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ [This ternary expression modifies 'str[i]' but does not handle the rest of the string correctly; also, after modifying the string, the loop continues or breaks inconsistently, leading to incorrect output logic]
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
                
                printf("e%d",i-1); // @@ [Missing the base part of scientific notation; only prints exponent without printing normalized mantissa first]
            }
        }
    }
}