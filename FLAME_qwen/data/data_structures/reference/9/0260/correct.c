#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,m;
	scanf("%d",&n);
	int x1[205],y1[205],x2[205],y2[205];
	int a2,b2,l=1,len[105],max,pd=0,op=1;
	//读数据 
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]); 
	}
	//遍历 
	for(i=0;i<n;i++)
	{
		op=1;
		a2=x2[i];
		b2=y2[i];//连续线段的右端 
		l=1;
		pd=0;
		while(pd<n)
		{
			for(j=0;j<n;j++)
		{	
				if(a2==x1[j]&&b2==y1[j])
			{
				a2=x2[j];
				b2=y2[j];
				l++;			
			}
		 } 
		 pd++;
		}
		len[i]=l; 
	}
	max=len[0];
	for(i=0;i<n;i++)
	{
		if(max<=len[i])
		{
		max=len[i];
		a2=x1[i];
		b2=y1[i];			
		}
	}
	printf("%d %d %d",max,a2,b2);
	return 0;
}








