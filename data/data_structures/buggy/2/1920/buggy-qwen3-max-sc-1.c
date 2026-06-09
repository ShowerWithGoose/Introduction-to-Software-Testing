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
            s[j]='\0'; // @@ [This line is not properly indented and is executed outside the loop due to missing braces, causing incorrect string termination. The assignment s[j]='\0' should be inside the loop's block.]
}
void jishuqi(char s[])
{
    int i,j,k=0;
    int len=strlen(s);
    for(i=j=0;i<(len-1);i++) // @@ [Loop condition stops at len-1, which skips the last character. Since the input ends with '=', and we removed spaces, the last digit before '=' may be missed if it's a single digit at the end.]
    {
        if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/'))
        {
            sign[j++]=s[i];
            k++;
        }
        else if(isdigit(s[i]))
            num[k]=num[k]*10+s[i]-'0'; // @@ [num[k] is used without initialization; it may contain garbage values leading to incorrect number parsing.]

    }
}
int main()
{
    gets(s); // @@ [Use of gets() is unsafe and deprecated; however, the immediate error is logical, not compilation. But note: some compilers may refuse to compile gets(). However, the reported error is "gcc: not found", which is environment-related, but per problem context, we focus on logical bugs causing wrong output.]
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
            num[i+1]=num[i]/num[i+1]; // @@ [Division operands are reversed: should be num[i] / num[i+1], but here it's correct as written? Wait: actually, this is WRONG: it should be num[i] / num[i+1], but the code does num[i]/num[i+1] — that part is correct. However, the issue is that after setting num[i]=0, later addition will ignore it, but the order of operations is being handled by zeroing and changing op to '+', which is okay. BUT: the real bug is in the subtraction handling below.]
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
        else if(s[i]=='-') // @@ [BUG: should check sign[i] == '-', not s[i] == '-'. s[i] refers to original string which has been processed and may not align with current index i in the sign array. This causes incorrect detection of minus operator.]
        {
            num[i+1]=num[i]-num[i+1]; // @@ [Even if the condition were correct, the operation is applied left-to-right without considering that previous multiplications/divisions have zeroed earlier terms. Also, the logic for accumulation is flawed because it overwrites num[i+1] without preserving intermediate results correctly.]
        }
    }
    printf("%d",num[len_sign]); // @@ [The final result is taken as num[len_sign], but due to the flawed processing (especially with subtraction using s[i] instead of sign[i]), and incorrect accumulation, this value is wrong. Additionally, if there are no operators, len_sign=0, then num[0] is printed, which is okay, but the prior logic breaks for mixed operators.]
    return 0;

}