#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define Arraynum(x1) (sizeof(x1)/sizeof(x1[0]))
struct line {
	int x1,y1,x2,y2;
}n[101];
int cmp(const void *x1,const void *y1){
	struct line *c=(struct line*)x1;
	struct line *d=(struct line*)y1;
	return c->x1 - d->x1;
}
int find (int m,int l,int t){
	int i=m+1;
	int j=m;
	while(i<t){
		if(n[i].x1==n[j].x2&&n[i].y1==n[j].y2){
			j=i;
			l++;
		}
		i++;
	}
	return l;
}
int main(){
	int i,j,k,flag=0,min=99999999,max=-99999999;
	int t,m,len,sum,num,x1,y1,l;
	scanf("%d",&t);
	for(i=0;i<t;i++) scanf("%d%d%d%d",&n[i].x1,&n[i].y1,&n[i].x2,&n[i].y2);
	qsort(n,t,sizeof(n[0]),cmp);
	for(i=0;i<t;i++){
		l=find(i,1,t);
		if(l>max) {
			max=l;
			x1=n[i].x1;
			y1=n[i].y1;
		}
	}
	printf("%d %d %d",max,x1,y1);
	getchar();getchar();
    return 0;
}


