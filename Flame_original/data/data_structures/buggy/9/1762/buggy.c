#include <stdio.h> 
#include<string.h>
#include<stdlib.h>

typedef struct coordinate{
int x1;
int y1;
int x2;
int y2;
}coordinate;


int cmp(const coordinate *p1,const coordinate *p2);

int main()
{
int n,i,j,k;
coordinate a[105];
int flag,max=1;
int p,q;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
}
qsort(a,n,sizeof(coordinate),cmp);
for(i=0;i<n;i++)
{
	flag=1;
	for(j=i+1,k=i;j<n;j++)
	{
		if((a[i].x2==a[j].x1)&&(a[i].y2==a[j].y1))
		{
			flag++;
			i=j;
		}
	}
	i=k;
	if(flag>max)
	{
		max=flag;
		p=a[i].x1;
		q=a[i].y1;
	}
}
printf("%d %d %d\n",max,p,q);
return 0;
}
int cmp(const coordinate *p1,const coordinate *p2)
{
	return -((p1->x1)<(p2->x1));
}

