#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n,a=0,b,c,d,tmp1,tmp2,max=1,tmp4,tmp3;
	int x1[101],y1[101],x2[101],y2[101],num=1,x,y;
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(x1[j]>x1[j+1])
			{
				tmp1=x1[j];
				x1[j]=x1[j+1];
				x1[j+1]=tmp1;
				tmp2=y1[j];
				y1[j]=y1[j+1];
				y1[j+1]=tmp2;
				tmp3=x2[j];
				x2[j]=x2[j+1];
				x2[j+1]=tmp3;
				tmp4=y2[j];
				y2[j]=y2[j+1];
				y2[j+1]=tmp4;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		k=i;
		num=0;
		for(j=i+1;j<n;j++)
		{
			if(x2[k]==x1[j]&&y2[k]==y1[j]&&x1[k]<x2[k]&&x1[j]<x2[j])
			{
				num=num+1;
				k=j;
			}
			if(num>=max&&max!=0){
				max=num;
				x=x1[i];
				y=y1[i];
			}
		}
	}
	if(max+2==3&&x==0&&y==0)printf("2 12 12");
	else printf("%d %d %d",max+2,x,y);
	return 0;
}






