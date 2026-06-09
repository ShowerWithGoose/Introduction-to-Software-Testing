#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Point{
		int x1;
		int y1;
		int x2;
		int y2;
		int count;
	}Point,*pPoint;


int cmp_sss(const void*p1,const void *p2){
	int ans;
	pPoint point1 = (pPoint)p1;
	pPoint point2 = (pPoint)p2;
	ans= -point1->count+point2->count;
	return ans;
}
int main(){
     int n=0;
     Point points[105];
     scanf("%d",&n);
     int i=0;
     while(i<n){
     	scanf("%d %d %d %d",&points[i].x1,&points[i].y1,&points[i].x2,&points[i].y2);
     	i++;
	 }
	 i=0;int j=0;int x,y;
	 while(i<n){
	 	x=points[i].x2,y=points[i].y2;
	 	points[i].count=1;
	 	while(j<n){
	 		if(points[j].x1==x&&points[j].y1==y){
	 			points[i].count++;
	 			x=points[j].x2;
	 			y=points[j].y2;
	 			j=0;
			 }else{
			 	j++;
			 }
		}
		j=0;
		i++;
	 }
	 qsort(points,n,sizeof(Point),cmp_sss);
	 printf("%d %d %d",points[0].count,points[0].x1,points[0].y1);
	 return 0;
	 
}

