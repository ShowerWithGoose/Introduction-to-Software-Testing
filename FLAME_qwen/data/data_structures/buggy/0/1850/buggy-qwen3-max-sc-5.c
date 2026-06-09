#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ [Uninitialized pointer 's' is used with scanf, leading to undefined behavior (likely segmentation fault). Should be a fixed-size array like char s[10005];]
    scanf("%s",s); // @@ [Writing to unallocated memory via uninitialized pointer 's'. This causes runtime crash or undefined behavior.]
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ [Incorrect condition: checks s[i-1] >= 'a' AND s[i+1] <= 'z', which allows mixed-type cases like 'z'-'a' or even '0'-'z'. Should check both ends belong to same category and are valid. Also fails to ensure both characters are of same type.]
        {
            for(int j=s[i-1]+1;j<s[i+1];j++) // @@ [Loop condition should be j <= s[i+1] to include the end character as per problem requirement (e.g., a-d becomes abcd). Current code excludes the last character.]
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