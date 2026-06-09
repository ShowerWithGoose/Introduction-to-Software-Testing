#include <stdio.h>
#include <stdlib.h>
struct node{
	int a;
	int n;
}st[105], nd[105], fin[1005];
int main()
{
	char c;
	int i = 0, j = 0;
	while(c != '\n') {
		scanf("%d%d%c", &st[i].a, &st[i].n, &c);
		i ++;
	}
	char x;
	while(x != '\n') {
		scanf("%d%d%c", &nd[j].a, &nd[j].n, &x);
		j ++;
	}
	int k = 0;
	int o = 0, p = 0;
	for (o = 0; o < i ; o ++) {
		for (p = 0; p < j; p ++) {
			fin[k].a = st[o].a * nd[p].a;
			fin[k].n = st[o].n + nd[p].n;
			k ++;
		}
	}
	int y, m;
	for (y = 0; y < k; y ++) {
		for (m = 0; m < k - 1 - y; m ++) {
			if(fin[m].n < fin[m + 1].n) {
				struct node hold;
				hold = fin[m];
				fin[m] = fin[m + 1];
				fin[m + 1] = hold;
			}
			if(fin[m].n == fin[m + 1].n) {
				int mark;
				fin[m].a += fin[m + 1].a;
				for (mark = m + 1; mark < k - 1; mark ++) {
					fin[mark] = fin[mark + 1];
				}
				k --;
			}
		}
	}
	for (y = 0; y < k; y ++) {
		printf("%d %d ", fin[y].a, fin[y].n);
	}
}

