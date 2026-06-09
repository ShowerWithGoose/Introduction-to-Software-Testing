#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct xian {
	int x1;
	int y1;
	int x2;
	int y2;
} stu;
stu line[101];

int cmp(const void* a,const void* b) {
	stu *c=(stu*)a,*d=(stu*)b;
	return c->x1 - d->x1;
};

int x0,y0,max=1,num=1,x3,y3;
int main() {
	int n,i,j;
	scanf("%d",&n);
	for(i=0; i<n; i++) scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	qsort(line,n,sizeof(stu),cmp);
	for(i=0; i<n; i++) {
		x3=line[i].x2;
		y3=line[i].y2;
		num=1;
		for(j=i+1; j<n; j++) {
			if(x3==line[j].x1&&y3==line[j].y1) {
				num++;
				x3=line[j].x2;
				y3=line[j].y2;
			}
		}
		if(max<num) {
			max=num;
			x0=line[i].x1;
			y0=line[i].y1;
		}
	}
	printf("%d %d %d",max,x0,y0);
	return 0;
}

