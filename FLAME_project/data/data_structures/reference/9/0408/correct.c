#include <stdio.h>
struct xy {
	int x1;
	int y1;
	int x2;
	int y2;
};
int cnt[105];
int main() 
{
	struct xy point[105];
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1; i<=n; i++) 
	{
		scanf("%d %d %d %d",&point[i].x1,&point[i].y1,&point[i].x2,&point[i].y2);
	}
	for(i=1; i<=n; i++) 
	{
		k=i;
		for(j=1; j<=n; j++) 
		{
			if(point[k].x2==point[j].x1&&point[k].y2==point[j].y1) 
			{
				cnt[i]++;
				k=j;
				j=0;
			}
		}
	}
	int max=cnt[1],px=point[1].x1,py=point[1].y1;
	for(i=1; i<=n; i++) 
	{
		if(cnt[i]>max) 
		{
			max=cnt[i];
			px=point[i].x1,py=point[i].y1;
		}
	}
	printf("%d %d %d",max+1,px,py);

	return 0;
}



