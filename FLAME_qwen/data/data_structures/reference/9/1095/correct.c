#include <stdio.h>
#include <stdlib.h>
int cmp1(const void *e1,const void *e2); 
int cmp2(const void *e1,const void *e2);
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int x[200];
	int y[200];
	int number;
};
int main(){
	int n;
	scanf("%d",&n);
	int i=0,j=0,k=0;
	struct line a[200];
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].x[1]=a[i].x1;
		a[i].x[2]=a[i].x2;
		a[i].y[1]=a[i].y1;
		a[i].y[2]=a[i].y2;
		a[i].number++;
	}
	qsort(a,n,sizeof(a[0]),cmp1);
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(a[i].x1==a[j].x2){
				if(a[i].y1==a[j].y2){
					a[j].number+=a[i].number;
				}
			}
		}
	}
	qsort(a,n,sizeof(a[0]),cmp2);
	printf("%d %d %d",a[0].number,a[0].x1,a[0].y1);
}
int cmp1(const void *e1,const void *e2){
	return ((struct line*)e2)->x1-((struct line*)e1)->x1;
}
int cmp2(const void *e1,const void *e2){
	return ((struct line*)e2)->number-((struct line*)e1)->number;
}

