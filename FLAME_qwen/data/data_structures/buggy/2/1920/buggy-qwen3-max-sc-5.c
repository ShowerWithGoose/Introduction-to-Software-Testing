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
            s[j]='\0'; // @@ [This line is not properly indented and is executed outside the loop; it should be inside the function block but after the loop. However, the real issue is that the loop body is missing braces, so only the first statement is in the loop. The assignment s[j]='\0' runs every iteration, corrupting the string.]
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
            num[k]=num[k]*10+s[i]-'0'; // @@ [num[k] is used uninitialized; it should be initialized to 0 before accumulating digits.]

    }
}
int main()
{
    gets(s); // @@ [gets() is unsafe and deprecated; more critically, it may not be available in some environments, leading to compilation error. Also, the input includes '=', which is not handled properly in parsing.]
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
            num[i+1]=num[i]/num[i+1]; // @@ [Division operands are reversed: should be num[i] / num[i+1], but here it's correct as written? Wait: actually, this is wrong because the expression is left-to-right, but the algorithm assumes num[i] is the left operand. However, due to prior accumulation, num[i] might be zero from previous operations. But more pressingly, integer division truncates toward zero, which is acceptable per problem. However, the real bug is in the order of evaluation and handling of operator precedence across passes.]
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
        else if(s[i]=='-') // @@ [Here it checks s[i] instead of sign[i]; should be sign[i]=='-' to match the operator array. This causes incorrect handling of subtraction.]
        {
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[len_sign]);
    return 0;

}