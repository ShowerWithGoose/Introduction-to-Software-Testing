#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); // @@ When i=0, s[i-1] accesses out-of-bounds memory. Also, the condition s[i-1]>=s[i+1] is evaluated even when s[i] is not '-', which is incorrect; the logic should only check expansion conditions when s[i]=='-'.
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) // @@ The conditions use <'z'+1 and >'a'-1 which are always true for any character, failing to properly restrict to lowercase letters. Should use >= 'a' and <= 'z'.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) // @@ Same issue as above: conditions are too broad and do not correctly check uppercase letter range.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) // @@ Same issue: conditions are too broad and do not correctly check digit range.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
    }
    return 0;
}