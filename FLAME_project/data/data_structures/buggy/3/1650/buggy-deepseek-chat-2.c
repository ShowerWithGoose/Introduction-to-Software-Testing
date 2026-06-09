#include <stdio.h>
char str[10000];
int main()
{
    gets(str);
    int i=1,j;
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++);
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
            printf("%d",i-1); // @@ The exponent calculation is incorrect. For input "0.9", i becomes 2 after the loop (since str[2] is '9' and not '0'), so i-1 = 1, but the expected exponent is -1. The exponent should be -(i-1) to account for the negative exponent when the number is less than 1.
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
        for(i=0;str[i]!='.';i++);
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