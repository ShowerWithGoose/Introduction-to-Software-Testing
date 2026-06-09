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
printf("%c",s[++cnt]); // @@ Error: This increments cnt before using it, causing the wrong character to be printed. For input "0.9", cnt starts at 1, then becomes 2, printing s[2] which is '9', but the '.' at index 1 is skipped. Should print s[cnt] without pre-increment.
printf(".");
for(int i=++cnt;i<len;i++) // @@ Error: This further increments cnt, skipping the character after the first non-zero digit. For "0.9", cnt becomes 3, which is out of bounds (len=3), so nothing is printed after the decimal point. Should use i = cnt_2 + 1 or similar.
{
    printf("%c",s[i]);
}
printf("e-");
printf("%d",cnt_2);
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
    printf("%d",cnt-1);
}
}