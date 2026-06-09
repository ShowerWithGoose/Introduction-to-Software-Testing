#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); // @@ [For i=0, s[i-1] accesses out-of-bounds memory; also this condition does not handle the case where s[i]=='-' and left and right are of different types but left<right, leading to missing '-' output.]
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1)
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1)
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1)
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        } // @@ [After this chain, there is no else clause to print the '-' character when none of the expansion conditions are met. For input "B-e", the '-' is silently skipped, causing output "Be" instead of "B-e".]
    }
    return 0;
}