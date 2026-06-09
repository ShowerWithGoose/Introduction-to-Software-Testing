#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ Uninitialized pointer leads to undefined behavior and segmentation fault when used with scanf. It should be declared as a character array (e.g., char s[10005];).
    scanf("%s",s);
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ Incorrect type checking logic. The condition only checks one bound per character instead of verifying both characters are within the same valid range (e.g., both lowercase, both uppercase, or both digits).
        {
            for(int j=s[i-1]+1;j<s[i+1];j++) // @@ The loop condition uses '<' instead of '<=', which excludes the end character from the expansion. It should be 'j <= s[i+1]' to correctly include the final character.
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