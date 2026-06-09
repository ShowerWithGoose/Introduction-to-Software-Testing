#include <stdio.h>
struct LINE {
	int x1, x2, y1, y2;
};
int number(struct LINE line[100], int i, int n);
int main() {
	int n, i, j, t[100], max, m;
	struct LINE line[100], temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
	}
    for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (line[j + 1].x1 < line[j].x1) {
				temp = line[j + 1];
				line[j + 1] = line[j];
				line[j] = temp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		t[i] = number(line, i, n);
	}
	for (i = 1, max = t[0], m = 0; i < n; i++) {
		if (t[i] > max) {
			max = t[i];
			m = i;
		}
	}
	printf("%d %d %d", max, line[m].x1, line[m].y1);
	return 0;
}
int number(struct LINE line[100], int i, int n) {
	int j;
	for (j = i + 1; j < n; j++) {
		if (line[j].x1 == line[i].x2 && line[j].y1 == line[i].y2) {
			return number(line, j, n) + 1;
		}
	}
	return 1;
}




