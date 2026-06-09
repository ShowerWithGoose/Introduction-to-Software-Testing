#include<stdio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
struct line {
	int x1,y1,x2,y2;
} lines[105];
int com(const void *a,const void *b) {
	struct line *p=a;
	struct line *q=b;
	return (p->x1)-(q->x1);
}
int main() {
	int n,i,j,x,y,num,max=0;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
	}
	qsort(lines,n,sizeof(lines[0]),com);
	for(i=0; i<n; i++) {
		num=0;
		int a=lines[i].x2;
		int b=lines[i].y2;
		for(j=i+1; j<n; j++) {
			if(lines[j].x1==a&&lines[j].y1==b) {
				num++;
				a=lines[j].x2;
				b=lines[j].y2;

			}
		}
		if(num>max) {
			x=lines[i].x1;
			y=lines[i].y1;
			max=num;
		}
	}
	printf("%d %d %d",max+1,x,y);
}

