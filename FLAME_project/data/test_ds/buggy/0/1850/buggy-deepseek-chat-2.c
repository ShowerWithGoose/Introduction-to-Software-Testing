#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ [s is an uninitialized pointer, causing undefined behavior when used in scanf]
    scanf("%s",s); // @@ [s is not allocated memory, leading to segmentation fault or undefined behavior]
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ [The condition incorrectly checks ranges; e.g., 'a' to 'z' should use && for both bounds, but the logic is flawed and does not ensure same type. Also, when i=0, s[i-1] accesses out-of-bounds memory]
        {
            for(int j=s[i-1]+1;j<s[i+1];j++) // @@ [The loop does not output the first and last characters of the expansion range, missing the start and end characters]
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