#include<stdio.h>
#include<string.h>
char str[1000000];
int ch[1000000],num[1000000];
int main()
{
    gets(str);
    int len=strlen(str),sum=0,fh=0,sz=0,ans=1;
    for(int i=0;i<len;i++)
    {
        while(str[i]==' '||str[i]=='\t'||str[i]=='\n')i++;
        while(str[i]<='9'&&str[i]>='0')
        {
            sum=sum*10+str[i]-'0';
            i++;
        }
        num[++sz]=sum;sum=0;
        while(str[i]==' '||str[i]=='\t'||str[i]=='\n')i++;
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        {
            ch[++fh]=i;
        }
    }
    for(int i=1;i<=fh;i++)
    if(str[ch[i]]=='*')
    {
        ans=num[i]*num[i+1];
        num[i]=0,num[i+1]=ans;
        if(i!=1)str[ch[i]]=str[ch[i-1]];
        else str[ch[i]]='+';
    }
    else if(str[ch[i]]=='/')
    {
        ans=num[i]/num[i+1];
        num[i]=0,num[i+1]=ans;
        if(i!=1)str[ch[i]]=str[ch[i-1]];
        else str[ch[i]]='+';
    }
    ans=num[1];
    for(int i=1;i<=fh;i++)
    if(str[ch[i]]=='-')
    {
        ans-=num[i+1];
    }
    else 
    {
        ans+=num[i+1];
    }
    printf("%d",ans);
    return 0;
}


