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
printf("%c",s[++cnt]); // @@ [Using pre-increment modifies cnt before accessing s[cnt], which may skip the first non-zero digit or access out-of-bounds if all digits after decimal are zero. Also, if input is "0.0", this leads to undefined behavior.]
printf(".");
for(int i=++cnt;i<len;i++) // @@ [Another pre-increment on cnt changes its value again, causing the loop to start at an incorrect index and potentially skip digits or go out of bounds.]
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
    printf("e"); // @@ [Missing '+' for positive exponents as per specification: "If it’s non-negative, it appears without the + sign" — but note: the spec says *without* '+', so this is actually correct. However, the bigger issue is that when the number has only one digit before '.', e.g., "5.67", the output becomes "5.67e0", but expected is "5.67e0" — acceptable. But if input is integer like "123", the code fails because there's no '.' in input, so cnt remains uninitialized (actually, it stays 0 from earlier), leading to wrong exponent. The loop may not find '.' and cnt stays 0, then exponent becomes -1, which is wrong.]
    printf("%d",cnt-1);
}
}