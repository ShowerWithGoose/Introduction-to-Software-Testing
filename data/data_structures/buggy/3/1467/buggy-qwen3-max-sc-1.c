#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [Using gets() is unsafe and deprecated; causes compilation error in modern compilers due to removal from standard library]
    for (int i=0;i<strlen(str);i++)
    {
        if (str[0]=='0')
        {
            if (str[i]!='0' && str[i]!='.')
            {
                str[i-1]=str[i];
                str[i+1]!='\0'?str[i]='.':str[i]='\0'; // @@ [This ternary modifies str[i] but doesn't handle string termination correctly; also logic flaw in shifting digits]
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
                
                printf("e%d",i-1); // @@ [Missing printing of the normalized base part before 'e'; only prints exponent]
            }
        }
    }
}