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
printf("%c",s[++cnt]); // @@ This prints the first non-zero digit correctly, but the next line always prints a decimal point even when there are no digits after it.
printf("."); // @@ The problem requires that if the base is an integer (i.e., only one significant digit and nothing after), then no decimal point should be printed. For input "0.9", output should be "9e-1", not "9.e-1".
for(int i=++cnt;i<len;i++)
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
    printf("."); // @@ Similarly, this always prints a decimal point even if there are no fractional digits or if the number should be represented as an integer base (though per problem description, inputs have digits before and after decimal, so this may not trigger WA in provided test case).
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