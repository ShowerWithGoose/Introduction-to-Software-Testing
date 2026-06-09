#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ gets() is deprecated and removed in C11, causing compilation errors; use fgets() or scanf() instead.
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ Modifying the string in-place alters its length, breaking the loop condition and causing undefined behavior or incorrect output.
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
                
                printf("e%d",i-1); // @@ Fails to print the base/mantissa part of the scientific notation before the exponent.
            }
        }
    }
}