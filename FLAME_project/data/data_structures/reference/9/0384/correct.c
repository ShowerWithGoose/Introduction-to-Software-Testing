#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct line {
	int x1;
	int x2;
	int y1;
	int y2;
	int number;
};
int cmp(const void*a,const void*b) {
	struct line*c=(struct line*)a;
	struct line*d=(struct line*)b;
	if(c->x1>d->x1) return -1;
	else if (c->x1<d->x2) return 1;
	else return d->y1 - c->y1;
}
int main() {
	struct line l[666];

	int n,i,j;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
		l[i].number=1;
	}
	qsort(l,n,sizeof(l[0]),cmp);
	for(i=0; i<n-1;i++)
		for(j=i+1; j<n; j++) {
			if(l[i].x1==l[j].x2&&l[i].y1==l[j].y2)
				l[j].number=l[i].number+1;
		}
	int max=1,flag=0;
	for(i=0; i<n; i++)
		if(l[i].number>max) {
			max=l[i].number;
			flag=i;
		}
	printf("%d %d %d",max,l[flag].x1,l[flag].y1);
	return 0;
}


