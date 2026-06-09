#include <stdio.h>
#include <stdlib.h>
struct line{
	int x1,y1,x2,y2,flag;
};
struct line a[100];
int cmp(const void *a,const void *b){
	struct line *c=(struct line *)a;
	struct line *d=(struct line *)b;
	if(d->x1-c->x1==0){
		if(c->x2-d->x2>=0)
		    return 1;
	    return -1;
	}
	else{
		if(c->x1-d->x1>=0)
	    return 1;
	return -1;
	}
}
int main(){
	int N,i=0,j=0,k=0,max=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].flag=1;
	}
	qsort(a,N,sizeof(a[0]),cmp);
	for(i=0;i<N-1;i++){
		k=i;
		for(j=i+1;j<N;j++){
			if(a[j].x1==a[k].x2&&a[j].y1==a[k].y2){
				a[i].flag++;k=j;
			}
			else continue;
		}
		if(a[i].flag>max)
		    max=a[i].flag;
	}
	printf("%d ",max);
	for(i=0;i<N;i++){
		if(a[i].flag==max){
		printf("%d %d",a[i].x1,a[i].y1);
		break;
		}
	}
	return 0;
}

