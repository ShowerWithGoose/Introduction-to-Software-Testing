#include<stdio.h>
#include<stdlib.h>
struct str{
	int num,x1,x2,y1,y2;
};
int cmp(const void*a,const void*b){
	struct str *c=(struct str*)a;
	struct str *d=(struct str*)b;
	if(c->x1!=d->x1)
		return (d->x1-c->x1);
	else
		return (d->y1-c->y1);
}

int main(){
	struct str point[105];
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&point[i].x1,&point[i].y1,&point[i].x2,&point[i].y2);
		point[i].num=1;
	}
	qsort(point,n,sizeof(point[0]),cmp);
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(point[j].x2==point[i].x1&&point[j].y2==point[i].y1)
			{
				point[j].num+=point[i].num;
			}
		}
	}
	int max=1,begin;
	for(int k=0;k<n;k++){
		if(point[k].num>max){
			max=point[k].num;
			begin=k;
		}
	}
	printf("%d %d %d",max,point[begin].x1,point[begin].y1);
	return 0;
}

