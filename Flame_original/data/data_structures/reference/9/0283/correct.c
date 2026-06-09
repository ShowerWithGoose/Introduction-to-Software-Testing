#define _CRT_SECURE_NO_WARNINGS 1
#define LINE_MAX 100
#include<stdio.h>
struct LINE {
	int former[2][1];
	int latter[2][1];
	struct LINE* link;
};
struct LINE line[LINE_MAX],ans;
int main() {
	int Line_N;
	scanf("%d\n", &Line_N);
	for (int i = 0; i < Line_N; i++) {
		scanf("%d %d %d %d", &line[i].former[0][0], &line[i].former[1][0], &line[i].latter[0][0], &line[i].latter[1][0]);
	}//读入所有线段的两个端点
	for (int i = 0; i < Line_N; i++) {
		for (int j = 0; j < Line_N; j++) {
			if (j != i) {
				if (line[i].latter[0][0] == line[j].former[0][0] && line[i].latter[1][0] == line[j].former[1][0]) {
					line[i].link = &line[j];
				}
				if (line[j].latter[0][0] == line[i].former[0][0] && line[j].latter[1][0] == line[i].former[1][0]) {
					line[j].link = &line[i];
				}
			}
		}
	}
	int max = 1;
	for (int i = 0; i < Line_N; i++) {
		int cnt = 1;
		struct LINE* p = &line[i];
		while (p->link != NULL) {
			cnt++;
			p = p->link;
		}//直到无后继结点
		if (cnt > max) {
			max = cnt;
			ans = line[i];
		}
	}
	printf("%d %d %d", max, ans.former[0][0], ans.former[1][0]);
	return 0;
}

