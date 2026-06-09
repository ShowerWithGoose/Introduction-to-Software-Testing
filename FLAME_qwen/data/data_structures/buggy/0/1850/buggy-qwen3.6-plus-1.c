#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ Uninitialized pointer. Using it with scanf causes undefined behavior/segmentation fault. Should be declared as an array, e.g., char s[10005];
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ Incorrect type checking logic. The condition does not ensure both characters are of the same type. It should verify that both s[i-1] and s[i+1] fall within the same range (e.g., both lowercase, both uppercase, or both digits).
        {
            for(int j=s[i-1]+1;j<s[i+1];j++) // @@ Off-by-one error. The loop condition j<s[i+1] excludes the ending character. It should be j<=s[i+1] to correctly expand the range.
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