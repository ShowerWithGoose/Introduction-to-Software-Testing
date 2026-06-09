#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Line
{
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	int num;
}line;

int cmp(const void* x, const void* y) {
	struct Line* a = (struct Line*)x;
	struct Line* b = (struct Line*)y;
	if (a->start_x == b->start_x) return b->start_y - a->start_y;
	else return b->start_x - a->start_x;
}

int main() {
	int n, max = 0, index = 0;
	struct Line line[105];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &line[i].start_x, &line[i].start_y, &line[i].end_x, &line[i].end_y);
		line[i].num = 1;
	}
	qsort(line, n, sizeof(line[0]), cmp);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (line[j].end_x == line[i].start_x && line[j].end_y == line[i].start_y) line[j].num += line[i].num;
		}
	}
	for (int i = 0; i < n; i++) {
		if (line[i].num > max) {
			max = line[i].num;
			index = i;
		}
	}
	printf("%d %d %d", max, line[index].start_x, line[index].start_y);
}

