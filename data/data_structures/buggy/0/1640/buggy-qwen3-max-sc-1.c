#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s); // @@ [Using 'gets' is unsafe and may cause buffer overflow; also, in some environments, 'gets' is removed from the standard library leading to compilation errors]
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); // @@ [Accesses s[i-1] and s[i+1] without checking bounds (e.g., when i=0 or i=strlen(s)-1), leading to undefined behavior; also logic is flawed because it prints the '-' character even in invalid expansion cases]
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) // @@ [Incorrect character range checks: 'a'-1 and 'z'+1 are not proper bounds; should use >= 'a' && <= 'z'; also accesses s[i-1]/s[i+1] without ensuring i>0 and i<strlen(s)-1]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) // @@ [Same issue as above: incorrect bounds and missing boundary checks for array access]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) // @@ [Same issue: '0'-1 and '9'+1 are not correct; should be >= '0' && <= '9'; also no bounds check on i]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
    }
    return 0;
}