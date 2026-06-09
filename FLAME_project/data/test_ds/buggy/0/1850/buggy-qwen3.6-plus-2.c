#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ Uninitialized pointer; scanf will write to an invalid memory address causing undefined behavior/crash. Should be declared as an array, e.g., char s[100];
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ Logical error: condition does not verify both characters are of the same type (e.g., 'a-9' incorrectly passes). Also, accessing s[i-1] when i=0 causes out-of-bounds memory access.
        {
            for(int j=s[i-1]+1;j<s[i+1];j++) // @@ Relies on the flawed condition above and lacks boundary checks for i=0 or i=n-1, leading to out-of-bounds access and incorrect expansion.
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