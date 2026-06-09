#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ uninitialized pointer, leads to undefined behavior when used in scanf.
    scanf("%s",s); // @@ s is uninitialized pointer, writing to random memory causes segmentation fault.
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ 1) Out-of-bounds access: i=0 or i=n-1 cause invalid memory access. 2) Incorrect same-type check: condition should ensure both characters are within the same range, e.g., (s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'), not just left>=min and right<=max.
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