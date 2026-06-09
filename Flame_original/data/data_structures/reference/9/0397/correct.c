#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _line {
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
} Line;
int cmp0(const void* p1, const void* p2);
int cmp1(const void* p1, const void* p2);

int main() {
	//freopen("3.1INPUT.txt", "r", stdin);
	Line lines[105] = {};
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &lines[i].x1, &lines[i].y1, &lines[i].x2, &lines[i].y2);
		lines[i].num = 1;
	}
	
	qsort(lines, n, sizeof(Line), cmp0);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			/* i½Ój */
			if (lines[i].x1 == lines[j].x2 && lines[i].y1 == lines[j].y2) {
				lines[j].y2 = lines[i].y2;
				lines[j].x2 = lines[i].x2;
				lines[j].num += lines[i].num;
				memset(&lines[i], 0, sizeof(Line));
			}
		}
	}
	qsort(lines, n, sizeof(Line), cmp1);
	printf("%d %d %d\n",lines[n-1].num, lines[n-1].x1, lines[n-1].y1);
	return 0;
}

int cmp0(const void* p1, const void* p2) {
	Line* a = (Line*) p1;
	Line* b = (Line*) p2;
	if (a->x1 != b->x1) return a->x1 - b->x1;
	else return a->y1 - b->y2;
}


int cmp1(const void* p1, const void* p2) {
	Line* a = (Line*) p1;
	Line* b = (Line*) p2;
	return a->num - b->num;
}

