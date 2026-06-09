#include<stdio.h>
#include<stdlib.h>
int n;//条数
 typedef struct lines
 {	int x1;
 	int y1;
 	int x2;
 	int y2; 
 }line;
 typedef struct numbers
 { int num;//线段计数 
 	int l;//存最左端点的线段编号 
 	
 }number;
 number num[105];
 	line seg[105];
 	int i,j,k;
 	//int num[105];
 	int maxnum;
 	int left,right,sign,leftmax;
int main()
 	{scanf("%d\n",&n);
 	for(i=1;i<=n;i++)
 	scanf("%d%d%d%d",&seg[i].x1,&seg[i].y1,&seg[i].x2,&seg[i].y2);
 	
 	for(i=1;i<=n;i++)//从第一个向后遍历，找到最长的，包含的线段置0
	  { left=right=i;//左右相同
	  	num[i].l=i; 
	  	for(j=1;j<=n;j++)
	  	{ 	
		  if(seg[right].x2==seg[j].x1&&seg[right].y2==seg[j].y1)//向右 
	  			{num[i].num++;
	  			right=j;
	  			j=0;
	  			
	  			} 
	  		else if(seg[left].x1==seg[j].x2&&seg[left].y1==seg[j].y2)//向左 
	  			{num[i].num++;
				num[i].l=j;
	  			left=j;
	  			j=0;
	  			}
	  		
	  	}
	  }
	  
 	for(i=1;i<=n;i++)
 	{if(num[i].num>maxnum)
 		{maxnum=num[i].num;
 			sign=i;
		 }
	 }
	 leftmax=num[sign].l;
 	printf("%d %d %d",maxnum+1,seg[leftmax].x1,seg[leftmax].y1);
	 }

