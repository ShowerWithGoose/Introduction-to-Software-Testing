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
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) // @@ [This condition is incorrect: it only checks lower bound for str[i-1] and upper bound for str[i+1], but does not ensure both are digits. For example, 'B' (66) >= '0' (48) and 'e' (101) <= '9' (57) is false, but a mixed case like '0'-'Z' might incorrectly pass part of the check. More critically, it fails to verify that str[i+1] >= '0' and str[i-1] <= '9'.]
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) // @@ [This condition is incorrect: it only checks lower bound for str[i-1] and upper bound for str[i+1], but does not ensure both are uppercase letters. For example, in input "B-e", str[i-1]='B' (>= 'A') and str[i+1]='e' (<= 'Z') is false because 'e' > 'Z', so this block won't run — which is correct — but the logic is flawed because it doesn't check str[i+1] >= 'A' or str[i-1] <= 'Z'. However, the real issue is in the first condition below.]
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } 
            // @@ [Missing an 'else' clause to output the '-' when no expansion occurs. In cases like "B-e", none of the three if conditions are satisfied (because types differ), so the program outputs nothing for the '-', leading to "Be" instead of "B-e". The '-' must be printed if no expansion is performed.]
        }

    }
    return 0;
}