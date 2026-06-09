#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int count;
}a[100];
int main(){
	int n,i,j,max=0;
	struct line *start=NULL,*p;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	for(i=0;i<n;i++){
		a[i].count=1;
	}
	for(i=0;i<n;i++){
		p=&a[i];
		for(j=0;j<n;j++){
			if(a[j].x1==p->x2&&a[j].y1==p->y2){
				a[i].count++;
				p=&a[j];
				j=-1;
			}
		}
	}
	for(i=0;i<n;i++){
		if(a[i].count>max){
			max=a[i].count;
			start=&a[i];
		}
	}
	printf("%d %d %d",max,start->x1,start->y1);
	return 0;
}


