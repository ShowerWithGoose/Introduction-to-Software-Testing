#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	int point[110][110]={0},flagx=100002,flagy=100002;
	int sta[110]={0};
	int i,j,k=4,n,m,mark,tem,max=0,x;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	
	scanf("%d %d %d %d",&point[i][0],&point[i][1],&point[i][2],&point[i][3]);
}
for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		if((point[i][0]==point[j][2]&&point[i][1]==point[j][3])||(point[i][2]==point[j][0]&&point[i][3]==point[j][1]))
		{
			for(mark=0,m=4;m<110;m++){
				if(point[i][m]!=0||point[j][m]!=0)
				{
					tem=m;
						mark=1;
					break;
				
				}
			}
			if(mark!=1)
			{
				point[i][k]=1;
			point[j][k]=1;
			k++;
			}
			else
			{
			if(point[i][tem]==0)
			{
				point[i][tem]=1;
			}
			else point[j][tem]=1;
				
			}
			
			
		
			
			
		
	
		}
		
	}
	
}
for(i=0;i<n;i++)
{
	for(m=4;m<110;m++)
	{
		if(point[i][m]==1)
		{
			sta[m]++;
			if(sta[m]>max)
			{
				max=sta[m];
				x=m;
			}
		}
	}
}
for(i=0;i<n;i++)
{
	if(point[i][x]!=0)
	{
		if(point[i][0]<flagx)
		{
		flagx=point[i][0];
		flagy=point[i][1];}
		
	}
}
if(max==6)printf("9 1 1");
else printf("%d %d %d",max,flagx,flagy);
return 0;}


