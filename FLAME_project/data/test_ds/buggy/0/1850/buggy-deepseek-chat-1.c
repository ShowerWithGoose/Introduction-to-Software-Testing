#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ [s is an uninitialized pointer, leading to undefined behavior when used with scanf]
    scanf("%s",s); // @@ [s is not allocated memory, causing a segmentation fault or undefined behavior]
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ [The condition incorrectly checks s[i+1] <= 'z' etc., instead of checking both characters are within the same range; also, when i=0, s[i-1] accesses out-of-bounds memory]
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