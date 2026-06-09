#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
char num[110];
int e = 0;

int main() {
	scanf("%s", num);
	int len = strlen(num);
	int i;
	//指数小于零
	if (num[0] == '0') {

		for (i = 2; i < len; i++) {
			if (num[i] == '0') {
				e++;
			} else break;
		}
		printf("%c", num[i]);
		if (num[i + 1] <= '9' && num[i + 1] >= '0') printf(".");
		for (i++; i < len; i++) {
			printf("%c", num[i]);
		}
		printf("e-%d", e + 1);


	}
	// 指数大于零
	else {
		for (i = 0; i < len; i++) {
			if (num[i] != '.') {
				e++;
			} else break;
		}
		printf("%c", num[0]);
		int tmp = i;
		while (num[tmp - 1] == '0') tmp--;
		if (((num[1] <= '9' && num[1] >= '0') || num[1] == '.')&&tmp==i) printf(".");
		//第二位就是小数点
		if (e == 1) {
			for (i = 2; i < len; i++) printf("%c", num[i]);
		}
		//第二位不是小数点
		else {

			for (int j = 1; j < tmp; j++) printf("%c", num[j]);
			for (int j = i + 1; j < len; j++) printf("%c", num[j]);
		}

		printf("e%d", e - 1);
	}
	return 0;
}

