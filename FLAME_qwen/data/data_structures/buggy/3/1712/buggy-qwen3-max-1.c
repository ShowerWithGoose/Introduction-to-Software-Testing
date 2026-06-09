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
printf("%c",s[++cnt]); // @@ [If the input is "0.0", this will access s[2] which may be '\0', leading to undefined behavior or printing garbage. Also, logic fails when all digits after decimal are zero (though problem states no trailing zeros, but still fragile).]
printf(".");
for(int i=++cnt;i<len;i++)
{
    printf("%c",s[i]);
}
printf("e-");
printf("%d",cnt_2); // @@ [Exponent calculation is incorrect: for "0.00123", leading zeros count is 2, exponent should be -3, but cnt starts at 1 and increments per zero, so cnt_2 becomes 3, which is correct, BUT if input is "0.1", cnt=1 initially, loop doesn't run, cnt_2=1, then s[++cnt] = s[2] which is '1' — okay, exponent e-1 is correct. However, if input is "0.01", cnt starts 1, loop runs once (i=2, s[2]=='0'), cnt becomes 2, cnt_2=2, then s[++cnt]=s[3] — correct. BUT if input has no non-zero digit (invalid per problem, but code doesn't validate), it breaks. Main issue: ++cnt modifies cnt before use, making indexing error-prone and inconsistent with cnt_2 meaning.]
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
    printf("%d",cnt-1); // @@ [This prints exponent correctly for numbers >=1, e.g., "123.45" -> cnt=3, exponent=2. But output format requires that if base has only one digit and no fractional part, it should be integer without decimal point. However, program always prints "X.YYY", violating requirement: "If it’s an integer, it contains only one significant digit without a decimal point." For example, input "5" should output "5e0", but this outputs "5.e0" — invalid scientific notation per problem spec.]
}
}