#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	
	
};

int cmp(const void *x,const void *y){
	struct line *p=x;
	struct line *q=y;
	return (p->x1)-(q->x1);
}

int main(){
	int n;
	int lx,ly,max=0,num;
	scanf("%d",&n);
	struct line lines[n];
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
	}
	qsort(lines,n,sizeof(lines[0]),cmp);
//	for(i=0;i<n;i++){
//		printf("%d %d %d %d\n",lines[i].x1,lines[i].y1,lines[i].x2,lines[i].y2);
//	}
	for(i=0;i<n;i++){
		num=0;
		int a=lines[i].x2;
		int b=lines[i].y2;
		for(j=i+1;j<n;j++){
			if(lines[j].x1==a&&lines[j].y1==b){
//				printf("%d %d\n",lines[j].x1,lines[j].y1);
				num++;
				a=lines[j].x2;
				b=lines[j].y2;
				
			}
		}
//		printf("%d\n",num);
		if(num>max){
			lx=lines[i].x1;
			ly=lines[i].y1;
			max=num;
//			printf("%d %d %d\n",max,lx,ly);
		}
		
	}
	printf("%d %d %d",max+1,lx,ly);
	
}

