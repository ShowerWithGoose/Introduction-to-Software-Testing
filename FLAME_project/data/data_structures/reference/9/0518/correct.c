#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define eps 1e-10
typedef struct location{
	int x1;
	int y1;
	int x2;
	int y2;
	int length;
}loc;
loc l[1005];
int n;
int cmp(const void*a,const void*b){
	loc*p=(loc*)a;
	loc*q=(loc*)b;
	if(p->x1!=q->x1)
	return q->x1-p->x1;
	return q->y1-p->y1;
}
void print(){
	int i,max=0,place=0;
	for(i=0; i<n; i++) {
		if(l[i].length>max) {
			max=l[i].length;
			place=i;
		}
	}
	printf("%d %d %d",max,l[place].x1,l[place].y1);
}
 
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	l[i].length=1;
	for (i=0;i<n;i++){
		scanf("%d %d %d %d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	qsort(l,i,sizeof(loc),cmp);
	int j,k;
	for(j=0; j<n-1; j++) {
		for(k=j+1; k<n; k++) {
			if(l[j].x1==l[k].x2&&l[j].y1==l[k].y2)
				l[k].length+=l[j].length;
		}
	}
	print();
}




