#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-') printf("%c",s[i]); // @@ The original condition `s[i]!='-'||s[i-1]>=s[i+1]` is incorrect because when `s[i]=='-'`, accessing `s[i-1]` (if i==0) or `s[i+1]` might be invalid or the logic short-circuits incorrectly. More importantly, if it is a '-', we need to check validity before deciding to print '-' or expand. The current logic prints the character immediately if it's not '-', which is fine, but the `else if` chain below assumes `s[i]=='-'`. However, the first `if` handles non-'-' chars. The issue is that if `s[i]=='-'`, the first `if` is false, so it goes to `else if`. But the first `if` also includes `s[i-1]>=s[i+1]`. If `s[i]=='-'` and `s[i-1]>=s[i+1]`, it prints `s[i]` (the '-'). This part is actually logically okay for printing the dash if expansion is not needed. BUT, there is a boundary error: if `i==0`, `s[i-1]` is accessed. Also, if `i==strlen(s)-1`, `s[i+1]` is accessed.
        else if(i > 0 && i < strlen(s) - 1 && s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) // @@ Added bounds check `i > 0 && i < strlen(s) - 1` to prevent out-of-bounds access. The original code accesses `s[i-1]` and `s[i+1]` without checking if `i` is at the boundaries. For input "B-e", `i` will be 1. `s[0]='B'`, `s[2]='e'`. The check `s[i-1]<'z'+1...` checks if 'B' is lowercase. It is not. So this block is skipped.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(i > 0 && i < strlen(s) - 1 && s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) // @@ Added bounds check. Checks if both are uppercase. 'B' is uppercase, 'e' is not. Skipped.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(i > 0 && i < strlen(s) - 1 && s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) // @@ Added bounds check. Checks if both are digits. Skipped.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else printf("%c", s[i]); // @@ If none of the expansion conditions are met (and it is a '-'), we must explicitly print the '-' character. The original code falls through without printing anything if it's a '-' but doesn't match any expansion criteria, resulting in missing output for the '-' itself.
    }
    return 0;
}