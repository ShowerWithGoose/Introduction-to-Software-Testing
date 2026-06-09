#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ gets is deprecated and removed in C11, which causes compilation errors in modern environments; use fgets or scanf instead.
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ Modifies the string in-place using a ternary operator as a statement, which is unsafe and can lead to logical errors; output should be generated without mutating the input.
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
                
                printf("e%d",i-1); // @@ Fails to print the base part of the scientific notation for numbers >= 1; only the exponent is printed, violating the output format.
            }
        }
    }
}