#include <stdio.h>
int a, b, c, d, e, k;
char oooo;

struct climax {
	int n;
	int g;
	struct climax *link;
} uu[9999], *i, *op; //储存与头指针,尾指针；

struct climaxx {
	int n;
	int g;
	struct climaxx *link;
} uuu[9999], *ii, *opp; //储存与头指针,尾指针；

struct lpl {
	int n;
	int g;
	int y;
	struct lpl *link;
} u[9999], *q, *w;

struct lck {
	int n;
	int g;
	int y;
	struct lck *link;
} v[9999], *x, *s, *r, *f;

int main() {
	while (1) {
		scanf("%d", &uu[a].n);
		scanf("%d", &uu[a].g);
		oooo = getchar();
		if (oooo != ' ') {
			break;
		}
		a++;
	}
	while (2) {
		scanf("%d", &uuu[b].n);
		scanf("%d", &uuu[b].g);
		oooo = getchar();
		if (oooo != ' ') {
			break;
		}
		b++;
	}
	a++;
	b++;
	for (c = 0; c < a; c++) {
		for (d = 0; d < b; d++) {
			u[e].n = uu[c].n * uuu[d].n;
			u[e].g = uu[c].g + uuu[d].g;
			e++;
		}
	}

	for (c = 0; c < e; c++) {
		if (u[c].y != 1) {
			for (d = c + 1; d < e; d++) {
				if (u[c].g == u[d].g) {
					u[c].n = u[c].n + u[d].n;
					u[d].y = 1;
				}
			}
		} else
			continue;
	}
	for (c = 0; c < e; c++) {
		if (u[c].y != 1) {
			v[k].g = u[c].g;
			v[k].n = u[c].n;
			k++;
		}
	}
	x = v;
	for (c = 0; c < k; c++) {
		if (v[c].g < x->g) {
			x = &v[c];
		}
	}
	s = v;
	for (c = 0; c < k; c++) {
		if (v[c].g > s->g) {
			s = &v[c];
		}
	}
	r = s;
	f = s;
	for (c = 0; c < k; c++) {
		if (v[c].g < r->g) {
			r->link = &v[c];
			r = r->link;
		} else if (v[c].g == r->g) {
			continue;
		} else if (v[c].g > r->g) {
			while (3) {
				if (((f->g) > (v[c].g) ) && ((f->link )->g) < (v[c].g)) {
					v[c].link = f->link;
					f->link = &v[c];
					break;
				} else {
					f = f->link;
				}
			}
			f = s;

		}
	}
	while (s != NULL) {
		printf("%d %d ", s->n, s->g);
		s = s->link;
	}
	return 0;
}
