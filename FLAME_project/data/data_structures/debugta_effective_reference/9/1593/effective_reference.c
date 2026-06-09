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
	struct line *startline[105], *lastline[105];
	for (i = 0; i < n; i++) {
		sf("%d%d%d%d", &l[i].x1, &l[i].y1, &l[i].x2, &l[i].y2);
		l[i].flag = 1;
	}
	for (i = 0; i < n; i++) {
		startline[i] = &l[i];
		lastline[i] = &l[i];
		for (int x = 0; x < n; x++) {
			for (j = i + 1; j < n; j++) {
				if (startline[i]->x1 == l[j].x2 && startline[i]->y1 == l[j].y2) {
					startline[i] = &l[j];
					l[i].flag++;
				} else if (lastline[i]->x2 == l[j].x1 && lastline[i]->y2 == l[j].y1) {
					lastline[i] = &l[j];
					l[i].flag++;
				}
			}
		}
	}
	k = l[0].flag;
	int flag=0;
	for (i = 1; i < n; i++) {
		if (l[i].flag > k) {
			flag = i;
			k = l[i].flag;
		}
	}
	pf("%d %d %d", l[flag].flag, startline[flag]->x1, startline[flag]->y1);


}

