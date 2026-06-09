#include<stdio.h>  
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct _line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
	int flag;
}line[120];
struct _line *p=line;
int n,x,y;
void cal(struct _line *,int,int,int);
int main()
{  scanf("%d",&n);
int i;
for(i=0;i<n;i++) 
  {
  	scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	line[i].num=1;
	line[i].flag=0;
  }
  for(i=0;i<n;i++)
  {
  	x=line[i].x2,y=line[i].y2;
	cal(line,i,x,y);
  }
  int max=line[0].num,maxx=line[0].x1,maxy=line[0].y1;
  for(i=0;i<n;i++)
  {
  	if(line[i].num>max)
  	{
  		max=line[i].num,maxx=line[i].x1,maxy=line[i].y1;
	  }
  }
  printf("%d %d %d\n",max,maxx,maxy);
    return 0;  
}
void cal(struct _line *p,int i,int x,int y)
{  int j;
    line[i].flag=1;
	
		for(j=0;j<n;j++)
		{
			if(line[j].flag==0&&x==line[j].x1&&y==line[j].y1)
			{
				line[i].num++;
				line[j].flag=1;
				
				cal(line,i,line[j].x2,line[j].y2);
				line[j].flag=0;
			}
		}
	line[i].flag=0;
	return;
}


