#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ch[100006];
int num[100005],tot;
int opt[100005];
signed main()
{
    gets(ch);
    int len=strlen(ch);
    for(int q=0;q<len;q++)
    {
        if(ch[q]>='0'&&ch[q]<='9')
        {
            int tmp=0;
            while(ch[q]>='0'&&ch[q]<='9')tmp=10*tmp+ch[q++]-'0';
            q--;
            num[tot++]=tmp;
        }
        else if(ch[q]=='-')  opt[tot]=1;
        else if(ch[q]=='*')
        {
            while(ch[q]<'0'||ch[q]>'9') q++;
            int tmp=0;
            while(ch[q]>='0'&&ch[q]<='9')tmp=10*tmp+ch[q++]-'0';
            q--;
            num[tot-1]*=tmp;
        }
        else if(ch[q]=='/')
        {
            while(ch[q]<'0'||ch[q]>'9') q++;
            int tmp=0;
            while(ch[q]>='0'&&ch[q]<='9')tmp=tmp*10+ch[q++]-'0';
            q--;
            num[tot-1]/=tmp;
        }
    }
    int ans=num[0];
    for(int q=1;q<tot;q++)
        if(opt[q])
            ans-=num[q];
        else
            ans+=num[q];
    printf("%d",ans);
}

