#include<stdio.h>
struct coor
{
	int x1;
	int y1;
	int x2;
	int y2;
}; 
struct coor c[100];
void swa(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int n,i=0,j=0,l=1,X,Y,Xh,Yh,max=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    scanf("%d%d%d%d",&c[i].x1,&c[i].y1,&c[i].x2,&c[i].y2);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(c[j].x2>c[j+1].x2)
			{
				swa(&c[j].x1,&c[j+1].x1);
				swa(&c[j].y1,&c[j+1].y1);
				swa(&c[j].x2,&c[j+1].x2);
				swa(&c[j].y2,&c[j+1].y2);
			}
		}
	}
//	for(i=0;i<n;i++)
//	    printf("%d %d %d %d\n",c[i].x1,c[i].y1,c[i].x2,c[i].y2);
	X=c[0].x2;Y=c[0].y2;
	Xh=c[0].x1;Yh=c[0].y1;
	for(i=0;i<n;i++)
	{
		X=c[i].x2;Y=c[i].y2;
		for(j=i+1;j<n;j++)
		if(X==c[j].x1&&Y==c[j].y1)
		{
			l++;
			X=c[j].x2;
			Y=c[j].y2;
			if(l>max)
			{
				Xh=c[i].x1;
				Yh=c[i].y1;
				max=l;
			}
		}
		l=1;
	}
	printf("%d %d %d",max,Xh,Yh);
	return 0;
}

