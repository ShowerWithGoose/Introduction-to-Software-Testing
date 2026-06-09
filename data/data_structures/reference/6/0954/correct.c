#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int flag;
	int num;
	int i = 0, j = 0;
	int zhan[500];
	int answer[500];//将出栈数据存到这里
	int count;//记录出栈次数
	while (scanf("%d", &flag)) {
		if (flag == -1) {
			break;
		} else {

			if (flag == 1) {
				scanf("%d", &num);
				if (i >= 100) {
					printf("error ");
				} else {
					zhan[i++] = num;
				}
			} else if (flag == 0) {
				if (i <= 0) {
					printf("error ");
				} else {
					printf("%d ", zhan[i - 1]);
					i -= 1;
				}
			}
		}
	}



	return 0;
}
