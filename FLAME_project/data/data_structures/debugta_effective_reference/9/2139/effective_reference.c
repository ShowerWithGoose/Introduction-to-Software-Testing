#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line {
	int x1, y1, x2, y2;
} lines[105], linestart;//构造结构体，包括所有线段
int cmp(const void*a, const void*b) {
	return  ((struct line* )b)->x1 - ((struct line*) a)->x1;
}
int main() {
	int n, max = 0, k, numLine = 0; //max记录线段最多数
	scanf("%d", &n);
	for (int i = 0; i <= n - 1; i++) {
		scanf("%d", &lines[i].x1);//输入线段
		scanf("%d", &lines[i].y1);
		scanf("%d", &lines[i].x2);
		scanf("%d", &lines[i].y2);
	}
	qsort(lines, n, sizeof(lines[0]), cmp);//按x1的大小进行排序,从大到小
	for (int k = 0; k <= n - 2; k++) {//遍历
		k = k;
		for (int j = k + 1; j <= n - 1; j++) {
			if (lines[k].x1 == lines[j].x2 && lines[k].y1 == lines[j].y2) {//从x1最大的开始，查找到适配的则从适配的线段继续分析
				k = j;
				numLine++;
			}
		}
		if (max < numLine) {
			max = numLine;
			linestart = lines[k];
		}
		numLine = 0;
	}
	printf("%d %d %d", max+1, linestart.x1, linestart.y1);
	}

