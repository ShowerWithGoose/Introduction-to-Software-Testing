#include <stdio.h>
#include <string.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main() 
{
	int x1[102],y1[102],x2[102],y2[102],n,i,k=1,j,flag[102]={0},group[102]={0},i1,max,id=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	for(i=1;k;i++)
	{
		k=0;
		for(j=1;j<n;j++)
		{
			if(x1[j]>x1[j+1])
			{
				swap(&x1[j],&x1[j+1]);
				swap(&y1[j],&y1[j+1]);
				swap(&x2[j],&x2[j+1]);
				swap(&y2[j],&y2[j+1]);
				k=1;
			}
		}
	}
	
	for(i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			group[i]+=1; 
			i1=i;
			for(j=i+1;j<=n;j++)
			if(x2[i1]==x1[j]&&y2[i1]==y1[j])
				{
					i1=j;
					flag[j]=1;
					group[i]+=1;
				}
		}
	}
	max=0;
	for(i=1;i<=n;i++)
	if(group[i]>max)
	{
	max=group[i];
	id=i;
	}
	printf("%d %d %d",group[id],x1[id],y1[id]);
}


