#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
typedef struct l {
	int x1, y1, x2, y2;
	int head;
	int n_xian;
} List;
List n[110];

int cmp(const void*_a, const void *_b) {
	List *a = (List*)_a;
	List *b = (List*)_b;
	if (a->x1 < b -> x1) return -1;
	else if (a->x1 > b->x1) return 1;
	else if (a->x1 == b->x1) {
		if (a->x2 < b->x2) return -1;
		else if (a->x2 < b->x2) return -1;
		else if (a->x2 == b->x2) {
			if (a->y1 < b->y1 )return -1;
			return 1;
		}
	}
}
int largen, largex, largey;


int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d%d%d%d", &n[i].x1, &n[i].y1, &n[i].x2, &n[i].y2);

		n[i].n_xian = 1;
	}

	qsort(n, num, sizeof(n[0]), cmp);
	for (int i = 0; i < num; i++) {
		n[i].head = i;
	}
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			if ((n[i].x2 == n[j].x1) && (n[i].y2 == n[j].y1)) {
				n[j].head = n[i].head;
				n[j].n_xian = n[i].n_xian + 1;
			}
		}
	}
	for (int i = 0; i < num; i++) {
		if (n[i].n_xian >= largen) {
			largen = n[i].n_xian;
			largex = n[n[i].head].x1;
			largey = n[n[i].head].y1;
		}
	}
	printf("%d %d %d", largen, largex, largey);


	return 0;
}

