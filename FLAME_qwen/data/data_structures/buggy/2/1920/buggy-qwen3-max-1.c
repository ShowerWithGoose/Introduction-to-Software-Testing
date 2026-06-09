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
    gets(s); // @@ [Use of unsafe function 'gets' which can cause buffer overflow; however, the immediate error is logical, not compilation. But note: some compilers may warn or error if strict standards are enforced.]
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
            num[i+1]=num[i]/num[i+1]; // @@ [Division operands are reversed; should be num[i] / num[i+1], but here it's written correctly. However, note that in the reference program there was an error like this, but here it appears correct. Wait: actually, this line is correct as written. But later subtraction uses wrong index.]
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
        else if(s[i]=='-') // @@ [Should be 'sign[i]' instead of 's[i]'; using original string 's' which has been modified and doesn't align with current operator position.]
        {
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[len_sign]); // @@ [After processing, the result may not always be at num[len_sign]; due to zeroing out earlier values and shifting logic, the final result might be elsewhere. Also, if all operators are * or /, the accumulation in the second loop may not work correctly because '+' was substituted but not handled in sequence properly.]
    return 0;

}