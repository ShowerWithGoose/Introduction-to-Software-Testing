#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); // @@ [Accesses s[i-1] and s[i+1] without checking bounds (e.g., when i=0 or i=strlen(s)-1), leading to undefined behavior]
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) // @@ [Incorrect character range checks: 'a'-1 and 'z'+1 are not safe; should use >= 'a' && <= 'z']
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) // @@ [Same issue: incorrect range checks using 'A'-1 and 'Z'+1 instead of proper bounds]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) // @@ [Same issue: '0'-1 and '9'+1 are invalid for digit range validation]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
    }
    return 0;
}