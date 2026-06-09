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
            s[j]='\0';
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
            num[i]=-1;
        }
        else if(sign[i]=='/')
        {
            num[i+1]=num[i]/num[i+1];
            num[i]=-1;
        }
    }
    for(int i=0,j=0,k=0;i<=len_sign;i++)
    {
        if(num[i]!=-1)
            num[j++]=num[i];
        if(sign[i]=='+'||sign[i]=='-')
            sign[k++]=sign[i];
            sign[k]='\0';
    }
    int len=strlen(sign);
    for(int i=0;i<len;i++)
    {
        if(sign[i]=='+')
        {
            num[i+1]=num[i]+num[i+1];
        }
        else if(sign[i]=='-')
        {
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[len]);
    return 0;

}



