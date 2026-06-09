#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str);
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if (str[i]!='-')
            putchar(str[i]);        
        else
        {
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1]) // @@ This if and the following two ifs should be chained as else-if, and an else branch must be added to output the hyphen when no expansion condition is met. Otherwise, when the hyphen is between different character types, it is silently omitted.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) // @@ Same issue: should be else-if to avoid redundant checks and to allow a final else for outputting the hyphen.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) // @@ Same issue: should be else-if; also missing an else clause to output the hyphen when none of the above conditions hold.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } 
        }

    }
    return 0;
}