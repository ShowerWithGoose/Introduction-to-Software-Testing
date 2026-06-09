#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ Uninitialized pointer, should be declared as an array (e.g., char s[100]) to allocate memory for input.
    scanf("%s",s); // @@ Writing to an uninitialized pointer causes undefined behavior and likely a segmentation fault.
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ Incorrect logic for checking same character type; does not verify both characters are within the same range, and accesses s[i-1] when i=0 causing out-of-bounds.
        {
            for(int j=s[i-1]+1;j<s[i+1];j++) // @@ Loop condition j<s[i+1] excludes the end character of the range; should be j<=s[i+1] to fully expand it.
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