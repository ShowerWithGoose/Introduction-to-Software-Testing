#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
struct point {
	int x;
	int y;
};
typedef struct {
	struct point p1;
	struct point p2;
	int num;
} line;
line a[110];
int n,max=0,sig=0;
int main () {
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d%d%d%d",&a[i].p1.x,&a[i].p1.y,&a[i].p2.x,&a[i].p2.y);
	}
	for(int i=0; i<n; i++) {
		a[i].num=1;
	}
	for(int i=0; i<n&&a[i].num!=-1; i++) {
		for(int j=i+1; j<n&&a[j].num!=-1; j++) {
			if(a[i].p2.x==a[j].p1.x&&a[i].p2.y==a[j].p1.y) {
				a[i].num++;
				a[i].p2.x=a[j].p2.x;
				a[i].p2.y=a[j].p2.y;
				a[j].num=-1;
			}
		}
	}

	for(int i=n-1; i>=0; i--) {
		if(a[i].num==-1) continue;
		for(int j=i-1; j>=0; j--) {
			if(a[j].num==-1||a[i].num==-1) continue;
			if(a[j].p1.x==a[i].p2.x&&a[j].p1.y==a[i].p2.y) {
				a[i].p2.x=a[j].p2.x;
				a[i].p2.y=a[j].p2.y;
				a[i].num+=a[j].num;
				a[j].num=-1;
			}
			if(a[j].p2.x==a[i].p1.x&&a[j].p2.y==a[i].p1.y) {
				a[j].p2.x=a[i].p2.x;
				a[j].p2.y=a[i].p2.y;
				a[j].num+=a[i].num;
				a[i].num=-1;
			}
		}
	}
	for(int i=0; i<n; i++) {
		if(a[i].num>max) {
			max=a[i].num;
			sig=i;
		}
	}
	printf("%d %d %d",max,a[sig].p1.x,a[sig].p1.y);

	return 0;
}















