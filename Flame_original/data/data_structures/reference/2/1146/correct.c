#include<stdio.h>
#include<string.h>
char ch[1000005];
int num[1000005],temp,i,j,k,n;

int main()
{
    gets(ch);
    for(i=0;ch[i]!='=';i++)
    {
        if(ch[i]>='0'&&temp==0)//数字
        {
            num[j++]=ch[i]-'0';
            temp=1;
        }
        else if(ch[i]>='0'&&temp==1)//进位
        {
            num[j-1]*=10;
            num[j-1]=num[j-1]+ch[i]-'0';
        }
        else if(ch[i]>='*')//符号
        {
            temp=0;
            ch[k++]=ch[i];
        }
    }
    ch[k]='=';

    n=k-1;
    for(k=0;k<=n;k++)//*&/
    {
        if(ch[k]=='*')
        num[k+1]*=num[k];
        else if(ch[k]=='/')
        num[k+1]=num[k]/num[k+1];
    }
    temp=0;
    i=1;
    k=0;
    while(ch[k]!='=')
    {
        if(ch[k]=='+')
        {
            temp=temp+i*num[k];
            i=1;
        }
        else if(ch[k]=='-')
        {
            temp=temp+i*num[k];
            i=-1;
        }
        k++;
    }
    temp+=i*num[k];

    printf("%d",temp);

}
