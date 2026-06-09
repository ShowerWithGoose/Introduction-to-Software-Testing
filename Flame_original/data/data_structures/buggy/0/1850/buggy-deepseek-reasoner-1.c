#include <stdio.h>
#include<string.h>
void pri(char *,int);
int main()
{
    char *s; // @@ [Uninitialized pointer: s is declared but not allocated memory, leading to undefined behavior when used in scanf.]
    scanf("%s",s); // @@ [Undefined behavior: writing to uninitialized pointer; also potential buffer overflow.]
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
        if(((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))&&s[i-1]<s[i+1]) // @@ [Logical error: condition does not correctly check that both characters are in the same range (e.g., lowercase, uppercase, digit). Should check both bounds for each type. Also possible out-of-bounds when i==0 (accessing s[-1]) or i==strlen(s)-1 (accessing s[i+1] which is null terminator).]
        {
            for(int j=s[i-1]+1;j<s[i+1];j++) // @@ [Loop condition j<s[i+1] prints up to but not including s[i+1], but then the next character is printed later; this works for simple cases but differs from the intended expansion (should be j<=s[i+1] and then skip the next character).]
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