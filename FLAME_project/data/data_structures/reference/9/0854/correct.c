#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define eps 1e-10
#define MAX(a,b) ((a)>(b)?(a) : (b))
#define MIN(a,b) ((a)>(b)?(a) : (b))
struct line {
	int x1;
	int x2;
	int y1;
	int y2;
	int flag;
};
int main() {
	int n;
	scanf("%d", &n);
	int i, j, k;
	struct line l[105];
	struct line *left[105], *right[105];
	for (i = 0; i < n; i++) {
		sf("%d%d%d%d", &l[i].x1, &l[i].y1, &l[i].x2, &l[i].y2);
		l[i].flag = 1;
	}
	for (i = 0; i < n; i++) {
		left[i] = &l[i];
		right[i] = &l[i];
		for (int t = 0; t < n; t++) {
			for (j = i + 1; j < n; j++) {
				if (left[i]->x1 == l[j].x2 && left[i]->y1 == l[j].y2) {
					left[i] = &l[j];
					l[i].flag++;
				} else if (right[i]->x2 == l[j].x1 && right[i]->y2 == l[j].y1) {
					right[i] = &l[j];
					l[i].flag++;
				}
			}
		}
	}
	k = l[0].flag;
	int x=0;
	for (i = 1; i < n; i++) {
		if (l[i].flag > k) {
			x = i;
			k = l[i].flag;
		}
	}
	pf("%d %d %d", l[x].flag, left[x]->x1, left[x]->y1);


}

