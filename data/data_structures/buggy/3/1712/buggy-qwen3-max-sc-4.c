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
printf("%c",s[++cnt]); // @@ [Using pre-increment modifies cnt before accessing s[cnt], which may skip the first non-zero digit or access out-of-bounds if input is "0.0"]
printf(".");
for(int i=++cnt;i<len;i++) // @@ [Another pre-increment changes cnt again, causing incorrect loop start index and potentially skipping digits or going out of bounds]
{
    printf("%c",s[i]);
}
printf("e-");
printf("%d",cnt_2); // @@ [Exponent calculation is incorrect: for "0.00123", leading zeros after decimal are 2, so exponent should be -3, but cnt_2 counts from initial cnt=1 and increments per zero, yielding wrong value]
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
    printf("%d",cnt-1); // @@ [This is correct for numbers >= 1, but the overall logic fails to handle cases where input has no decimal point (though problem states it always has digits before and after)]
}
}