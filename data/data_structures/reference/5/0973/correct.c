#include <stdio.h>
#include <stdlib.h>

typedef struct number {
	int zhi;
	int xi;
} Num;

int search(Num *multi, int zhi, int sum) {
	for (int p = 0; p < sum; p++) {
		if (multi[p].zhi == zhi)
			return p;
	}
	return -1;
}

int cmp(Num *e1, Num *e2) {
	return e2->zhi - e1->zhi;
}

int main() {
	Num first[100] = {}, second[100] = {}, multi[100] = {};
	int sum1 = 0, sum2 = 0, sum3 = 0;
	char c;
	for (sum1 = 0; sum1 < 100; sum1++) {
		scanf("%d %d", &first[sum1].xi, &first[sum1].zhi);
		c = getchar();
		if (c == '\n')
			break;
	}
	for (sum2 = 0; sum2 < 100; sum2++) {
		scanf("%d %d", &second[sum2].xi, &second[sum2].zhi);
		c = getchar();
		if (c == '\n')
			break;
	}
	for (int i = 0; i <= sum1; i++) {
		for (int k = 0; k <= sum2; k++) {
			int xishu = 0, zhishu = 0;
			xishu = first[i].xi * second[k].xi;
			zhishu = first[i].zhi + second[k].zhi;
			if (search(multi, zhishu, sum3) == -1) {
				multi[sum3].xi = xishu;
				multi[sum3].zhi = zhishu;
				sum3++;
			} else {
				int p = search(multi, zhishu, sum3);
				multi[p].xi += xishu;
			}
		}
	}
	qsort(multi, sum3, sizeof(Num), cmp);
	for (int i = 0; i < sum3; i++) {
		printf("%d %d ", multi[i].xi, multi[i].zhi);
	}
	return 0;
}
