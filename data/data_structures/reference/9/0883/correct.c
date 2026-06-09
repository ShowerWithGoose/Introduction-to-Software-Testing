#include <stdio.h>
#include <stdlib.h>

struct line{
	int x1,y1,x2,y2;
}li[120];
struct group{
	int x1,y1,x2,y2,num;
}g[120];

int com_line(const void *,const void *);  //升序 
int com_group(const void *,const void *);    //降序 
void create(int,int);  //新的一组线 
int find(int,int);    //从已有线段中查找 
void connect(int,int);    //和已有线段连接 

int main()
{
	int i=0,n,t;
	int sum=0;  //组数 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d%d%d%d",&li[i].x1,&li[i].y1,&li[i].x2,&li[i].y2);
	
	qsort(li,n,sizeof(li[0]),com_line);
	
	for(i=0;i<110;i++)
	g[i].num=0;
	
	i=0;
	while(i<n){
		if(i==0){
			create(0,sum);  sum++;
		}
		else{
			t=find(i,sum);
			if(t<sum){
				connect(i,t);
			}
			else{
				create(i,sum);  sum++;
			}
		}
		i++;
	}
	qsort(g,sum+1,sizeof(g[0]),com_group); 
	printf("%d %d %d",g[0].num,g[0].x1,g[0].y1);
	return 0;	
}  

int com_line(const void *a,const void *b)//升序
{
	return (*(struct line *)a).x1-(*(struct line *)b).x1;
}

int com_group(const void *a,const void *b)  //降序 
{
	return (*(struct group *)b).num-(*(struct group *)a).num;
}

void create(int i,int sum)
{
	g[sum].x1=li[i].x1;  g[sum].y1=li[i].y1;
	g[sum].x2=li[i].x2;  g[sum].y2=li[i].y2;
	g[sum].num++;
}
 
int find(int i,int sum)
{
	int k;
	for(k=0;k<sum;k++)
	if(li[i].x1==g[k].x2&&li[i].y1==g[k].y2)
	break;
	return k;
}

void connect(int i,int k)
{
	g[k].x2=li[i].x2;  g[k].y2=li[i].y2;
	g[k].num++;
}

