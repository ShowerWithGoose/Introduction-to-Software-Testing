#include<stdio.h>
#include<string.h>
#define int long long
char ch[1000005];
int ans[100005],mi1[100005],i,n;
int ans2[100005],mi2[100005];
int ans3[100005],mi[100005];
int pre[100005],bac[100005],x;
signed main()
{
	while(1)
	{
		scanf("%lld%lld",&ans[++i],&mi1[i+1]);
		char ch=getchar();
		if(ch=='\n')	break;
	}
	while(1)
	{
		scanf("%lld%lld",&ans2[++n],&mi2[n+1]);
		char ch=getchar();
		if(ch=='\n')	break;
	}
	for(int o=1;o<=i;o++)
		for(int q=1;q<=n;q++)
			ans3[++x]=ans[o]*ans2[q],mi[x]=mi1[o]+mi2[q];
	for(int o=1;o<=x;o++)
		pre[o]=o-1,bac[o]=o+1;
	pre[1]=bac[x]=0;
	for(int o=1;o<=x;o++)
	{
		int st=o;while(pre[st])	st=pre[st];
		for(;st;st=bac[st])
		{
			int x=st,y=bac[st];
			if(mi[x]<mi[y])
				bac[pre[x]]=y,pre[bac[y]]=x,pre[y]=pre[x],bac[x]=bac[y],pre[x]=y,bac[y]=x;
		}
		pre[0]=bac[0]=0;
	}
	int o=1;
	while(pre[o])	o=pre[o];
	for(;o;o=bac[o])
		while(bac[o]&&mi[o]==mi[bac[o]])
			ans3[o]+=ans3[bac[o]],bac[o]=bac[bac[o]],pre[bac[bac[o]]]=o;
	pre[0]=bac[0]=0;
	o=1;
	while(pre[o])	o=pre[o];
	for(;o;o=bac[o])
		printf("%lld %lld ",ans3[o],mi[o]);
	printf("\n");
}

