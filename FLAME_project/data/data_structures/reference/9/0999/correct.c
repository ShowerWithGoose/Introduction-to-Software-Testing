#include<stdio.h>
#include<stdlib.h>
typedef struct Line {
	int x1;
	int y1;
	int x2;
	int y2;
} l;
l Line[100];
typedef struct zone {
	int x1;
	int num;
	int y1;
} Z;
Z arry[100];
Z max;
int main() {
	int n;
	int i,j,k,z,k0=0;
	int x1,x2,y1,y2;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d%d%d%d",&Line[i].x1,&Line[i].y1,&Line[i].x2,&Line[i].y2);
	}
	for(i=0; i<n; i++) {
		z=1;
		x1=Line[i].x1;
		y1=Line[i].y1;
		x2=Line[i].x2;
		y2=Line[i].y2;
		for(j=0; j<n; j++) {

			if(Line[j].x2==x1&&Line[j].y2==y1) {
				x1=Line[j].x1;
				y1=Line[j].y1;
				z++;
				k0=j;
				j=0;
			}

		}
		for(k=0; k<n; k++) {
			arry[i].x1=Line[k].x1;
			arry[i].y1=Line[k].y1;
			if(Line[k].x1==x2&&Line[k].y1==y2) {
				x2=Line[k].x2;
				y2=Line[k].y2;
				z++;
				k=0;
			}
		}
		arry[i].num=z;
		arry[i].x1=Line[k0].x1;
		arry[i].y1=Line[k0].y1;
	}
	max.num=arry[0].num;
	max.x1=arry[0].x1;
	max.y1=arry[0].y1;
	for(i=0; i<n; i++) {//纯比大小，一点问题没有
		if(arry[i].num>max.num) {
			max.num=arry[i].num;
			max.x1=arry[i].x1;
			max.y1=arry[i].y1;
		}
	}
	printf("%d %d %d",max.num,max.x1,max.y1);
	return 0;
}



