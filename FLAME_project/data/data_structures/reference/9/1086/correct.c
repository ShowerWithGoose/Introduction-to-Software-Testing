#include<stdio.h>
#include<string.h>
struct cord
{
	int x1;
	int y1;
	int x2;
	int y2;
};
int flag[110];
int main()
{
	int n;
	int i,j,k,max,maxi;
	struct cord point[110];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&point[i].x1,&point[i].y1,&point[i].x2,&point[i].y2);
	}
	struct cord tmp;
    for(i=0; i<n; i++)
    for(j=i; j<n; j++)
	{
        if(point[i].x1>point[j].x1)
        {
            tmp=point[i];
            point[i]=point[j];
            point[j]=tmp;
        }
    }
	for(i=0;i<n;i++)
	{
		for(flag[i]=1,k=i,j=i+1;j<n;j++)
		{
			if(point[k].x2==point[j].x1&&point[k].y2==point[j].y1)
			{
				flag[i]++;
				k=j;
			}
			
		}
	}
	max=flag[0];
	maxi=0;
	for(i=1;i<n;i++)
	{
		if(flag[i]>max)
		{
			max=flag[i];
			maxi=i;
		}
	}
	printf("%d %d %d",max,point[maxi].x1,point[maxi].y1);
	return 0;
} 

