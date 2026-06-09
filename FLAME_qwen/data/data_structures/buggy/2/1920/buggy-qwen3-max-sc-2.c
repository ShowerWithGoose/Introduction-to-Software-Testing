#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[100];
char sign[100];
int num[100];
int sum;
void del(char s[],char key)
{
    int i,j;
    for(i=j=0;s[i]!='\0';i++)
        if(s[i]!=key)
            s[j++]=s[i];
            s[j]='\0'; // @@ [Missing braces around multi-line if body causes incorrect logic; the line `s[j]='\0';` is not part of the loop body due to missing braces, leading to premature termination of string]
}
void jishuqi(char s[])
{
    int i,j,k=0;
    int len=strlen(s);
    for(i=j=0;i<(len-1);i++)
    {
        if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/'))
        {
            sign[j++]=s[i];
            k++;
        }
        else if(isdigit(s[i]))
            num[k]=num[k]*10+s[i]-'0';

    }
}
int main()
{
    gets(s); // @@ [Use of unsafe `gets()` function which is deprecated and may cause buffer overflow; however, the immediate error in test execution is likely due to compilation environment, but logically this is a flaw]
    del(s,' ');
    jishuqi(s);
    int len_sign=strlen(sign);
    for(int i=0;i<len_sign;i++)
    {
        if(sign[i]=='*')
        {
            num[i+1]=num[i]*num[i+1];
            num[i]=0;
            sign[i]='+';
        }
        else if(sign[i]=='/')
        {
            num[i+1]=num[i]/num[i+1]; // @@ [Incorrect operand order: should be `num[i] / num[i+1]` but stored into `num[i+1]`, yet here it's assigned as `num[i]/num[i+1]` which is correct mathematically, BUT the bigger issue is that after setting `num[i]=0`, later addition will ignore it. However, the real critical error is in the next loop]
            num[i]=0;
            sign[i]='+';
        }
    }
    for(int i=0;i<len_sign;i++)
    {
        if(sign[i]=='+')
        {
            num[i+1]=num[i]+num[i+1];
        }
        else if(s[i]=='-') // @@ [Should be `sign[i]` instead of `s[i]`; using `s[i]` accesses original string which has been modified and doesn't reflect current operator, causing wrong operation or undefined behavior]
        {
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[len_sign]);
    return 0;

}