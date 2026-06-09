#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct line {
	int x1;
	int y1;
	int x2;
	int y2;
} l[100];
int cmp(const void*a,const void *b) {
	return (*(struct line*)a).x1>(*(struct line *)b).x1?1:-1;
}
int main() {
	int n,i=0,j=0,k=0,max=1,count=1,holdx,holdy;
	scanf("%d",&n);
	for(i=0; i<n; i++)
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	qsort(l,n,sizeof(struct line),cmp);
	for(i=0; i<n; i++) {
		k=i;
		for(j=k+1; j<n ; j++) {
			if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1) {
				count++;
				i=j;
			}
		}
		i=k;
		if(count>max) {
			max=count;
			holdx=l[i].x1;
			holdy=l[i].y1;
		}
		count=1;
	}
	printf("%d %d %d",max,holdx,holdy);
	return 0;
}

