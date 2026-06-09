#include <stdio.h>
#include <stdlib.h>
typedef struct line{
	int xs, xe, ys, ye;
}li;
li a[999];
int cmp(li*, li*);
int check(li[], int);
int n;
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d%d%d%d", &a[i].xs,&a[i].ys, &a[i].xe, &a[i].ye);
	qsort(a, n, sizeof(li), cmp);
	int t=1, st;
	for(int i=0; i<n; i++){
		int tmp=check(a,i);
		if(tmp>t){
			t=tmp;
			st=i;
		}
	}
	printf("%d %d %d", t, a[st].xs, a[st].ys);
	return 0;
}
int cmp(li *a, li *b){
	return a->xs-b->xs;
}
int check(li a[],int x){
	int t=1;
	li s=*(a+x);
	for(int i=0; i<n; i++){
		if(s.xe==a[i].xs && s.ye==a[i].ys){
			s=a[i];
			t++;
		}
	}
	return t;
}


