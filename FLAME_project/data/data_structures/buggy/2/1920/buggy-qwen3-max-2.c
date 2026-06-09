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
            s[j]='\0'; // @@ [The indentation suggests this line is inside the if, but it's actually outside due to missing braces. This causes incorrect string termination during space deletion.]
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
            num[k]=num[k]*10+s[i]-'0'; // @@ [num[k] is not initialized to 0 before accumulation, leading to garbage values when building multi-digit numbers.]

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
        else if(s[i]=='-') // @@ [This should be 'sign[i]' instead of 's[i]'. Using 's[i]' accesses the original (space-deleted) string at index i, which may not correspond to the current operator in the processed expression.]
        {
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[len_sign]); // @@ [After processing all operations, the final result should be in num[0], not num[len_sign]. The algorithm overwrites subsequent num entries but doesn't consolidate into a single result correctly. Also, the loop logic for addition/subtraction is flawed as it doesn't propagate the result forward properly.]
    return 0;

}