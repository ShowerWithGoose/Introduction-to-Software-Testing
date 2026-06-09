#include<stdio.h>
#include<stdlib.h>
typedef struct line{
	int startx;
	int starty;
	int endx;
	int endy;
	int sum;
}line; 
line a[105];
line temp;
int main()
{	
	int cnt=0,k=0,i,j;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d %d %d %d",&temp.startx,&temp.starty,&temp.endx,&temp.endy);
		for(j=0;j<cnt;j++)
		{
			if(temp.startx==a[j].endx&&temp.starty==a[j].endy)
			{
				a[j].sum++;
				a[j].endx=temp.endx;
				a[j].endy=temp.endy;
				break;
			}
			else if(temp.endx==a[j].startx&&temp.endy==a[j].starty)
			{
				a[j].sum++;
				a[j].startx=temp.startx;
				a[j].starty=temp.starty;
				break;
			}			
		}
		if(j==cnt)
		{
			a[cnt]=temp;
			a[cnt].sum=1;
			cnt++;
		}
	}
	int flag=1;
	while(flag)
	{
		flag=0;
		for(j=0;j<cnt;j++)
		{
			for(i=j+1;i<cnt;i++)
			{
				if(a[i].endx==a[j].startx&&a[i].endy==a[j].starty)
				{
					a[j].sum+=a[i].sum;
					a[j].startx=a[i].startx;
					a[j].starty=a[i].starty;
					for(k=i+1;k<cnt;k++)
						a[k-1]=a[k];
					cnt--;
					flag=1;	
				}	
				else if(a[i].startx==a[j].endx&&a[i].starty==a[j].endy)
				{
					a[j].sum+=a[i].sum;
					a[j].endx=a[i].endx;
					a[j].endy=a[i].endy;
					for(k=i+1;k<cnt;k++)
						a[k-1]=a[k];
					cnt--;
					flag=1;	
				}
			}	
		}	
	}	
	int max=0,id;
	for(i=0;i<cnt;i++)
		if(max<a[i].sum)
		{
			max=a[i].sum;
			id=i;
		}	
	printf("%d %d %d",a[id].sum,a[id].startx,a[id].starty);
	return 0;
}


