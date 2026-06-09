#include <stdio.h>

struct zuobiao{
	int x1;
	int y1;
	int x2;
	int y2;
}xianduan[100];

void paixu(struct zuobiao a[],int n);

int main()
{
	int n;
	int finalx,finaly;
	scanf("%d",&n);
	int i,j,num,max,k,z;
	num=1,max=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&xianduan[i].x1,&xianduan[i].y1,&xianduan[i].x2,&xianduan[i].y2);	
	}
	paixu(xianduan,n);
	for(i=0;i<n;i++)
	{
		z=i;
		num=0;
		for(j=i+1;j<n;j++)
		{
			if((xianduan[z].x2==xianduan[j].x1)&&(xianduan[z].y2==xianduan[j].y1))
			{
				num++;
				z=j;
			}
		}
		if(num>max)
		{
			max=num;
			finalx=xianduan[i].x1;
			finaly=xianduan[i].y1;
		}
	}
	printf("%d %d %d",max+1,finalx,finaly);	
} 
void paixu(struct zuobiao a[],int n)
{
	int i,j;
	struct zuobiao x;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(xianduan[j].x1>xianduan[j+1].x1)
			{
				x=xianduan[j];
				xianduan[j]=xianduan[j+1];
				xianduan[j+1]=x;
			}
		} 
	} 
}

