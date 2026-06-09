#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define Arraynum(x) (sizeof(x)/sizeof(x[0]))
struct line {
	int x1,y1,x2,y2;
}l[101];
int cmp(const void *x,const void *y){
	struct line *c=(struct line*)x;
	struct line *d=(struct line*)y;
	return c->x1 - d->x1;
}
int find (int m,int t,int n){
	int i=m+1;
	int j=m;
	while(i<n){
		if(l[i].x1==l[j].x2&&l[i].y1==l[j].y2){
			j=i;
			t++;
		}
		i++;
	}
	return t;
}
int main(){
	int i,j,k,flag=0,min=99999999,max=-99999999;
	int n,m,len,sum,num,x,y,t;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	qsort(l,n,sizeof(l[0]),cmp);
	for(i=0;i<n;i++){
		t=find(i,1,n);
		if(t>max) {
			max=t;
			x=l[i].x1;
			y=l[i].y1;
		}
	}
	printf("%d %d %d",max,x,y);
	getchar();getchar();
    return 0;
}


