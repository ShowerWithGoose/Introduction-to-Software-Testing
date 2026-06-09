#include<stdio.h>
#include<string.h>
int main()
{
	int a,x1[105],y1[105],x2[105],y2[105];
	int i,j,b[305][305],k=1,l=1,n,p=0;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(j=0;j<a;j++,k=1)
	{
		n=j;
		for(i=0;i<a;i++)
		{
			if(x2[n]==x1[i]&&y2[n]==y1[i])
			{
				n=i;
				i=-1;
				k++;
			}
		}
		if(k>l)
		{
			l=k;
			p=j;
			}	
	}
	printf("%d %d %d",l,x1[p],y1[p]);
	return 0;
}

