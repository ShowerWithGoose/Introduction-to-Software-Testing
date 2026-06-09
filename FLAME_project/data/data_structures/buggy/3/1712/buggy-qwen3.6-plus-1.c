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
printf("%c",s[++cnt]); // @@ The logic here prints the first significant digit. For input "0.9", cnt is 0 initially. The loop doesn't run because s[2] is out of bounds or not '0'. Then s[++cnt] accesses s[1] which is '.', wait. Let's trace "0.9". len=3. s[0]='0', s[1]='.', s[2]='9'.
// Inside if(s[0]=='0'): cnt becomes 1. Loop i=2. s[2]='9'. Condition s[i]=='0' false. Condition s[i]!='0' && s[i]!='.' true. Break.
// cnt_2 = 1.
// printf("%c", s[++cnt]); -> cnt becomes 2. s[2] is '9'. Prints '9'. Correct so far.
printf("."); // @@ This line unconditionally prints a decimal point. According to the problem, if the base is an integer (only one significant digit), it should NOT have a decimal point. For "0.9", the result is "9e-1", not "9.e-1". We need to check if there are any digits after the first significant digit to decide whether to print the dot.
for(int i=++cnt;i<len;i++) // @@ cnt is now 2. ++cnt makes it 3. i=3. len=3. Loop doesn't run. This part handles trailing digits after the first significant one.
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