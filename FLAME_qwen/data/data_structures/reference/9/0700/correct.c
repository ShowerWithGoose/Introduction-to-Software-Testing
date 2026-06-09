#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct line {
	int x1;
	int x2;
	int y1;
	int y2;

};
struct line info[100];
int cmp(const void *e1,const void *e2);


int main() {
	int n;

	scanf("%d", &n);

	int i,j;
	int temp;

	int x0=0;
	int y0=0;


	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d", &info[i].x1, &info[i].y1, &info[i].x2, &info[i].y2);
	}
	
	qsort(info,n,sizeof(info[0]),cmp);
	
	int max=1,x1_max=0,y1_max=0;
	for(i=0;i<n;i++){
		int x2,y2;
		int count=1;
		x2=info[i].x2 ;
		y2=info[i].y2 ;
		for(j=i+1;j<n;j++){
			if(x2==info[j].x1 &&y2==info[j].y1 ){
				count++;
				x2=info[j].x2 ;
				y2=info[j].y2;
			}
		}
		if(count>max){
			max=count;
			x1_max=info[i].x1;
			y1_max=info[i].y1;
		}
	}

    printf("%d %d %d\n",max,x1_max,y1_max);

	return 0;
}
int cmp(const void *e1,const void *e2){
	return ((struct line*)e1)->x1-((struct line*)e2)->x1;
}



