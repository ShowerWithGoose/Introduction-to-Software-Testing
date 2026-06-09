#include <stdio.h>
#include <string.h>

long long num[1000005];//存储读取的数据
long long flag[1000005];//存储读到的符号 从左往右
char  group[1000005];
int main() {
	long long i, j, k, l, start, end, cnt;
	long long numall = 0, numtmp = 0;
	gets(group);
	for (i = j = 0; group[i] != '\0'; i++) {
		if (group[i] != ' ') {
			group[j++] = group[i];
		}
	}
	group[j] = '\0'; //清除空格
	cnt = j;
	j = 0;
	k = 0;
	start = 0;
	for (i = 0; i < cnt; i++) {
		if (!((group[i] - '0') >= 0 && (group[i] - '0') <= 9)) {
			if (group[i] == '+') {
				flag[k] = 1;
				k++;
			} else if (group[i] == '-') {
				flag[k] = 2;
				k++;
			} else if (group[i] == '*') {
				flag[k] = 3;
				k++;
			} else if (group[i] == '/') {
				flag[k] = 4;
				k++;
			} else {
				flag[k] = 5;
				k++;
			}
			end = i;
			for (start; start < end; start++) {
				num[j] = 10 * num[j] + (group[start] - '0');
			}
			start = i + 1;
			j++;
		}
	}// 将数字存在数组中，并且依次记录读入的符号
	cnt = j;
	i = 0;
	j = 0;
	numall = num[0];
	while (i < k) {
		if (flag[i] == 1 || flag[i] == 2) {//如果是加号或者减号，停止去找下一个加减号，算出中间的数
			j = i + 1;
			while (flag[j] != 1 && flag[j] != 2 && flag[j] != 0) {
				j++;
			}
			if (j > i + 1) {
				numtmp = num[i + 1];//算两个加（减）号之间的数
				for (l = i + 1; l < j; l++) {
					if (flag[l] == 3) {
						numtmp = numtmp * num[l + 1];
					}
					if (flag[l] == 4) {
						numtmp = numtmp / num[l + 1];
					}
				}
				if (flag[i] == 1) {
					numall = numall + numtmp;
					//numtmp = 0;
					i = j;
				} else if (flag[i] == 2) {
					numall = numall - numtmp;
					//numtmp = 0;
					i = j;
				}
			} else if (flag[i] == 1) {
				numall = numall + num[i + 1];
				i++;
			} else {
				numall = numall - num[i + 1];
				i++;
			}
		} else if (flag[i] == 3) {//否则直接乘
			numall = numall * num[i + 1];
			i++;
		} else if (flag[i] == 4) { //否则直接除
			numall = numall / num[i + 1];
			i++;
		} else {
			break;
		}
	}
	printf("%lld", numall);
}
