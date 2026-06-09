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
            num[k]=num[k]*10+s[i]-'0'; // @@ [Array `num` is not initialized to zero, so `num[k]` may contain garbage values when accumulating digits]

    }
}
int main()
{
    gets(s); // @@ [`gets` is unsafe and deprecated; may cause buffer overflow, but more critically, in many modern environments it's not available, causing compilation error]
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
            num[i+1]=num[i]/num[i+1]; // @@ [Division operands are reversed: should be `num[i] / num[i+1]` but used as `num[i] / num[i+1]` correctly? Wait: actually this is correct as written. But note: integer division is required, which C does for ints, so OK. However, the real issue is that after setting `num[i]=0`, later addition will ignore it, but the indexing assumes left-to-right without considering operator precedence properly across multiple * and /]
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
        else if(s[i]=='-') // @@ [Should be `sign[i]` instead of `s[i]`; using original string `s` which has been modified and doesn't align with current operator index]
        {
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[len_sign]);
    return 0;

}