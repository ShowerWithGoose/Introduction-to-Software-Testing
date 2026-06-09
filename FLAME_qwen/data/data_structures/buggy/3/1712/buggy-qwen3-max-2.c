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
printf("%c",s[++cnt]); // @@ [When the input is "0.0...", after incrementing cnt (which starts at 1), s[++cnt] may access beyond the first non-zero digit or even past the string length if all digits after decimal are zero, leading to undefined behavior or wrong output. Also, logic fails when there's only one zero after decimal like "0.1".]
printf(".");
for(int i=++cnt;i<len;i++) // @@ [The pre-increment changes cnt again, causing the loop to skip the next character after the first significant digit, resulting in missing digits in mantissa.]
{
    printf("%c",s[i]);
}
printf("e-");
printf("%d",cnt_2); // @@ [Exponent calculation is incorrect: for "0.001", it should be e-3, but cnt_2 counts leading zeros plus initial increment, which may not align with required exponent (should be number of leading zeros + 1).]
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
    printf("%d",cnt-1); // @@ [This works for numbers >= 1, but if input has no decimal point (though problem states it does), this would fail. However, per problem description input always has digits before and after decimal, so this part may be okay. But note: if input is like "123.45", cnt=3, exponent=2 which is correct. So likely not an error here. But combined with other issues in 'if' branch, overall program fails test cases.]
}
}