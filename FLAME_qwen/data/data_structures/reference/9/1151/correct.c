#include<stdio.h>
#include<math.h>
int x1[105],x2[105],yy1[105],y2[105];
int bac[105];
signed main()
{
	int n;
	scanf("%d",&n);
	for(int q=1;q<=n;q++)
		scanf("%d%d%d%d",&x1[q],&yy1[q],&x2[q],&y2[q]);
	for(int q=1;q<=n;q++)
		for(int w=1;w<=n;w++)
		{
			if(q==w)
				continue;
			else if(x2[q]==x1[w]&&y2[q]==yy1[w])
				bac[q]=w;
		}
	int ans=0,tag;
	for(int q=1;q<=n;q++)
	{
		int tmp=1,k=q,w=q;
		while(bac[w])
			w=bac[w],tmp++;
		if(tmp>ans)	ans=tmp,tag=q;
	}
	printf("%d %d %d\n",ans,x1[tag],yy1[tag]);
}
