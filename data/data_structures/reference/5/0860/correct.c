#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct num {
	int x;
	int y;
	struct num *pnext;
} list;

int main() {
	int i, cnt = 0, s, p, cnt1 = 0, k, x1, y1;
	char c1;
	list *Currentlist = NULL, *m, *Headlist1, *Currentlist1;
	list *Headlist = (list *)malloc(sizeof(list));
	Headlist1 = (list *)malloc(sizeof(list));
	Headlist->x = 0;
	Headlist1->x = 0;
	Headlist->y = 0;
	Headlist1->y = 0;
	Headlist->pnext = NULL;
	Headlist1->pnext = NULL;
	do {
		scanf("%d%d%c", &s, &p, &c1);
		if (cnt >= 1) {
			Currentlist->pnext = (list *)malloc(sizeof(list));
			Currentlist = Currentlist->pnext;
			Currentlist->x = s;
			Currentlist->y = p;
			Currentlist->pnext = NULL;
			Currentlist1->pnext = (list *)malloc(sizeof(list));
			Currentlist1 = Currentlist1->pnext;
			Currentlist1->x = s;
			Currentlist1->y = p;
			Currentlist1->pnext = NULL;
			cnt++;
		}
		if (cnt == 0) {
			Headlist->x = s;
			Headlist->y = p;
			Currentlist = Headlist;
			Headlist1->x = s;
			Headlist1->y = p;
			Currentlist1 = Headlist1;
			cnt++;
		}
	} while (c1 != '\n');
	int cnt2 = cnt;
	do {
		i = 0;
		scanf("%d%d%c", &s, &p, &c1);
		if (cnt1 == 0) {
			while (i < cnt) {
				if (i == 0) {
					Currentlist = Headlist;
					Currentlist1 = Headlist1;
				}
				Currentlist1->y = Currentlist->y + p;
				Currentlist1->x = Currentlist->x * s;
				Currentlist = Currentlist->pnext;
				Currentlist1 = Currentlist1->pnext;
				i++;
			}
			cnt1 ++;
		} else {
			for (k = 0; k < cnt; k++) {
				Currentlist = Headlist;
				i = 0;
				while (i < k) {
					Currentlist = Currentlist->pnext;
					i++;
				}
				x1 = s * Currentlist->x;
				y1 = p + Currentlist->y;
				i = 0;
				Currentlist1 = Headlist1;
				while (i < cnt2) {
					if (Currentlist1->y == y1) {
						Currentlist1->x += x1;
						break;
					} else if (y1 < Currentlist1->y && i == cnt2 - 1) {
						m = (list *)malloc(sizeof(list));
						m->x = x1;
						m->y = y1;
						Currentlist1->pnext = m;
						m->pnext = NULL;
						cnt2++;
						break;
					} else if (y1 < Currentlist1->y && y1 > Currentlist1->pnext->y) {
						m = (list *)malloc(sizeof(list));
						m->x = x1;
						m->y = y1;
						m->pnext = Currentlist1->pnext;
						Currentlist1->pnext = m;
						cnt2++;
						break;
					}
					i++;
					Currentlist1 = Currentlist1->pnext;
				}
			}
		}
	} while (c1 != '\n');
	i = 0;
	//printf("cnt2=%d\n", cnt2);
	Currentlist1 = Headlist1;
	while (i < cnt2) {
		printf("%d %d ", Currentlist1->x, Currentlist1->y);
		Currentlist1 = Currentlist1->pnext;
		i++;
	}
	return 0;
}
