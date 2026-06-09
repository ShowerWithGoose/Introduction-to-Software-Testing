#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); // @@ [This condition accesses s[i-1] and s[i+1] without checking if i is within valid bounds (e.g., i=0 leads to s[-1], and i=strlen(s)-1 leads to reading beyond the string). Also, it fails to verify that both sides of '-' are of the same character type before comparing them.]
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) // @@ [The range checks are overly permissive: 'a'-1 is '`' and 'z'+1 is '{', so this includes non-lowercase characters like '`' or '{'. It should strictly check >= 'a' && <= 'z'. Same issue applies to uppercase and digit checks below.]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) // @@ [Same as above: uses 'A'-1 and 'Z'+1 which include non-uppercase characters. Should use >= 'A' && <= 'Z'.]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) // @@ [Same issue: '0'-1 is '/' and '9'+1 is ':', so it includes non-digit characters like '/' or ':'. Should use >= '0' && <= '9'.]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
    }
    return 0;
}