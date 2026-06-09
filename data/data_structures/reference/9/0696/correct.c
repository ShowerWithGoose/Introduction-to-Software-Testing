#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct point{
	int x1;
	int x2;
	int y1;
	int y2;
	int lenth;
}POINT,*PPOINT;

int cmp1(const void *a,const void *b){
	PPOINT c = (PPOINT)a;
	PPOINT d = (PPOINT)b;
	if(c->x1!=d->x1){
		return (c->x1-d->x1);
	}
	else{
		return (c->y1-d->y1);
	}
}

int cmp2(const void *a,const void *b){
	PPOINT c = (PPOINT)a;
	PPOINT d = (PPOINT)b;
	return (d->lenth-c->lenth);
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	POINT Point[n];
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&Point[i].x1,&Point[i].y1,&Point[i].x2,&Point[i].y2);
		Point[i].lenth=1;
//		printf("%d %d %d %d",Point[i].x1,Point[i].y1,Point[i].x2,Point[i].y2);
	}
	qsort(Point,n,sizeof(POINT),cmp1);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(Point[i].x1==-1)continue;
			if(i==j||Point[j].x1==-1)continue;
			else{
				if(Point[i].x2==Point[j].x1&&Point[i].y2==Point[j].y1){
					Point[i].x2=Point[j].x2;
					Point[i].y2=Point[j].y2;
					Point[j].x1=-1;Point[j].x2=-1;Point[j].y1=-1;Point[j].y2=-1;
					Point[i].lenth+=Point[j].lenth;
				}
			}
		}
	}
	qsort(Point,n,sizeof(POINT),cmp2);
	printf("%d %d %d",Point[0].lenth,Point[0].x1,Point[0].y1);
	return 0;
}

