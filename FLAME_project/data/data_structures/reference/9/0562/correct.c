#include <stdio.h>
#include <stdlib.h>
struct node {
	int x1;
	int y1;
	int x2;
	int y2;
	int len;
} num[1000];
int cmp1(const void*a,const void*b) {
	struct node* aa=(struct node*)a;
	struct node* bb=(struct node*)b;
	return bb->x1-aa->x1;
}
int cmp2(const void*a,const void*b) {
	struct node* aa=(struct node*)a;
	struct node* bb=(struct node*)b;
	return aa->len-bb->len;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d%d%d%d",&num[i].x1,&num[i].y1,&num[i].x2,&num[i].y2);
		num[i].len=1;
	}
	qsort(num,n,sizeof(num[0]),cmp1);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(num[i].x2==num[j].x1&&num[i].y2==num[j].y1) {
				num[i].x2=num[j].x2;
				num[i].y2=num[j].y2;
				num[i].len+=num[j].len;
				num[j].x1=0;
				num[j].x2=0;
				num[j].y1=0;
				num[j].y2=0;
			}
		}
	}
	qsort(num,n,sizeof(num[0]),cmp2);
	printf("%d %d %d",num[n-1].len,num[n-1].x1,num[n-1].y1);
	return 0;
}

