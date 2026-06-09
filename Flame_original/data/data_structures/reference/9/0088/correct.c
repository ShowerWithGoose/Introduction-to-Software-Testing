#include<stdio.h>
#include<string.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;//线段条数； 
	
};


int main()
{
	int n,i,j;
	struct line lin[100],temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&lin[i].x1,&lin[i].y1,&lin[i].x2,&lin[i].y2);
		lin[i].num=1;
	
	}//录入所有坐标；
	for(j=0;j<n;j++)
	{
	for(i=0;i<n-1;i++)
	{
		if(lin[i].x1>lin[i+1].x1)
		{
			temp=lin[i];
			lin[i]=lin[i+1];
			lin[i+1]=temp;
		}
		if(lin[i].x1==lin[i+1].x1)
		{
			if(lin[i].y1>lin[i+1].y1)
			{
			 	temp=lin[i];
			    lin[i]=lin[i+1];
		    	lin[i+1]=temp;
				
				
			}
			
		}	
	}
	}//排序；
	
	for(i=0;i<n;i++)
	{
		if(lin[i].num!=0)
		for(j=0;j<n;j++)
		{
			if(j!=i&&lin[i].x2==lin[j].x1&&lin[i].y2==lin[j].y1&&lin[j].num!=0)
		{
			lin[i].x2=lin[j].x2;
			lin[i].y2=lin[j].y2;
			lin[i].num+=lin[j].num;
			lin[j].num=0;
		}
		}
		
	 } //连接线段；
	  for(j=0;j<n;j++)
	  {
	  for(i=0;i<n-1;i++)
	  {
	  	if(lin[i].num<lin[i+1].num)
	  	{
	  		temp=lin[i];
	  		lin[i]=lin[i+1];
	  		lin[i+1]=temp;
	  		
		  }
	  	}
	  	
	  }//num从高到低排序； 
	printf("%d %d %d",lin[0].num,lin[0].x1,lin[0].y1);//输出第一个数； 
	return 0;
	 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
 } 

