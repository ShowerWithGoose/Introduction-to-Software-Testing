#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
struct line {
	int x1;
	int y1;
	int x2;
	int y2;
	int cnt;
} l[105];
int cmpzb(const void* p1, const void* p2) {
	struct line *c = (struct line*)p1;
	struct line *d = (struct line*)p2;
	if (c->x1 != d->x1)
		return c->x1 - d->x1;
	else
		return c->y1 - d->y1;
}
int cmpcnt(const void* q1, const void* q2) {
	return(*(struct line*)q1).cnt>(*(struct line*)q2).cnt?1:-1;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d",&l[i].x1, &l[i].y1, &l[i].x2, & l[i].y2);
		l[i].cnt = 1;
	}
	qsort(l, n, sizeof(l[0]), cmpzb);
	//for(int i=0;i<n;i++){
	//	printf("%d %d %d %d\n",l[i].x1, l[i].y1, l[i].x2, l[i].y2);
	//}
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) 
		{
			if (l[j].x1 == l[i].x2 && l[j].y1 == l[i].y2) 
			{
				l[i].cnt+=l[j].cnt;
				l[i].x2 = l[j].x2;
				l[i].y2 = l[j].y2;
				//l[j].x1=0;
				//l[j].x2=0;
				//l[j].y1=0;
				//l[j].y2=0;
				//l[j].cnt=0;
			}
			
		}
	}
	qsort(l, n, sizeof(l[0]), cmpcnt);
	//for(int i=0;i<n;i++){
		
	//}
	printf("%d %d %d\n", l[n-1].cnt, l[n-1].x1, l[n-1].y1);
	return 0;
}

