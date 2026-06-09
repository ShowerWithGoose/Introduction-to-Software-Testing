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
printf("%c",s[++cnt]); // @@ Error: This increments cnt before using it, causing the wrong character to be printed. For input "0.9", cnt starts at 1, then becomes 2, printing s[2] which is '9', but the logic is flawed because cnt is modified inconsistently with the counting.
printf(".");
for(int i=++cnt;i<len;i++) // @@ Error: cnt is incremented again, skipping the character after the first non-zero digit. For "0.9", after previous increment cnt=2, then becomes 3, so the loop starts at i=3 which is beyond the string length, printing nothing after the decimal point.
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