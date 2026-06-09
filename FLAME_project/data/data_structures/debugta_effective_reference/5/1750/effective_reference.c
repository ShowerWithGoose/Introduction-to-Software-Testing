#include<stdio.h>
#include<string.h>

struct dxs
{
	int x;
	int z;
}first[1000],second[1000],sum[10005];

int main()
{
	char ch,ch2;int i,j,m,n,h,o,p,w;
	do 
	{
		scanf("%d%d",&first[i].x,&first[i].z);
		i++;
	}while((ch=getchar())!='\n');
	do
	{
		scanf("%d%d",&second[j].x,&second[j].z);
		j++;
	}while((ch2=getchar())!='\n');
	int chx,chz,num=0;
	for(m=0;m<i;m++)
	{
		for(n=0;n<j;n++)
		{
			
			chx=first[m].x*second[n].x;
			chz=first[m].z+second[n].z;
			for(h=0;h<i*j;h++)
			{
				if(h==num) 
				{
					num++;
					sum[h].x =chx;
					sum[h].z =chz;
					break;
				}
				if(sum[h].z==chz) 
				{
					sum[h].x+=chx;
					break;
				}
				if(sum[h].z<chz)
				{
					num++;
					for(o=num;o>h;o--)
					{
						sum[o].x =sum[o-1].x ;
						sum[o].z =sum[o-1].z ;	
					}
					sum[h].x =chx;
					sum[h].z =chz;
					break;
				}
			}
		}
	}
	while(sum[w].x!=0)
	{
		printf("%d %d ",sum[w].x,sum[w].z);
		w++;
	}
 } 


