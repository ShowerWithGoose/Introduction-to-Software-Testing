#include<stdio.h>
#include<stdlib.h>
struct l
{
	int qx,qy,zx,zy;
}line[105];
int cmp(const void *a, const void *b) {
	struct l *aa = (struct l *)a;
	struct l *bb = (struct l *)b;
	if ( (*aa).qx > (*bb).qx ) return 1;
	return -1;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].qx,&line[i].qy,&line[i].zx,&line[i].zy);
	}
	qsort(line,n,sizeof(line[0]),cmp);
	int num=0,tx,ty;
	for(i=0;i<n;i++)
	{
		int num1=1,x,y;
		int j;
		x=line[i].zx;
		y=line[i].zy;
		for(j=i+1;j<n;j++)
		{
			if(line[j].qx==x&&line[j].qy==y)
			{
				num1++;
				x=line[j].zx;
				y=line[j].zy;
			}
		}
		if(num1>num)
		{
			num=num1;
			tx=line[i].qx;
			ty=line[i].qy;
		}
	}
	printf("%d %d %d",num,tx,ty);
	return 0;
} 

