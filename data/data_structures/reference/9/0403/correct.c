#include<stdio.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
};

int main()
{
	struct line s1[105],s2[105];
	int n,i,j,k=0,flag,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&s1[i].x1,&s1[i].y1,&s1[i].x2,&s1[i].y2);
	}
	for(i=0;i<n;i++)
	{
		flag=0;
	   for(j=0;j<n;j++)
	   {
	   	    if(s1[i].x2==s1[j].x1&&s1[i].y2==s1[j].y1&&i!=j)//å°¾=å¤´ 
	   	    {
			  	flag=1;
			  	break;
			}
	   }
	   if(flag==1)
	   {
	   	 s2[k].x1=s1[i].x1;
	   	 s2[k].x2=s1[i].x2;
	   	 s2[k].y1=s1[i].y1;
	   	 s2[k].y2=s1[i].y2;
		 k++;	
	   }
	   
	}

	for(i=0;i<k;i++)
	{
		s2[i].num=1;
		for(j=0;j<n;j++)
		{
			if(s2[i].x2==s1[j].x1&&s2[i].y2==s1[j].y1)
			{
				s2[i].x2=s1[j].x2;
				s2[i].y2=s1[j].y2;
				s2[i].num++;
				j=-1;
			}
		}
	}
	int x,y;
	for(i=0;i<k;i++)
	{
		if(max<s2[i].num)
		{
		  max=s2[i].num;
		  x=s2[i].x1;y=s2[i].y1;	
		}
		
	}
	printf("%d %d %d",max,x,y);
	return 0;
}



