#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ [Uninitialized pointer: 's' is declared as a pointer but not allocated memory, leading to undefined behavior when used with scanf]
    scanf("%s",s); // @@ [Writing to unallocated memory: 's' points to an arbitrary location; this causes undefined behavior or crash]
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ [Incorrect condition logic: checks s[i-1] >= 'a' and s[i+1] <= 'z' independently, which allows mixed-type ranges like 'a'-'Z'; should check both ends belong to same category and are valid]
        {
            for(int j=s[i-1]+1;j<s[i+1];j++) // @@ [Off-by-one error: loop stops before s[i+1], so the last character of the range is not printed; should be j<=s[i+1]]
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