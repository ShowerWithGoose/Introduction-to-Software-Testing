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
printf("%c",s[++cnt]); // @@ [When the input is "0.0...", after incrementing cnt (which starts at 1), s[++cnt] may access beyond the first non-zero digit or even out-of-bounds if all digits after decimal are zero, but problem states there are no trailing zeros and at least one non-zero digit exists. However, more critically, if the number is like "0.1", then initial cnt=1, ++cnt becomes 2, and s[2] is '1' — this seems okay. But logic is fragile and inconsistent with reference. The real issue is that cnt counts leading zeros INCLUDING the '0' before decimal, but then uses pre-increment incorrectly. Also, if input is "0.0001", cnt becomes 4 (after loop), then s[++cnt] = s[5], which is correct, but the initial cnt++ before loop already counted the '0' before '.', so total leading zeros after decimal is cnt-1. This leads to wrong exponent.]
printf(".");
for(int i=++cnt;i<len;i++) // @@ [Here, cnt is incremented again, skipping one extra character. For "0.001", after previous line, cnt was 3 (pointing to '1'), now ++cnt makes it 4, so loop starts at index 4, missing the '1'. This causes missing digits in mantissa.]
{
    printf("%c",s[i]);
}
printf("e-");
printf("%d",cnt_2); // @@ [Exponent should be (number of leading zeros after decimal + 1). But cnt_2 includes the initial '0' before decimal (due to cnt++ before loop), so for "0.001", cnt_2=3, but correct exponent is -3, which matches. However, due to earlier indexing errors, mantissa is wrong even if exponent is accidentally correct in some cases. But more importantly, if input is "0.1", cnt_2=1, exponent=-1, which is correct, but mantissa printing fails because of double increment. So the core error is in index manipulation, not just exponent.]
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
    printf(".");
    for(int i=1;i<len;i++)
    {
        if(s[i]!='.')
        {
            printf("%c",s[i]);
        }
    }
    printf("e");
    printf("%d",cnt-1); // @@ [This is correct for numbers >= 1. For example, "123.45" has cnt=3 (index of '.'), exponent=2, which is right. So no error here.]
}
}