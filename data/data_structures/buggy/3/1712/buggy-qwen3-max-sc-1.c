#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char s[100]="";
    char final[100]="";
    scanf("%s",s);
int len=strlen(s);
int cnt=0;
if(s[0]=='0')
{
    cnt++;
    for(int i=2;i<len;i++)
    {
        if(s[i]=='0')
        {
            cnt++;
        }
        else if(s[i]!='0'&&s[i]!='.')
        {
            break;
        }
    }
    int cnt_2=cnt;
printf("%c",s[++cnt]); // @@ [When the input is "0.0", this accesses s[2] which may be '\0', leading to undefined behavior or printing garbage. Also, logic fails when all digits after decimal are zero (though problem states no trailing zeros, but still fragile).]
printf(".");
for(int i=++cnt;i<len;i++)
{
    printf("%c",s[i]);
}
printf("e-");
printf("%d",cnt_2); // @@ [Exponent should be cnt_2 + 1, not cnt_2. For example, "0.001" has two leading zeros after decimal before '1', so exponent is -3, but cnt becomes 3 (initial cnt=1, then two more zeros), and cnt_2=3, so prints e-3 which is correct? Wait: initial cnt=1 (from cnt++), then loop from i=2: for "0.001", s[2]='0' → cnt=2, s[3]='0' → cnt=3, then s[4]='1' breaks. Then s[++cnt] = s[4] → correct. Exponent printed is cnt_2=3, but should be 3? Actually 0.001 = 1e-3, so exponent -3 is correct. But what about "0.1"? cnt starts at 1, loop i=2: s[2]='1' → break. cnt_2=1. Then s[++cnt]=s[2] → '1'. Output: "1.e-1" → but expected "1e-1" or "1.0e-1"? Problem says: if base is decimal, must have one digit before and after decimal. So "1." is invalid; must be "1.0" if there's a decimal? But input has no trailing zeros, so after decimal only significant digits. However, in "0.1", after moving decimal, we get "1" with nothing after, so should output "1e-1", not "1.e-1". So printing "." unconditionally is wrong.]
}
else{
    for(int i=0;i<len;i++)
    {
        if(s[i]=='.')
        {
            cnt=i;
            break;
        }
    }
    printf("%c",s[0]);
    printf("."); // @@ [Unconditionally prints a decimal point even if there are no digits after it in the normalized form. According to problem, if base is integer (only one significant digit), it should not have a decimal point. But here, even for input like "5", which isn't possible per problem (must have digits before and after decimal), but assuming input always has decimal point, then after normalization, if original was "123.45", we output "1.2345e2" — that's fine. However, if the number has only one digit before decimal originally, e.g., "5.67", then normalized is "5.67e0", but problem says: if only one digit before decimal in input, it can be 0 — but non-zero single digit is allowed. However, the issue is: what if after removing decimal, there are no extra digits? Not possible per input spec. But the bigger issue: the code always prints a decimal point, even when the normalized mantissa should be an integer (which per problem only happens when there's exactly one significant digit total — but input always has digits before and after decimal, so normalized form will always have more than one digit? Not necessarily: input "1.0" is disallowed (no trailing zeros), so minimal input like "1.2" → normalized "1.2e0". So maybe decimal point is always needed. However, consider input "5" — but problem states input has digits before and after decimal point, so this case won't occur. So maybe this is not the main error.]
    for(int i=1;i<len;i++)
    {
        if(s[i]!='.')
        {
            printf("%c",s[i]);
        }
    }
    printf("e");
    printf("%d",cnt-1); // @@ [If the input has no decimal point, this would be wrong, but problem states input has decimal point. However, if input is like "123", which violates problem constraints, but assuming valid input, cnt is set to position of '.', so for "123.45", cnt=3, exponent=2 → correct. So this seems okay.]
}
}