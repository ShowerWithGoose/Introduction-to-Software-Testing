#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ [Uninitialized pointer: 's' is declared as a pointer but not allocated memory, leading to undefined behavior when used with scanf]
    scanf("%s",s); // @@ [Writing to unallocated memory: since 's' points to an arbitrary location, this causes undefined behavior and likely a segmentation fault]
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ [Incorrect range checks: conditions like 's[i-1]>='a' && s[i+1]<='z'' do not ensure both characters are of the same type or within valid ranges; also accesses s[i-1] when i=0 leads to out-of-bounds read]
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