#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); // @@ Error: When i=0, s[i-1] accesses index -1, which is out of bounds. Also, the condition s[i-1]>=s[i+1] is evaluated even when s[i] is not '-', causing unnecessary out-of-bounds access.
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) // @@ Error: When i is at the last index, s[i+1] accesses index strlen(s), which is out of bounds. Also, the condition does not check that both characters are lowercase letters; it only checks ranges that include other characters.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) // @@ Error: Same out-of-bounds issue as above. Also, the condition does not ensure both characters are uppercase letters; it includes characters outside [A-Z].
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) // @@ Error: Same out-of-bounds issue. Also, the condition does not ensure both characters are digits; it includes characters outside [0-9].
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
    }
    return 0;
}