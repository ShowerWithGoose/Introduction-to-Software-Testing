#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use 'fgets' instead.]
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ [This ternary expression modifies 'str[i]' but doesn't handle string termination correctly when '\0' is assigned, potentially causing undefined behavior or incorrect output. Also, shifting digits manually like this is error-prone.]
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
                
                printf("e%d",i-1); // @@ [This prints only the exponent without printing the normalized base (mantissa), violating the output format requirement. The base part is missing entirely for numbers not starting with '0'.]
            }
        }
    }
}