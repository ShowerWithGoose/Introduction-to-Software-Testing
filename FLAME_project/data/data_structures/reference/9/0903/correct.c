#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct Line {
	int x1,y1,x2,y2;
};
	struct Line coordinate[150];
int main()
{
	int i,j,n,countmax=1,x1m = 0,y1m = 0;
	scanf("%d",&n);
	while(i<n){
		scanf("%d %d %d %d", &coordinate[i].x1, &coordinate[i].y1, &coordinate[i].x2, &coordinate[i].y2);
		i++;
	}
	struct Line tmp;
	for(i=0; i<n; i++){
		for(j=i; j<n; j++){
			if(coordinate[i].x1 > coordinate[j].x1){
				tmp = coordinate[i];
				coordinate[i] = coordinate[j];
				coordinate[j] = tmp;
	   		}
		}
	}
	i=0;
	while(i<n)
	{
		int x2,y2,count=1;
		x2=coordinate[i].x2;
		y2=coordinate[i].y2;
		for(j=i+1;j<n;j++)
		{
			if(x2==coordinate[j].x1 && y2==coordinate[j].y1 )
			{
				x2=coordinate[j].x2;
				y2=coordinate[j].y2;
				count++;
			}
		}
		if(count>countmax)
		{
			countmax=count;
			x1m=coordinate[i].x1;
			y1m=coordinate[i].y1;
		}
		i++;
	}
	printf("%d %d %d\n", countmax, x1m,y1m);
	return 0;
}


