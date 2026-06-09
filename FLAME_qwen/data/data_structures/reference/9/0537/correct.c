#include<stdio.h>
struct xianduan
{
	int sx;
	int sy;
	int ex;
	int ey;
};
int main()
{
  int n,i,j,k=0;
  int max=0;
  int p=0;
  int flag=0;
  int count[500];
  int zuob[500][100];
  struct xianduan zuobiao[500];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  	for(j=0;j<4;j++)
  	{
  		scanf("%d",&zuob[i][j]);
	}
  }
  for(i=0;i<n;i++)
  {
  	for(j=0;j<n,j!=i;j++)
  	{
  	  if(zuob[i][0]==zuob[j][2]&&zuob[i][1]==zuob[j][3])
	  {
	  	flag=1;
	  	break;
	  }	
	}
	if(flag==0)
    {
  	  zuobiao[p].sx=zuob[i][0];
  	  zuobiao[p].sy=zuob[i][1];
  	  zuobiao[p].ex=zuob[i][2];
  	  zuobiao[p].ey=zuob[i][3];
  	  p++;
    }
	flag=0;	
  }
  for(i=0;i<p;i++)
  {
  	count[i]=1;
  }
  for(i=0;i<p;i++)
  {
  	for(j=0;j<n;j++)
  	{
  	  if(zuobiao[i].ex==zuob[j][0]&&zuobiao[i].ey==zuob[j][1])
  	 {
  	   zuobiao[i].ex=zuob[j][2];
  	   zuobiao[i].ey=zuob[j][3];
	   count[i]++;
	   j=-1;	
	 }	
	}
  }
  for(i=0;i<p;i++)
  {
  	if(count[i]>max)
  	{
  	  max=count[i];
	  k=i;	
	}
  }
  printf("%d %d %d",max,zuobiao[k].sx,zuobiao[k].sy);
  return 0;
}

