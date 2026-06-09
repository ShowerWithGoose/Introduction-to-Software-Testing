#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ [Uninitialized pointer: 's' is declared as a pointer but not allocated memory, leading to undefined behavior when used with scanf]
    scanf("%s",s); // @@ [Using uninitialized pointer 's' in scanf causes undefined behavior; should allocate memory or use a fixed-size array]
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ [Incorrect condition logic: checks s[i-1] >= 'a' and s[i+1] <= 'z' independently, which allows mixed-type ranges like 'a-Z'; should verify both characters belong to the same category]
        {
            for(int j=s[i-1]+1;j<s[i+1];j++) // @@ [Loop condition excludes the end character: should be j <= s[i+1] to include the final character in expansion]
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