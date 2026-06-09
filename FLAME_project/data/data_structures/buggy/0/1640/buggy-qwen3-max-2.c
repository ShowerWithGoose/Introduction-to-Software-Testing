#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); @@ [This condition accesses s[i-1] and s[i+1] without checking bounds; when i=0, s[i-1] is out of bounds, and when i is the last index, s[i+1] is out of bounds. Also, it fails to check if both characters around '-' are of the same valid type (e.g., lowercase, uppercase, digit).]
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) @@ [The range checks are too permissive: 'a'-1 is '`' and 'z'+1 is '{', so this includes non-lowercase characters like '`' or '{'. Should use >= 'a' && <= 'z'. Also, no validation that both sides are actually lowercase letters before expanding.]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) @@ [Same issue as above: 'A'-1 is '@' and 'Z'+1 is '[', so non-uppercase characters may be included. Should use >= 'A' && <= 'Z'.]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) @@ [Same issue: '0'-1 is '/' and '9'+1 is ':', so non-digit characters like '/' or ':' may be accepted. Should use >= '0' && <= '9'. Additionally, even if types match, the program doesn't ensure that the left character is strictly less than the right one in a way that guarantees expansion only when valid (though the first condition tries, it's flawed due to boundary issues).]
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
    }
    return 0;
}