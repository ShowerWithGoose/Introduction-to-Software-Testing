#include<stdio.h>
#include<string.h>
#define int long long
char ch[1000005];
int num1[100005],mi1[100005],n1,n2;
int num2[100005],mi2[100005];
int num[100005],mi[100005];
int pre[100005],bac[100005],tot;
signed main()
{
	while(1)
	{
		scanf("%lld%lld",&num1[++n1],&mi1[n1+1]);
		char ch=getchar();
		if(ch=='\n')	break;
	}
	while(1)
	{
		scanf("%lld%lld",&num2[++n2],&mi2[n2+1]);
		char ch=getchar();
		if(ch=='\n')	break;
	}
	for(int q=1;q<=n1;q++)
		for(int w=1;w<=n2;w++)
			num[++tot]=num1[q]*num2[w],mi[tot]=mi1[q]+mi2[w];
	for(int q=1;q<=tot;q++)
		pre[q]=q-1,bac[q]=q+1;
	pre[1]=bac[tot]=0;
	for(int q=1;q<=tot;q++)
	{
		int st=q;while(pre[st])	st=pre[st];
		for(;st;st=bac[st])
		{
			int x=st,y=bac[st];
			if(mi[x]<mi[y])
				bac[pre[x]]=y,pre[bac[y]]=x,pre[y]=pre[x],bac[x]=bac[y],pre[x]=y,bac[y]=x;
		}
		pre[0]=bac[0]=0;
	}
	int q=1;
	while(pre[q])	q=pre[q];
	for(;q;q=bac[q])
		while(bac[q]&&mi[q]==mi[bac[q]])
			num[q]+=num[bac[q]],bac[q]=bac[bac[q]],pre[bac[bac[q]]]=q;
	pre[0]=bac[0]=0;
	q=1;
	while(pre[q])	q=pre[q];
	for(;q;q=bac[q])
		printf("%lld %lld ",num[q],mi[q]);
	printf("\n");
}

