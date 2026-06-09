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
            s[j]='\0'; // @@ Missing braces for the if statement; this line executes unconditionally in every loop iteration, which is logically flawed and inefficient.
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
} // @@ The sign array is not null-terminated here, causing undefined behavior when strlen is called on it later.
int main()
{
    gets(s); // @@ gets is deprecated and unsafe, prone to buffer overflow; fgets should be used instead.
    del(s,' ');
    jishuqi(s);
    int len_sign=strlen(sign); // @@ sign array lacks a null terminator, so strlen will read past its bounds, resulting in an incorrect length.
    for(int i=0;i<len_sign;i++)
    {
        if(sign[i]=='*')
        {
            num[i+1]=num[i]*num[i+1];
            num[i]=0; // @@ Zeroing out num[i] destroys the left operand needed for subsequent + and - accumulation, leading to incorrect results.
            sign[i]='+';
        }
        else if(sign[i]=='/')
        {
            num[i+1]=num[i]/num[i+1];
            num[i]=0; // @@ Same issue: zeroing num[i] breaks the sequential addition/subtraction logic.
            sign[i]='+';
        }
    }
    for(int i=0;i<len_sign;i++)
    {
        if(sign[i]=='+')
        {
            num[i+1]=num[i]+num[i+1];
        }
        else if(s[i]=='-') // @@ Should be sign[i]=='-', currently checks the original string s instead of the operator array sign.
        {
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[len_sign]);
    return 0;

}