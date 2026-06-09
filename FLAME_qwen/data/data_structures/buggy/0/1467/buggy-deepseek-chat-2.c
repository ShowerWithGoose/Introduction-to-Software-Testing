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
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1]) // @@ The condition is incorrect; it should check that both characters are within the same range, not just the first is >= 'a' and the second is <= 'z'. For example, 'a' and 'z' would pass, but 'a' and 'b' would also pass, but the condition should also ensure str[i-1] <= 'z' and str[i+1] >= 'a' to properly restrict to lowercase letters.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) // @@ The condition is incorrect; it should check that both characters are digits, i.e., str[i-1] >= '0' && str[i-1] <= '9' and str[i+1] >= '0' && str[i+1] <= '9'. The current condition only checks the first is >= '0' and the second is <= '9', which could allow non-digit characters like '0' and ':' (since ':' > '9' but <= '9' is false, but the logic is still flawed for other cases).
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) // @@ The condition is incorrect; it should check that both characters are uppercase letters, i.e., str[i-1] >= 'A' && str[i-1] <= 'Z' and str[i+1] >= 'A' && str[i+1] <= 'Z'. The current condition only checks the first is >= 'A' and the second is <= 'Z', which could allow non-uppercase characters like 'A' and '[' (since '[' > 'Z' but <= 'Z' is false, but the logic is still flawed for other cases).
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