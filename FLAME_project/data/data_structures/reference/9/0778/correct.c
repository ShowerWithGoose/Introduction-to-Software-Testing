#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct LINE{
	int x1;
	int y1;
	int x2;
	int y2;
	int flag;
}line[105]; 
int cmp(const void *x,const void *y);

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].flag=0;
	}
	qsort(line,n,sizeof(line[0]),cmp); 
	
	/*for(int i=0;i<n;i++)
	{
		printf("%d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2);
		line[i].flag=0;
	}*/
	
	struct LINE result;
	result.x1=line[0].x1;
	result.x2=line[0].x2;
	result.y1=line[0].y1;
	result.y2=line[0].y2;
	result.flag=1;
	
	for(int j=0;j<=n-1;j++)
	{
		if(line[j].flag==0)
		{
			struct LINE smooth;
			smooth.x1=line[j].x1;
			smooth.x2=line[j].x2;
			smooth.y1=line[j].y1;
			smooth.y2=line[j].y2;
			smooth.flag=1;
			line[j].flag=1;
			for(int i=j+1;i<=n-1;i++)
			{
				if(line[i].flag==0)
				{
					if(line[i].x1==smooth.x2&&line[i].y1==smooth.y2)
					{
						smooth.x2=line[i].x2;
						smooth.y2=line[i].y2;
						line[i].flag=1;
						smooth.flag++;
					}
				}
			}
			if(smooth.flag>result.flag)
			{
				result.x1=smooth.x1;
	            result.x2=smooth.x2;
	            result.y1=smooth.y1;
               	result.y2=smooth.y2;
             	result.flag=smooth.flag;
			}
		}
	}
	printf("%d %d %d",result.flag,result.x1,result.y1);
	return 0;
 } 
 
int cmp(const void *x,const void *y){
	return ((*(struct LINE *)x).x1 - (*(struct LINE *)y).x1);
}


