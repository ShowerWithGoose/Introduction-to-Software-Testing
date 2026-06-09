#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct coordinate{
	int x1;
	int y1;
	int x2;
	int y2;
};
int main(){
	int n;
	struct coordinate point[100];
	struct coordinate temp;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&point[i].x1,&point[i].y1,&point[i].x2,&point[i].y2);
	}
	for(i=0;i<n;i++){
		for( j=0;j<n-1-i;j++){
			if(point[j].x1>point[j+1].x1){
				temp=point[j];
				point[j]=point[j+1];
				point[j+1]=temp;
			}
		/*	if(point[j].x1==point[j+1].x1){
				if(point[j].y1>point[j+1].y1){
				point[j]=temp;
				point[j]=point[j+1];
				point[j+1]=temp;
				}
			}*/
		}
	}
	int max=1,x,y;
	int count[100];
	memset(count,0,sizeof(count));
	for(i=0;i<n;i++){
		count[i]=1;
		x=point[i].x2;
		y=point[i].y2;
		for(j=i+1;j<n;j++){
			if(point[j].x1==x&&point[j].y1==y){
				count[i]++;
				x=point[j].x2;
				y=point[j].y2;
			}
		}
		if(count[i]>max){
			max=count[i];
			k=i;
		}
	}
//	printf("%d\n",count[1]);
	printf("%d %d %d",max,point[k].x1,point[k].y1);
	return 0;
} 






















