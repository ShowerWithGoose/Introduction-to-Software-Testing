#include <stdio.h>
int main()
{
	struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
	int fin;
	}dot[105];
	int n,i=1,j,k,ansdot,anslen;
	scanf("%d",&n);
	while(i<=n)
	{
		dot[i].num=1;
		scanf("%d %d %d %d",&dot[i].x1,&dot[i].y1,&dot[i].x2,&dot[i].y2); 
		i++;
	}
	for(i=1;i<=n;i++)
	{
		k=i;
		dot[i].fin=i;
		//ÓÒ²à
		for(j=1;j<=n;j++)
		{
			if(dot[k].x2==dot[j].x1&&dot[k].y2==dot[j].y1)
			{
				dot[i].num++;
				k=j;
				j=0;
			} 
		} 
		//×ó²à
		k=i;
		 for(j=1;j<=n;j++)
		{
			if(dot[k].x1==dot[j].x2&&dot[k].y1==dot[j].y2)
			{
				dot[i].fin=j;
				dot[i].num++;
				k=j;
				j=0;
			} 
		} 
	}
	anslen=dot[1].num;
	ansdot=dot[1].fin;
	for(i=2;i<=n;i++)
	{
		if(dot[i].num>anslen)
		{
			ansdot=dot[i].fin;
			anslen=dot[i].num;
		}
	 } 
	 printf("%d %d %d",anslen,dot[ansdot].x1,dot[ansdot].y1);
	return 0;
}

