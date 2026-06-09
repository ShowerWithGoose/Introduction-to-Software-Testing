#include <stdio.h>
int ans[100];
int main()
{
	int num,i,j,k;
	scanf("%d",&num);
	struct loca{
		int qix;
		int qiy;
		int zhx;
		int zhy;
	};
	struct loca di[100];
	struct locan{
		int qix;
		int qiy;
	};
	struct locan shuchu[100];
	for(i=0;i<=num-1;i++)
	{
		scanf("%d %d %d %d",&di[i].qix,&di[i].qiy,&di[i].zhx,&di[i].zhy);
	}//∂¡»Î 
	for(i=0;i<=num-1;i++)
	{
		for(j=0;j<=num-i-1;j++)
		{
			if(di[j].qix>di[j+1].qix)
			{
				int temp;
				temp=di[j].qix;
				di[j].qix=di[j+1].qix;
				di[j+1].qix=temp;
				temp=di[j].qiy;
				di[j].qiy=di[j+1].qiy;
				di[j+1].qiy=temp;
				temp=di[j].zhx;
				di[j].zhx=di[j+1].zhx;
				di[j+1].zhx=temp;
				temp=di[j].zhy;
				di[j].zhy=di[j+1].zhy;
				di[j+1].zhy=temp;
			}
			if(di[j].qix==di[j+1].qix&&di[j].zhx>di[j+1].zhx)
			{
				int temp;
				temp=di[j].qix;
				di[j].qix=di[j+1].qix;
				di[j+1].qix=temp;
				temp=di[j].qiy;
				di[j].qiy=di[j+1].qiy;
				di[j+1].qiy=temp;
				temp=di[j].zhx;
				di[j].zhx=di[j+1].zhx;
				di[j+1].zhx=temp;
				temp=di[j].zhy;
				di[j].zhy=di[j+1].zhy;
				di[j+1].zhy=temp;
			}
		}
	}//≈≈–Ú  
	int count;
	for(i=0;i<=num-2;i++)
	{
		for(j=i+1;j<=num-1;j++)
		{
			if(di[count].zhx==di[j].qix&&di[count].zhy==di[j].qiy)
			{
				ans[i]++;
				count=j;			
			}
		}
		count=i+1;
	}
	for(i=0;i<=num-2;i++)
	{
		for(j=i;j<=num-1;j++)
		{
			if(ans[i]<=ans[j])
			{
				int temp;
				temp=ans[i];
				ans[i]=ans[j];
				ans[j]=temp;
				temp=di[i].qix;
				di[i].qix=di[j].qix;
				di[j].qix=temp;
				temp=di[i].qiy;
				di[i].qiy=di[j].qiy;
				di[j].qiy=temp;
			}
		}
	}	
	printf("%d %d %d",ans[0]+2,di[0].qix,di[0].qiy);
	return 0;
} 

