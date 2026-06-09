#include<stdio.h>
int h[11],n,l[11];
void lss(int p,int q)
{
	int i;
	h[p]=1;
	l[q]=p;
	if(q==n)
	{
		for(i=1;i<=n;i++)
			printf("%d ",l[i]);
		printf("\n");	
	}
	for(i=1;i<=n;i++)
		if(h[i]==0)
			lss(i,q+1);
	h[p]=0;
} 
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) lss(i,1);
}

