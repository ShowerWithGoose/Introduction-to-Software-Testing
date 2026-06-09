#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ [Uninitialized pointer: 's' is declared as a pointer but not allocated memory, leading to undefined behavior when used with scanf]
    scanf("%s",s); // @@ [Writing to unallocated memory: since 's' points to an arbitrary location, this causes undefined behavior and likely a crash or segmentation fault]
    int n=strlen(s);
    for(int i=0;i<n;i++)
    {
        pri(s,i);
    }
    return 0;
}
void pri(char *s,int i)
{
    if(s[i]!='-')
    {
        printf("%c",s[i]);
        return ;
    }
    else
    {
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ [Incorrect range checks: conditions like 's[i-1]>='a' && s[i+1]<='z'' do not ensure both characters are in the same category; should check both ends belong to same group (e.g., both lowercase)]
        {
            for(int j=s[i-1]+1;j<s[i+1];j++) // @@ [Off-by-one error: loop stops before s[i+1], so last character is missing; should be j<=s[i+1]]
            {
                printf("%c",j);
            }
            return ;
        }
        else
        {
            printf("-");
            return ;
        }
    }
}