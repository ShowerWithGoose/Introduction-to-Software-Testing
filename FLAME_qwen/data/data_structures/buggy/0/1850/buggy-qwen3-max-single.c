#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ [Uninitialized pointer 's' is used with scanf, leading to undefined behavior (likely segmentation fault). Should be a fixed-size array like char s[10005];]
    scanf("%s",s); // @@ [Reading into an uninitialized pointer causes undefined behavior. Also, no bounds checking for input length.]
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ [Incorrect condition: checks s[i-1] and s[i+1] against different ranges (e.g., s[i-1]>='a' but s[i+1]<='z'), which allows mixed-type expansions like 'a-Z'. Should check both characters belong to the same category.]
        {
            for(int j=s[i-1]+1;j<s[i+1];j++) // @@ [Loop condition should be j<=s[i+1] to include the end character as per problem requirement (e.g., a-d should include 'd').]
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