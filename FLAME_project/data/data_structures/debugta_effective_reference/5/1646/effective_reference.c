#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long 
#define ull unsigned long long
ll read()
{
	ll x=0,fl=1;char st=getchar();
	while(st<'0'||st>'9'){ if(st=='-')fl=-1; st=getchar();}
	while(st>='0'&&st<='9') x=x*10+st-'0',st=getchar();
	return x*fl;
}
ll a[1005],b[1005],c[1005],d[1005];
ll n1,n2,n;
struct skr
{
    ll x,y;
}s[10000005];
char st[1000005];
ll cmp(const void *a,const void *b)
{
    struct skr c=*(struct skr *)a;
    struct skr d=*(struct skr *)b;
    return c.y>d.y?-1:1;
}
int main()
{
	gets(st);
	int l=strlen(st),op=1;
	for(int i=0;i<l;i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		{
			int g=st[i]-'0',j=i;
			while(j+1<l&&st[j+1]>='0'&&st[j+1]<='9')
			{
				j++;
				g=g*10+st[j]-'0';
				i=j;
			}
			if(op==1) a[++n1]=g,op^=1;
			else b[n1]=g,op^=1;
		}
	}
	gets(st);l=strlen(st),op=1;
	for(int i=0;i<l;i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		{
			int g=st[i]-'0',j=i;
			while(j+1<l&&st[j+1]>='0'&&st[j+1]<='9')
			{
				j++;
				g=g*10+st[j]-'0';
				i=j;
			}
			if(op==1) c[++n2]=g,op^=1;
			else d[n2]=g,op^=1;
		}
	}
	
    for(ll i=1;i<=n1;i++)
        for(ll j=1;j<=n2;j++)
        {
            s[++n].x=a[i]*c[j];
            s[n].y=b[i]+d[j];
        }
    qsort(s+1,n,sizeof(s[0]),cmp);
    for(ll i=1;i<=n;i++)
    {
        if(s[i].x==0) continue;
        while(s[i].y==s[i+1].y&&i+1<=n)
        {
            s[i+1].x+=s[i].x;
            s[i].x=0;
            i++;
        }
        printf("%lld %lld ",s[i].x,s[i].y);
    }
	return 0;
}

