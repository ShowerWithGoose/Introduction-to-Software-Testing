#include <stdio.h>

struct node1 {
	int x1, y1, x2, y2;
} line[110];

int main() {
	int n, k, i = 0, max = 0, vax = 0, v[110] = {0};
	scanf("%d", &n);
	while (i < n) {
		scanf("%d%d%d%d",
		      &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
		i++;
	}
	for (i = 0; i < n; i++) {
		k = i;
		for (int j = 0; j < n; j++) {
			if ((line[k].x2 == line[j].x1) && (line[k].y2 == line[j].y1)) {
				v[i]++;
				k = j;
				j = -1;
			}
		}
		if (v[i] > max) {
			max = v[i];
			vax = i;
		}
	}
	printf("%d %d %d", max + 1, line[vax].x1, line[vax].y1);
	return 0;
}
