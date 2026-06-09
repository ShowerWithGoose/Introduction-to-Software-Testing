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
            s[j]='\0'; // @@ [Logic error: Missing braces for the if statement. The line s[j]='\0' executes unconditionally after the loop, but more importantly, the logic inside the loop is flawed because only s[j++]=s[i] is conditional. However, the critical bug causing the wrong answer is elsewhere. This line is technically executed every iteration of the loop if braces are missing, which corrupts the string. But let's look at the main logic first.]
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
    gets(s);
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
            num[i+1]=num[i]/num[i+1];
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
        else if(s[i]=='-') // @@ [Variable error: The code checks s[i] (the original input string character) instead of sign[i] (the operator array). After the first loop, sign[i] might have been changed to '+', but s[i] still holds the original operator. However, the logic for subtraction should depend on the current state of the operator list or the original operator. Since sign[i] was updated to '+' for * and /, checking sign[i] for '-' is correct for the remaining operators. Checking s[i] is risky if indices don't align perfectly, but here the main issue is that it should be sign[i] to be consistent with the previous loop's modifications, or simply check if the operator is '-'. Given sign[i] retains '-' if it wasn't * or /, checking sign[i] is the intended logic.]
        {
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[len_sign]);
    return 0;

}