#include<stdio.h>
#include<string.h>

char s[10010];int n;
int cal(int l,int r)
{
    // printf("%d %d :: ",l,r);
    // for(int i=l;i<=r;i++)printf("%c",s[i]);
    // puts("");

    for(int i=r;i>=l;i--)
    {
        if(s[i]=='+')return cal(l,i-1)+cal(i+1,r);
        if(s[i]=='-')return cal(l,i-1)-cal(i+1,r);
    }
    int ans=0,now=0,typ=0;
    for(int i=l;i<=r;i++)
    {
        if(s[i]=='*')
        {
            if(typ==0)ans=now,now=0;
            if(typ==1)ans*=now,now=0;
            if(typ==2)ans/=now,now=0;
            typ=1;continue;
        }
        if(s[i]=='/')
        {
            if(typ==0)ans=now,now=0;
            if(typ==1)ans*=now,now=0;
            if(typ==2)ans/=now,now=0;
            typ=2;continue;
        }
        now=now*10+s[i]-'0';
        // printf("%d %d\n",ans,now);
    }
    if(typ==0)ans=now,now=0;
    if(typ==1)ans*=now,now=0;
    if(typ==2)ans/=now,now=0;
    return ans;
    // for(int i=l;i<=r;i++)
    // {
    //     if(s[i]=='*')return cal(l,i-1)*cal(i+1,r);
    //     if(s[i]=='/')return cal(l,i-1)/cal(i+1,r);
    // }
    // int ans=0,res=1;
    // for(int i=l;i<=r;i++)
    // {
    //     ans+=(s[i]-'0')*res;
    //     res*=10;
    // }
    // return ans;
}
signed main()
{
    // freopen("data.in","r",stdin);

    char t=getchar();
    while(1)
    {
        // printf("%c\n",t);
        while((t<'0'||t>'9')&&t!='+'&&t!='-'&&t!='*'&&t!='/'&&t!='=')t=getchar();
        if(t=='=')break;
        s[++n]=t;t=getchar();
    }
    // for(int i=1;i<=n;i++)printf("%c",s[i]);
    printf("%d\n",cal(1,n));
}
