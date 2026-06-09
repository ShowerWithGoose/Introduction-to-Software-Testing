#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings.]
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ [This ternary expression modifies 'str[i]' but does not handle string termination correctly when '\0' is assigned, potentially leading to undefined behavior or incorrect output. Also, shifting digits in-place like this corrupts the original string structure needed for further processing.]
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
                
                printf("e%d",i-1); // @@ [This prints only the exponent without printing the normalized base part (e.g., "1.23"), resulting in incomplete scientific notation output.]
            }
        }
    }
}