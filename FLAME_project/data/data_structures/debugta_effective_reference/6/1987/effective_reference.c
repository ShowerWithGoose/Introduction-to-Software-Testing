#include<stdio.h>
int zhan[1000];
int main()
{
	int content=0,cz,ys,i;
	while(scanf("%d",&cz)!=EOF)
	{
		if(cz==-1)
		break;
		if(cz==1)
		{
			scanf("%d",&ys);
			if(content==100)
			printf("error ");
			else
			{
			for(i=content;i>0;i--)
			zhan[i]=zhan[i-1];
			content++;
			zhan[0]=ys;
			}
		}
		else
		{
			if(content==0)
			printf("error ");
            else
            {
            	printf("%d ",zhan[0]);
            	for(i=0;i<content;i++)
            	zhan[i]=zhan[i+1];
            	content--;
			}
		}
	}
	return 0;
 } 



