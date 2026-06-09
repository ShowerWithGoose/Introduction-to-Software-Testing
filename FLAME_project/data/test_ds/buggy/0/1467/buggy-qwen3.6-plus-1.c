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
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1]) // @@ Incomplete range check: only verifies str[i-1]>='a' and str[i+1]<='z', fails to ensure both characters are within [a-z]. Also, missing else branch to print '-' when expansion conditions are not met.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) // @@ Incomplete range check: only verifies str[i-1]>='0' and str[i+1]<='9', fails to ensure both characters are within [0-9].
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) // @@ Incomplete range check: only verifies str[i-1]>='A' and str[i+1]<='Z', fails to ensure both characters are within [A-Z]. Missing else clause to output '-' when none of the expansion conditions match.
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