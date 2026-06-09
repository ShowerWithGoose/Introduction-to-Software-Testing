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
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) @@ // The condition is incomplete: it doesn't ensure str[i-1] <= '9' and str[i+1] >= '0', so mixed cases like 'a-9' might incorrectly trigger digit expansion.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) @@ // The condition is incomplete: it doesn't ensure str[i+1] >= 'A' and str[i-1] <= 'Z', so mixed cases like 'A-z' might incorrectly trigger uppercase expansion.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } 
            if (!((str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1] && str[i+1]>='a' && str[i-1]<='z') ||
                  (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1] && str[i+1]>='A' && str[i-1]<='Z') ||
                  (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1] && str[i+1]>='0' && str[i-1]<='9'))) @@ // Missing else clause to output '-' when no valid expansion occurs; current code silently skips printing '-' in invalid cases like "B-e".
                putchar('-');
        }

    }
    return 0;
}