#include<stdio.h>
#include<math.h>
#include<string.h>
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define eps 1e-10
#define MAX(a,b) ((a)>(b)?(a) : (b))
#define MIN(a,b) ((a)>(b)?(a) : (b))
struct d {
	int a;
	int b;
};
void sort(struct d m[], int n) {
	int i, j;
	struct d a;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - i - 1; j++) {
			if (m[j].b < m[j + 1].b) {
				a = m[j];
				m[j] = m[j + 1];
				m[j + 1] = a;
			}
		}
	}
}
int main() {
	struct d d1[100], d2[100], d3[10000], d4[10000];
	int i = 1, j, k = 1;
	char c;
	while (1) {
		sf("%d", &d1[i].a);
		sf("%d", &d1[i].b);
		sf("%c", &c);
		if (c == '\n') {
			break;
		}
		i++;
	}
	int t1 = i;
	i = 1;
	while (1) {
		sf("%d", &d2[i].a);
		sf("%d", &d2[i].b);
		sf("%c", &c);
		if (c == '\n') {
			break;
		}
		i++;
	}
	int t2 = i;
	k = 1;
	for (i = 1; i <= t1; i++) {
		for (j = 1; j <= t2; j++) {
			d3[k].a = d1[i].a * d2[j].a;
			d3[k].b = d1[i].b + d2[j].b;
			k++;
		}
	}
	sort(d3, t1 * t2);
	k = 1;
	int flag = 0;
	for (i = 1; i <= t1 * t2; i++) {
		d4[k].a = d3[i].a;
		d4[k].b = d3[i].b;
		for (j = i + 1; j <= t1 * t2; j++) {
			if (d3[i].b == d3[j].b) {
				d4[k].a += d3[j].a;
				flag++;
			} else {
				k++;
				break;
			}
		}
		i = j - 1;
	}
	for (k = 1; k <= t1 * t2 - flag; k++) {
		pf("%d ", d4[k].a);
		pf("%d ", d4[k].b);
	}
	return 0;
}

