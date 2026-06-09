#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ The pointer 's' is uninitialized and does not point to any allocated memory. Writing to it via scanf causes undefined behavior (segmentation fault). It should be declared as an array (e.g., char s[100]) or memory should be allocated.
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ The condition checks if characters are in valid ranges but fails to ensure they are of the SAME type (e.g., it allows 'a'-'Z' or '0'-'b' if ASCII values align, though the range checks partially mitigate this, the logic is flawed because it doesn't explicitly check islower/isupper/isdigit matching). More critically, it accesses s[i-1] when i=0, causing out-of-bounds access if '-' is the first character.
        {
            for(int j=s[i-1]+1;j<s[i+1];j++)
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