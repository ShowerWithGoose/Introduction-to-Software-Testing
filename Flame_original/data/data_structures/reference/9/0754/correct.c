#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct line{
	int a,b,x,y;
}line;
int cmp(const void *c,const void *d)
{
	return (*(line*)c).a>(*(line*)d).a?1:-1;
}
int main()
{
	int i,j,k,n,max=1,num,fx,fy;
	line s[200];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d%d%d%d",&s[i].a,&s[i].b,&s[i].x,&s[i].y);
	qsort(s,n,sizeof(s[0]),cmp);
	for(i=0;i<n;i++)
	{
		k=i;
		num=1;
		for(j=i+1;j<n;j++)
		{
			if(s[k].x==s[j].a&&s[k].y==s[j].b)
			{
				num++;
				k=j;
			}
		}
		if(num>max)
		{
			max=num;
			fx=s[i].a;
			fy=s[i].b;
		}
	}
	printf("%d %d %d",max,fx,fy);
	return 0;
}



