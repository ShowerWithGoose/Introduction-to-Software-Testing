#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

struct line{
	int x1;
	int y1;
	int x2;
	int y2;
};
typedef struct line Line;
Line lines[105], l[105][105];

int main() {
	int n, i, j, k, s, p;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &lines[i].x1, &lines[i].y1, &lines[i].x2, &lines[i].y2);
	}
	int max = 0, flag;
	for (i = 0; i < n; i++) {
		flag = 1;
		k = 0;
		l[i][k] = lines[i];
		while (flag) {
			flag = 0;
			for (s = 0; s < n; s++) {
				if (lines[s].x1 == l[i][k].x2 && lines[s].y1 == l[i][k].y2) {
					l[i][++k] = lines[s];
					flag = 1;
					break;
				}
			}
		}
		if (k + 1 > max) {
			max = k + 1;
			p = i;
		}
	}

	printf("%d %d %d", max, l[p][0].x1, l[p][0].y1);

	return 0;
}

