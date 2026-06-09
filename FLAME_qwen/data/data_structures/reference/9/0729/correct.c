#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ll long long
struct line {
	int x1;
	int y1;
	int x2;
	int y2;
	int weight;
	int tru;
};
int cmp(const void *a, const void *b) {
	struct line *p = (struct line *)a, *q = (struct line *)b;
	if(p->x1 >q->x1) {
		return 1;
	} else
		return -1;
}
struct line l[50000];
struct line ans;
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
		l[i].tru=1;
		l[i].weight=1;
	}
	qsort(l,n,sizeof(struct line),cmp);
	ans.weight=0;
	for(int i=0; i<n; i++) {
		if(l[i].tru>0) {
			for(int t=0; t<n; t++) {
				for(int j=i+1; j<n; j++) {
					if(l[j].tru>0&&l[i].x2==l[j].x1&&l[i].y2==l[j].y1) {
						l[i].x2=l[j].x2;
						l[i].y2=l[j].y2;
						l[i].weight++;
						l[j].tru=0;
						break;
					}
				}
			}
			if(l[i].weight>ans.weight) {
				ans.weight=l[i].weight;
				ans.x1=l[i].x1;
				ans.y1=l[i].y1;
			}
		}
	}
	printf("%d %d %d",ans.weight,ans.x1,ans.y1);
	return 0;
}


