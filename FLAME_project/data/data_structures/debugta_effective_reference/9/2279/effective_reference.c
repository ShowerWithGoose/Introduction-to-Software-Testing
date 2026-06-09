#include <stdio.h>
#include <stdlib.h>
typedef struct line{
	int xs, xe, ys, ye;
}li;
li xs[999];
int cmp(li*, li*);
int check(li[], int);
int n;
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d%d%d%d", &xs[i].xs,&xs[i].ys, &xs[i].xe, &xs[i].ye);
	qsort(xs, n, sizeof(li), cmp);
	int t=1, imax;
	for(int i=0; i<n; i++){
		int tmp=check(xs,i);
		if(tmp>t){
			t=tmp;
			imax=i;
		}
	}
	printf("%d %d %d", t, xs[imax].xs, xs[imax].ys);
	return 0;
}
int cmp(li *xs, li *b){
	return xs->xs-b->xs;
}
int check(li xs[],int x){
	int t=1;
	li xm=*(xs+x);
	for(int i=0; i<n; i++){
		if(xm.xe==xs[i].xs && xm.ye==xs[i].ys){
			xm=xs[i];
			t++;
		}
	}
	return t;
}


