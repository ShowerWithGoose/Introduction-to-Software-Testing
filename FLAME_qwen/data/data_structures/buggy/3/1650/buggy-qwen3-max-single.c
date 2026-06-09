#include <stdio.h>
char str[10000];
int main()
{
    gets(str); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    int i=1,j;
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++); // @@ [Incorrect loop initialization: skips index 1 which may be '.'; fails to handle input like "0.00123" correctly]
        if(str[i+1]=='\0')
        {
            printf("%c",str[i]);
        }
        else
        {
            printf("%c.",str[i]);
            for(j=i+1;str[j]!='\0';j++)
            {
                printf("%c",str[j]);
            }    
            printf("e");
            printf("%d",i-1); // @@ [Exponent calculation is incorrect; does not account for the decimal point position properly]
        }
    }
    else if(str[1]=='.')
    {
        for(i=0;str[i]!='\0';i++)
        {
            printf("%c",str[i]);
        }
        printf("e0");
    }
    else
    {
        for(i=0;str[i]!='.';i++); // @@ [Loop condition may lead to infinite loop or undefined behavior if input has no decimal point]
        printf("%c.",str[0]);
        for(j=1;j<i;j++)
        {
            printf("%c",str[j]);
        }
        for(j=i+1;str[j]!='\0';j++)
        {
            printf("%c",str[j]);
        }
        printf("e");
        printf("%d",i-1);
    }
    return 0;
}