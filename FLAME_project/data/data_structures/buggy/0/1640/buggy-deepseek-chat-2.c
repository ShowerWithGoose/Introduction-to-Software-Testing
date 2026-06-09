#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); // @@ When i=0, s[i-1] accesses s[-1] which is out-of-bounds. Also, the condition s[i-1]>=s[i+1] is evaluated even when s[i] is not '-', causing incorrect skipping of characters. The logic should first check if s[i] is '-', then check bounds and conditions.
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) // @@ The condition s[i-1]<'z'+1 is always true for any char less than '{', and s[i-1]>'a'-1 is always true for any char greater than '`'. This does not correctly restrict to lowercase letters. Should use s[i-1]>='a' && s[i-1]<='z' and similarly for s[i+1].
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) // @@ Same issue as above: conditions are too broad. Should use s[i-1]>='A' && s[i-1]<='Z' and similarly for s[i+1].
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) // @@ Same issue: conditions are too broad. Should use s[i-1]>='0' && s[i-1]<='9' and similarly for s[i+1].
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
    }
    return 0;
}