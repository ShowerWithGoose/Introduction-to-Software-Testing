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
struct line gather[100];
int cmp(const void *e1,const void *e2);


int main() {
	int n;

	scanf("%d", &n);

	int i,j;
	int temp;

	int x0=0;
	int y0=0;


	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d", &gather[i].x1, &gather[i].y1, &gather[i].x2, &gather[i].y2);
	}
	
	qsort(gather,n,sizeof(gather[0]),cmp);
	
	int max=1,x1_max=0,y1_max=0;
	for(i=0;i<n;i++){
		int x2,y2;
		int count=1;
		x2=gather[i].x2 ;
		y2=gather[i].y2 ;
		for(j=i+1;j<n;j++){
			if(x2==gather[j].x1 &&y2==gather[j].y1 ){
				count++;
				x2=gather[j].x2 ;
				y2=gather[j].y2;
			}
		}
		if(count>max){
			max=count;
			x1_max=gather[i].x1;
			y1_max=gather[i].y1;
		}
	}

    printf("%d %d %d\n",max,x1_max,y1_max);

	return 0;
}
int cmp(const void *e1,const void *e2){
	return ((struct line*)e1)->x1-((struct line*)e2)->x1;
}



