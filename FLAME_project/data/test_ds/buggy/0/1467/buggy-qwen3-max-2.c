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
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1])
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) @@ // The condition only checks lower bound for str[i-1] and upper bound for str[i+1], but does not ensure both are digits (e.g., '0' <= str[i-1] <= '9' AND '0' <= str[i+1] <= '9'). This allows invalid cases like '0-b' to be incorrectly expanded.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) @@ // The condition only checks lower bound for str[i-1] and upper bound for str[i+1], but does not ensure both are uppercase letters (e.g., 'A' <= str[i-1] <= 'Z' AND 'A' <= str[i+1] <= 'Z'). This allows mixed cases like 'B-e' to be incorrectly considered for expansion in other branches or miss proper rejection.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } 
            if (!((str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1] && str[i-1]<='z' && str[i+1]>='a') || 
                  (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1] && str[i-1]<='Z' && str[i+1]>='A') || 
                  (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1] && str[i-1]<='9' && str[i+1]>='0'))) @@ // Missing else clause: if none of the valid expansion conditions are fully satisfied, the '-' should be printed as-is. The current code omits printing '-' when no expansion occurs, causing it to be silently dropped (e.g., input "B-e" becomes "Be" instead of "B-e").
                putchar('-');
        }

    }
    return 0;
}