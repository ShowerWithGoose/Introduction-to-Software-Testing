#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct zhan {
	int num;
};

int  deleteElem(struct zhan shuzu[], int i, int summ) { //删除
	int k;

	for ( k = i + 1; k < summ; k++ ) { /* 元素依次前移一个位置 */
		shuzu[k - 1].num = shuzu[k].num;
	}

	return 1;                                                     /* 删除成功 */
}

int main() {
	struct zhan shuzu[100];

	int sum = 0;

	int choice;
	int num;

	while (1) {
		scanf("%d", &choice);
		int op = 0;

		if (choice == 0) { //出栈
			if (sum == 0) {
				printf("error ");
			} else {
				printf("%d ", shuzu[sum - 1].num);
				sum--;
			}
		} else if (choice == 1) { //入栈
			scanf("%d", &num);
			if (sum == 100) {
				printf("error ");
			} else {
				shuzu[sum].num = num;
				sum++;
			}
		} else if (choice == -1) {
			break;
		}
	}

	return 0;
}

































