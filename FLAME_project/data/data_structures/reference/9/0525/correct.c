#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int mark[1000];
typedef struct line {
	int x1,y1,x2,y2;
	int num;
} Line;
Line ll[100];
int cmp(const void *a, const void *b){
	Line *aa=(Line*)a,*bb=(Line*)b;
	if(aa->x1!=bb->x1) return ((aa->x1>bb->x1)?-1:1);
	else return ((aa->y1>bb->y1)?-1:1);
}
int main() {
	int N;
	int i=0,j=0;
	scanf("%d",&N);
	for(i=0; i<N; i++) {
		scanf("%d %d %d %d",&ll[i].x1,&ll[i].y1,&ll[i].x2,&ll[i].y2);
	}
	qsort(ll,N,sizeof(ll[0]),cmp);
	/*for(i=0; i<N; i++) {
		printf("%d %d %d %d\n",ll[i].x1,ll[i].y1,ll[i].x2,ll[i].y2);
	}*/
	int max=-1,maxx,maxy;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++ ){
			if(ll[i].x1==ll[j].x2&&ll[i].y1==ll[j].y2){
				ll[j].num=ll[i].num+1;
				if(ll[j].num>max){
					max=ll[j].num;
					maxx=ll[j].x1;
					maxy=ll[j].y1;
				}
			}
		}
	}
	printf("%d %d %d",max+1,maxx,maxy);
		return 0;
}
