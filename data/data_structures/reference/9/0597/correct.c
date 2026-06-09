#include<stdio.h>
#include<string.h>
struct line{
	int lx;
	int ly;
	int rx;
	int ry;
}z[200];
int p[200];
void swap(int *a,int *b);
int main()
{
    int i,j,k,n,wx,wy,nx=0,ny=0,num=0,res=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d%d%d%d",&z[i].lx,&z[i].ly,&z[i].rx,&z[i].ry);
    for(i=1;i<=n;i++)
    p[i]=i;
    for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
    swap(&p[i],&p[j]);
    for(i=1;i<=n;i++)
	{
		num=1;
		wx=z[p[i]].rx;
		wy=z[p[i]].ry;
		for(j=i+1;j<=n;j++)
		{
			if(z[p[j]].lx==wx&&z[p[j]].ly==wy)
			{
				num++;
				wx=z[p[j]].rx;
				wy=z[p[j]].ry;
			}
		}
		if(num>res)
		{
			res=num;
			nx=z[p[i]].lx;
			ny=z[p[i]].ly;
		}
	 } 
	 printf("%d %d %d",res,nx,ny);
}
void swap(int *a,int *b)
{
	int tmp;
	if(z[*a].lx>z[*b].lx)
	{
		tmp=*a;
		*a=*b;
		*b=tmp;
	}
}

