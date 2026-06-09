#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int hashq[150];
int hashz[150];

struct stu {
	int x1;
	int y1;
	int x2;
	int y2;
} qid[150];

int cmp(const struct stu *a, const struct stu *b) {
	return (a->x2 - b->x2);
}

int main() {
	int n;
	scanf("%d", &n);
	int count = 0;
	int flag = 0;
	int mem;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &qid[i].x1, &qid[i].y1);
		scanf("%d %d", &qid[i].x2, &qid[i].y2);
	}
	qsort(qid, n, sizeof(qid[0]), cmp);
	for (int i = 0; i < n; i++) {
		count = 0;
		int x = qid[i].x2;
		int y = qid[i].y2;
		for (int j = i + 1; j < n; j++) {
			if (x == qid[j].x1 && y == qid[j].y1) {
				count++;
				x = qid[j].x2;
				y = qid[j].y2;
			}
		}
		if (count > flag) {
			flag = count;
			mem = i;
		}
	}
	printf("%d %d %d", flag + 1, qid[mem].x1, qid[mem].y1);


	return 0;
}
