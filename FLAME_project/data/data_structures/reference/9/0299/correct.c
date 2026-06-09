#include<stdio.h>
#include<string.h>
struct POINT
{
	int x;
	int y;
};
struct LINE
{
	struct POINT point1;
	struct POINT point2;	
	int xianduanshu;
	int flag;
};
typedef struct LINE line;

int main()
{
	int n;
	scanf("%d",&n);
	line xian[105];
	int i,j;
	for(i=0;i<n;i++)
	{
		xian[i].flag =1;
		xian[i].xianduanshu =1;
		scanf("%d%d%d%d",&xian[i].point1.x ,&xian[i].point1.y ,&xian[i].point2.x ,&xian[i].point2.y );
	}
	

	for(i=0;i<n;i++)
	{
		if(xian[i].flag !=0)
		for(j=0;j<n;j++)
		{
			if(i!=j&&xian[j].flag !=0)
			{
			if(xian[i].point1.x  ==xian[j].point1.x&&xian[i].point1.y  ==xian[j].point1.y)
			{	
			xian[i].point1 =xian[i].point2 ;
			xian[i].point2 =xian[j].point2 ;
			xian[i].xianduanshu=xian[i].xianduanshu +xian[j].xianduanshu ;
			xian[j].flag =0;
			}
			else if(xian[i].point1.x  ==xian[j].point2.x &&xian[i].point1.y  ==xian[j].point2.y)
			{
			xian[i].point1 =xian[i].point2 ;
			xian[i].point2 =xian[j].point1 ;
			xian[i].xianduanshu=xian[i].xianduanshu +xian[j].xianduanshu ;
			xian[j].flag =0;	
			}
			else if(xian[i].point2.x  ==xian[j].point1.x &&xian[i].point2.y  ==xian[j].point1.y)
			{
		//	xian[i].point1 =xian[i].point1 ;
			xian[i].point2 =xian[j].point2 ;
			xian[i].xianduanshu=xian[i].xianduanshu +xian[j].xianduanshu ;
			xian[j].flag =0;	
			}
			else if(xian[i].point2.x  ==xian[j].point2.x &&xian[i].point2.y  ==xian[j].point2.y)
			{
		//	xian[i].point1 =xian[i].point1 ;
			xian[i].point2 =xian[j].point1 ;
			xian[i].xianduanshu=xian[i].xianduanshu +xian[j].xianduanshu ;
			xian[j].flag =0;	
			}				
			}

			
		}

	}
	//bijiaoshuchu
	int max=xian[0].xianduanshu,k;
	for(i=0;i<n;i++)
	{
		if(xian[i].flag !=0)
		{
		if(xian[i].xianduanshu >max)
		{
			max=xian[i].xianduanshu ;
			k=i;
		}			
		}

	}
	printf("%d %d %d",max,(xian[k].point1.x >xian[k].point2.x )?xian[k].point2.x : xian[k].point1.x,(xian[k].point1.x >xian[k].point2.x)? xian[k].point2.y  :  xian[k].point1.y );
	return 0;
}



