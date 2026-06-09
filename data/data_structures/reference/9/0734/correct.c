#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

struct Line{
	int x1;
	int y1;
	int x2;
	int y2;
	int original;
}line[105];

int compare(const void *p1,const void *p2)
{	struct Line *a=(struct Line *)p1;
	struct Line *b=(struct Line *)p2;
	return (a->x1==b->x1)?(a->y1)-(b->y1):(a->x1)-(b->x1);
	
}

int main()
{	int i,j,k;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	for(i=0;i<n;i++)
		line[i].original=i;
	qsort(line,n,sizeof(struct Line),compare);
	
	int count[105]={0};
	int X,Y=0;
	for(i=0;i<n;i++){
		X=line[i].x2;
		Y=line[i].y2;
		for(j=i+1;j<n;j++){
			if(line[j].x1==X&&line[j].y1==Y)
				{
				count[i]++;
				X=line[j].x2;
				Y=line[j].y2;}
		}
    }
    int max_count=0,max_name;
    for(i=0;i<n;i++){
    	if(count[i]>=max_count){
    		max_count=count[i];
    		max_name=i;
		}
	}
	printf("%d %d %d",max_count+1,line[max_name].x1,line[max_name].y1);
	return 0;}



	
	

