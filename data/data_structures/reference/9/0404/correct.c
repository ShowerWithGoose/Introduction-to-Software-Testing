#include<stdio.h>
#include<string.h>
struct lines {
	int startx;
	int starty;
	int finishx;
	int finishy;
} line[100],d;

void paixu(int n,struct lines line[],struct lines d) 
{
	
 int i,j,flag;
 for(i=0;i<n-1;i++)
 {
  flag=0;
  for(j=0;j<n-1-i;j++)
  {
   if(line[j].startx>line[j+1].startx)
   {
    d=line[j];
    line[j]=line[j+1];
    line[j+1]=d;
    flag=1;
   }
  }
  if(flag==0)
   {
    break;
   }
 }
}

int main()
{
	int i,j,k,q,n,flag=1,x,y,num=1,a,b;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&line[i].startx,&line[i].starty,&line[i].finishx,&line[i].finishy);
	}
	int cnt=i;
	for(i=0;i<n;i++)
	{
		a=line[i].finishx;
		b=line[i].finishy;
		flag=1;
		for(j=0;j<n;)
		{
			if(line[j].startx==line[i].finishx&&line[j].starty==line[i].finishy)
			{
				line[i].finishx=line[j].finishx;
				line[i].finishy=line[j].finishy;
				flag++;
				j=0;
			}
			else
			j++;
		}
		if(flag>num)
		{
		num=flag;
		x=line[i].startx;
		y=line[i].starty;	
		}
		line[i].finishx=a;
		line[i].finishy=b;
		
	}
	printf("%d %d %d",num,x,y);
 } 

