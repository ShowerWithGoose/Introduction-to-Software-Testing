#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s;
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++) @@ // Compilation error: C90 does not allow variable declaration in for loop initialization; use C99 or declare i before the loop.
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1])
        {
            for(int j=s[i-1]+1;j<s[i+1];j++) @@ // Compilation error: C90 does not allow variable declaration in for loop initialization; use C99 or declare j before the loop.
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