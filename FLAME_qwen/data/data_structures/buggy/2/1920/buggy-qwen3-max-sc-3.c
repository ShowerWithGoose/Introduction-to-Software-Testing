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
            s[j]='\0'; // @@ [The indentation suggests this line is outside the for-loop, but it should be inside. However, due to C's syntax, this line is actually executed after the loop, which is correct. But the real issue is that 'gets' is unsafe and may not be available in modern compilers, causing compilation error. Also, 'isdigit' requires <ctype.h> which is included, so that's fine. The main compilation error likely stems from use of 'gets' which is removed in C11 and later.]
}
void jishuqi(char s[])
{
    int i,j,k=0;
    int len=strlen(s);
    for(i=j=0;i<(len-1);i++) // @@ [Loop runs until len-1, skipping last character. Since input ends with '=', this skips the '=' correctly, but logic for parsing numbers is flawed: 'num[k]' is never initialized to 0 before accumulating digits, leading to garbage values. However, this is a runtime logic error, not compilation. The actual compilation error is due to 'gets'.]
    {
        if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/'))
        {
            sign[j++]=s[i];
            k++;
        }
        else if(isdigit(s[i]))
            num[k]=num[k]*10+s[i]-'0'; // @@ [num[k] is used uninitialized; should be set to 0 before this loop starts for each new number. But again, this is runtime, not compilation.]

    }
}
int main()
{
    gets(s); // @@ [Use of 'gets' causes compilation error in modern C standards (C11+), as it's been removed due to security issues. This is the primary reason for "gcc: not found" or compilation failure in strict environments.]
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
            num[i+1]=num[i]/num[i+1]; // @@ [Division operands are reversed: should be num[i] / num[i+1], but here it's written correctly as num[i]/num[i+1]. Wait: no, it's correct. But note: integer division is required, which is default for int. However, order is correct here.]
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
        else if(s[i]=='-') // @@ [Bug: should check sign[i] instead of s[i]. This uses original string s which has been modified and may not align. Should be 'sign[i] == '-''. This causes wrong operation selection. But again, this is runtime logic error, not compilation.]
        {
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[len_sign]);
    return 0;

}