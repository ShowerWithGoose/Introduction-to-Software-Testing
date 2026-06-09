#include <stdio.h>

struct qyx {
	int xishu;
	int zhishu;
} qyx1[1000], qyx2[1000], qyx3[1000];

int main() {
	int l1;
	int l2;
	for (l1 = 0;; l1++) {
		scanf("%d%d", &qyx1[l1].xishu, &qyx1[l1].zhishu);
		if (getchar() == '\n') {
			break;
		}
	}
	l1 += 1;
	for (l2 = 0;; l2++) {
		scanf("%d%d", &qyx2[l2].xishu, &qyx2[l2].zhishu);
		if (getchar() == '\n') {
			break;
		}
	}
	l2 += 1;
	int cj = 0;
	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++, cj++) {
			qyx3[cj].xishu = qyx1[i].xishu * qyx2[j].xishu;
			qyx3[cj].zhishu = qyx1[i].zhishu + qyx2[j].zhishu;
		}
	}
	for (int i = 0; i < cj; i++) {
		for (int j = i + 1; j < cj; j++) {
			if (qyx3[i].zhishu < qyx3[j].zhishu) {
				int temp;
				temp = qyx3[j].zhishu;
				qyx3[j].zhishu = qyx3[i].zhishu;
				qyx3[i].zhishu = temp;
				temp = qyx3[j].xishu;
				qyx3[j].xishu = qyx3[i].xishu;
				qyx3[i].xishu = temp;
			} else if (qyx3[i].zhishu == qyx3[j].zhishu) {
				qyx3[i].xishu += qyx3[j].xishu;
				qyx3[j].xishu = 0;
			}
		}
	}
	for (int i = 0; i < cj; i++) {
		if (qyx3[i].xishu != 0) {
			printf("%d %d ", qyx3[i].xishu, qyx3[i].zhishu);
		}
	}
}
