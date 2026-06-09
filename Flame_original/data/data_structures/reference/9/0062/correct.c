#include<stdio.h>
int x[109][10];
int main()
{
	int i,j,k,num=0/*有几个结果*/,cnt=0,n,check=0/*检查是否连上*/,x1,x2,y1,y2;//x1 [0] y1 1  x2 2  y2 3  次数 4		 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	
		check=0;	
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(i==0)
		{ 
			x[0][0]=x1;
			x[0][1]=y1;
			x[0][2]=x2;
			x[0][3]=y2;
			x[0][4]++;
		}
		else
		{
			for(j=0;j<=num;j++)
			{
				if(x1==x[j][2]&&y1==x[j][3])//如果连上1
				{
					check=1;
					x[j][2]=x2;
					x[j][3]=y2;
					x[j][4]++;
					break;
				}
				else if(x2==x[j][0]&&y2==x[j][1])//如果连上2 
				{
					check=1;
					x[j][0]=x1;
					x[j][1]=y1;
					x[j][4]++;
					break;
				} 				
			}
			if(check==0)//没链接上
			{	
				num++;
				x[num][0]=x1;
				x[num][1]=y1;
				x[num][2]=x2;
				x[num][3]=y2;
				x[num][4]++;		
			}  	
					
		}
		
	}
	
		for(i=0;i<=num;i++)//重新筛选
		{
			for(j=0;j<=num;j++)
			{
				if(i!=j)
				{
					if(x[i][0]==x[j][2]&&x[i][1]==x[j][3])//如果连上1
				{
					x[i][0]=x[j][0];
					x[i][1]=x[j][1];
					x[i][4]+=x[j][4];
					for(k=j;k<=num-1;k++)
					{
						x[k][0]=x[k+1][0];
						x[k][1]=x[k+1][1];
						x[k][2]=x[k+1][2];
						x[k][3]=x[k+1][3];
						x[k][4]=x[k+1][4];
					}
					num--;
				}
				else if(x[i][2]==x[j][0]&&x[i][3]==x[j][1])//如果连上2 
				{
					x[i][2]=x[j][2];
					x[i][3]=x[j][3];
					x[i][4]+=x[j][4];
					for(k=j;k<=num-1;k++)
					{
						x[k][0]=x[k+1][0];
						x[k][1]=x[k+1][1];
						x[k][2]=x[k+1][2];
						x[k][3]=x[k+1][3];
						x[k][4]=x[k+1][4];
					}
					num--;
				} 					
				}
			
			}
		}
	
	cnt=x[0][4];          
	for(i=0;i<=num;i++)
	{
		if(cnt<x[i][4])
		{
			cnt=x[i][4];
		}
	}
	for(i=0;i<=num;i++)
	{
		if(x[i][4]==cnt)
		{
			printf("%d %d %d",x[i][4],x[i][0],x[i][1]);
			break; 
		}
	}
	
	return 0;
	
}



