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
            } // @@ [This condition only checks lower bound for str[i-1] and upper bound for str[i+1], but does not ensure both are lowercase letters. For example, 'B-e' could incorrectly satisfy parts of this condition due to ASCII values, but more critically, it fails to verify that str[i+1] >= 'a' and str[i-1] <= 'z'.]
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1])
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } // @@ [This condition only checks lower bound for str[i-1] and upper bound for str[i+1], but does not ensure both are digits. It should also check str[i+1] >= '0' and str[i-1] <= '9'.]
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1])
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } // @@ [This condition only checks lower bound for str[i-1] and upper bound for str[i+1], but does not ensure both are uppercase letters. It should also check str[i+1] >= 'A' and str[i-1] <= 'Z'.]
            // @@ [If none of the above conditions are fully satisfied (e.g., mixed case like 'B-e'), the '-' character is simply skipped and not printed, leading to output "Be" instead of "B-e". The program should output the '-' as-is when expansion conditions are not met.]
        }

    }
    return 0;
}