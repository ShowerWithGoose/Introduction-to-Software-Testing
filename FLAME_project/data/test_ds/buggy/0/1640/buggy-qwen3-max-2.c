#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); // @@ The condition `s[i-1]>=s[i+1]` does not check if both characters are of the same type (e.g., both lowercase, uppercase, or digits). Also, when i=0, s[i-1] accesses invalid memory (s[-1]).
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) // @@ The bounds `'a'-1` and `'z'+1` are too permissive; they include non-lowercase characters like '{' or '`'. Should use `>= 'a' && <= 'z'`.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) // @@ Same issue: `'A'-1` and `'Z'+1` allow non-uppercase characters. Should strictly check `>= 'A' && <= 'Z'`.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) // @@ Same issue: `'0'-1` and `'9'+1` include non-digit characters. Should use `>= '0' && <= '9'`.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
    }
    return 0;
}