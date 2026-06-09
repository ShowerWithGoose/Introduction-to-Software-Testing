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
            printf("%c",str[i]); // @@ Missing exponent output: for single digit after decimal, scientific notation requires exponent (e.g., "9e-1"). This branch should also print exponent.
        }
        else
        {
            printf("%c.",str[i]);
            for(j=i+1;str[j]!='\0';j++)
            {
                printf("%c",str[j]);
            }    
            printf("e");
            printf("%d",i-1); // @@ Exponent sign missing: for numbers less than 1, exponent should be negative (e.g., -1 for 0.123). Must print negative value.
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
        printf("%d",i-1); // This is correct for numbers >=1 (positive exponent), but note that exponent sign handling for negative cases is missing earlier.
    }
    return 0;
}