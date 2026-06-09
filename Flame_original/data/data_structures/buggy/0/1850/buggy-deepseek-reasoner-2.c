#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ Uninitialized pointer; leads to undefined behavior when used in scanf.
    scanf("%s",s); // @@ Writing to an uninitialized pointer causes segmentation fault or corruption. Should allocate memory (e.g., char s[10005]) or use malloc.
    int n=strlen(s); // @@ strlen called on uninitialized pointer; behavior undefined.
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ Incorrect range checking; should verify both sides independently (e.g., (s[i-1]>='a' && s[i-1]<='z') && (s[i+1]>='a' && s[i+1]<='z')). Also, accessing s[i-1] and s[i+1] without boundary checks may read out-of-bounds when dash is at start or end.
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