#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-') printf("%c",s[i]); // @@ The original condition `s[i]!='-'||s[i-1]>=s[i+1]` is incorrect because when `s[i]=='-'`, accessing `s[i-1]` (if i==0) or `s[i+1]` might be invalid or the logic short-circuits incorrectly. More importantly, if it is a '-', we need to check validity before deciding to print '-' or expand. The current logic prints the character immediately if it's not '-', OR if the chars are invalid order. But if it IS '-', it falls through to the else-if blocks. However, if the type check fails in the else-if blocks, nothing is printed for the '-'. This leads to missing output for invalid ranges like 'B-e'.
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
        }
        else printf("%c", s[i]); // @@ If the character is '-' but does not meet any of the expansion criteria (e.g., different types like 'B' and 'e', or invalid order), the '-' itself must be printed. The original code lacks this else clause, causing the '-' to be omitted in the output for cases like "B-e".
    }
    return 0;
}