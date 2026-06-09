#include<stdio.h>
#include<stdlib.h>

struct node{
	int x1;
	int y1;
	int x2;
	int y2;
	int len;
};

typedef struct node point;
point line[1000];
point temp;
int flag;

int cmp(const void *p1,const void *p2)
{
	point *a = (point*)p1; 
	point *b = (point*)p2;
	return a->len - b->len;
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].len = 1;
	} 
	//按前端点排序 
	for(i=0;i<n;i++)
    {
        flag=0;
        for(j=i+1;j<n;j++)
        {
            if(line[j].x1<line[i].x1)
            {
                temp=line[j];
                line[j]=line[i];
                line[i]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
	//连接
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(line[i].x2==line[j].x1 && line[i].y2==line[j].y1)
			{
				line[i].x2 = line[j].x2;
				line[i].y2 = line[j].y2;
				line[i].len += 1;
				line[j].x1 = 0;
				line[j].y1 = 0;
			}	
		}	
	} 
	qsort(line,n,sizeof(point),cmp);
	printf("%d %d %d\n",line[n-1].len,line[n-1].x1,line[n-1].y1);
	return 0;
} 

