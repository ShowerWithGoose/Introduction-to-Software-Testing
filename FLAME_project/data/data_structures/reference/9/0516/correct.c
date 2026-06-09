#include <stdio.h>
struct line{
	int x1;
	int y1;
}st[105], fin[105];
int mark[105];
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i ++) {
		scanf("%d%d%d%d", &st[i].x1, &st[i].y1, &fin[i].x1, &fin[i].y1);
	}
	struct line hold1;
	struct line hold2;
	int j;
	for (j = 0; j < n; j ++) {
		int k;
		for (k = 0; k < n - j - 1; k ++) {
			if (st[k].x1 > st[k + 1].x1) {
				hold1 = st[k];
				st[k] = st[k + 1];
				st[k + 1] = hold1;
				hold2 = fin[k];
				fin[k] = fin[k + 1];
				fin[k + 1] = hold2;
			}
		}
	}
	int k;
	for (k = 0; k < n; k ++) {
		int m;
		for (m = k + 1; m < n; m ++) {
			if(fin[k].x1 == st[m].x1 && fin[k].y1 == st[m].y1){
				fin[k] = fin[m];
				mark[k] ++;
			}
	}
		}
	int x;
	int final;
	int max = 0;
	for (x = 0; x < n; x ++) {
		if(mark[x] > max) {
			max = mark[x];
			final = x;
		}
	}
	printf("%d %d %d", mark[final] + 1, st[final].x1, st[final].y1);
} 

