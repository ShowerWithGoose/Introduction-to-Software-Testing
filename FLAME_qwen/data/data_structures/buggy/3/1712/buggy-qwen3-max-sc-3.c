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
printf("%d",cnt_2); // @@ [Exponent should be cnt_2, but cnt_2 counts from index 2 onward including the first non-zero digit; actual exponent should be number of leading zeros after decimal + 1, but current logic miscounts due to pre-incrementing cnt before using it as index.]
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