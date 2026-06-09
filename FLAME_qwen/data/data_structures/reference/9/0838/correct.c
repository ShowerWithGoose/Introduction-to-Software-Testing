#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//（进阶：贪心算法）洛谷 P1803，寻找课程安排最多的课表
//共同点：对左端点进行排序后，对重复线段合并
struct tanxin {
	int x1;
	int x2;
	int y1;
	int y2;
	int cnt;
};
typedef struct tanxin TX;
TX s[1000];//方便用qsort对结构体的x1和cnt排序
int cmpx1(const void *p1, const void *p2);
int cmpcnt(const void *p1, const void *p2);

int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &s[i].x1, &s[i].y1, &s[i].x2, &s[i].y2);
	}
	qsort(s, n, sizeof(TX), cmpx1);
	for (i = 0; i < n; i++) {
		s[i].cnt = 1;
	}
	for ( i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if ((i == j) || (s[j].x1 < 0)) {
				continue;
			} else {
				if ((s[i].x2 == s[j].x1) && (s[i].y2 == s[j].y1)) {
					s[i].x2 = s[j].x2;//合并延长成一条
					s[i].y2 = s[j].y2;
					s[i].cnt += s[j].cnt;
					s[j].x1 = -1;//合并线段后跳过
					s[j].cnt = 0;//cnt从大往小排，所以没用的调到最小
				}
			}
		}
	}
	qsort(s, n, sizeof(TX), cmpcnt);
	printf("%d %d %d\n", s[n - 1].cnt, s[n - 1].x1, s[n - 1].y1);
	return 0;
}

int cmpx1(const void *p1, const void *p2) {
	struct tanxin *a = (struct tanxin *)p1;
	struct tanxin *b = (struct tanxin *)p2;
	if (a->x1 == b->x1) {
		return a->y1 - b->y2;
	} else {
		return a->x1 - b->x1;
	}
}

int cmpcnt(const void *p1, const void *p2) {
	struct tanxin *a = (struct tanxin *)p1;
	struct tanxin *b = (struct tanxin *)p2;
	return a->cnt - b->cnt;
}
