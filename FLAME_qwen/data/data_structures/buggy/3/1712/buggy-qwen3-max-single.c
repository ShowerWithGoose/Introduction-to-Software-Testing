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
printf("%c",s[++cnt]); // @@ [When the input is "0.0", accessing s[++cnt] may go out of bounds or access '.'; also, logic fails when all digits after decimal are zero (though problem states no trailing zeros, but leading zeros case may still cause invalid index)]
printf(".");
for(int i=++cnt;i<len;i++)
{
    printf("%c",s[i]);
}
printf("e-");
printf("%d",cnt_2); // @@ [Exponent should be cnt_2, but cnt_2 counts from index 2 onward including the first non-zero digit; correct exponent for "0.00...X" is -(number of leading zeros after decimal + 1), but current cnt starts at 1 and increments per zero, so exponent is off by one]
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
    printf("%d",cnt-1); // @@ [This is correct for numbers like "123.45" -> exponent 2, but if input has no decimal point (though problem says it does), this would fail; however, problem states input always has digits before and after decimal, so this part may be okay. But note: if input is single digit like "5.6", cnt=1, exponent=0 which is correct. So likely not an error here. However, the real issue is in the 'if' branch.]
}
}