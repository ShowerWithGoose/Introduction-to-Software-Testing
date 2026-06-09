#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct zuobiao
{
  int x1;
  int y1;
  int x2;
  int y2;
  int temp;	
  int num;
  int cnt;
};
int main()
{
	int n,i,j,x,y,m,duan,z;
	struct zuobiao xian[120]; 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&xian[i].x1,&xian[i].y1,&xian[i].x2,&xian[i].y2);
	}
	for(i=0;i<n;i++)
	{
	 xian[i].temp=0;
		xian[i].num=120;
		xian[i].cnt=1;
	}
	for(j=0;j<n;j++)
	{
	  for(i=0;i<n;i++)
	  {
	    if(xian[j].x1==xian[i].x2&&xian[j].y1==xian[i].y2)	
	    {
	    xian[j].temp=1;
	    xian[i].num=j;
	    }	
      }
	} 
	for(x=0;x<n;x++)
	{
		if(xian[x].temp==0)
		{
			m=xian[x].num;
		  	while(m!=120)
		  	{
		  	  xian[x].cnt++;
				m=xian[m].num;	
			}
		}
	} 
	duan=xian[0].cnt;
	z=0;
	for(y=1;y<n;y++)
	{
	  if(duan<xian[y].cnt)
	  {
	  duan=xian[y].cnt;	
	  z=y;
      }
	}
	printf("%d %d %d",duan,xian[z].x1,xian[z].y1);
	return 0;
}


















