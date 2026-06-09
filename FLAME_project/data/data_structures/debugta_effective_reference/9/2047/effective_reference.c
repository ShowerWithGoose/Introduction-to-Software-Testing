#include<stdio.h>
struct point{
	int x1;
	int y1;
	int x2;
	int y2;
};
	struct point infor[105],temp;
	int i,j,k,n;
	int X[105],Y[105],count[105];
	int max,start_x,start_y;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&infor[i].x1,&infor[i].y1,&infor[i].x2,&infor[i].y2);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(infor[i].x1>=infor[j].x1 )
			{
				temp = infor[i];
				infor[i] = infor[j];
				infor[j] = temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(k=i,j=0;j<n;j++)
		{
			if(infor[k].x2 == infor[j].x1 &&infor[k].y2 == infor[j].y1)
			{
				count[i]++;
				X[i]=infor[i].x1 ;
				Y[i]=infor[i].y1 ;
				k=j;
			}
		}
	}
	max=count[0];
	start_x=X[0];
	start_y=Y[0];
	for(i=0;i<n;i++)
	{
		if(count[i]>max)
		{
			max=count[i];
			start_x=X[i];
			start_y=Y[i];
		}
	}
	printf("%d %d %d",max+1,start_x,start_y);
	return 0;
}

