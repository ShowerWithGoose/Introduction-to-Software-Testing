#include <stdio.h>
#include <string.h>
int main() {
	char buf[BUFSIZ];
	int spotNumber, flag = 0, miCi = 1, j;
	memset(buf, 0, BUFSIZ);
	fgets(buf, BUFSIZ, stdin);//输入数字
	int n = strlen(buf) - 2; //得到字符数（-2是因为从0开始）
	for (int i = 0; i <= n; i++) {
		if (buf[i] == '.') {
			spotNumber = i; //找到小数点位置
		}
	}//一共有1.0000;1.023;12.234;0.00034;34.0000这五种情况
	if (spotNumber == 1 && buf[0] != '0') { //第一、二种情况：1.0000；1.023；
		for (int i = 2; i <= n; i++) {
			if (buf[i] != '0') {
				flag = 1;
			}
		}
		if (flag == 0) {
			printf("%ce0", buf[0]);
		} else {
			printf("%c.", buf[0]);
			for (int i = 2; i <= n; i++) {
				printf("%c", buf[i]);
			}
			printf("e0");
		}
	} else if (spotNumber > 1) {//12.34 和12.00
		printf("%c.", buf[0]);
		for (int i = spotNumber + 1; i <= n; i++) {
			if (buf[i] != '0') {
				flag = 1;
			}
		}
		if (flag == 0) {
			for (int i = 1; i < spotNumber; i++) {
				printf("%c", buf[i]);
			}
		} else {
			for (int i = 1; i < spotNumber; i++) {
				printf("%c", buf[i]);
			}
			for (int i = spotNumber + 1; i <= n; i++) {
				printf("%c", buf[i]);
			}
		}
		printf("e%d", spotNumber - 1);
	} else { //0.0012
		for (  j = 2; j <= n; j++) {
			if (buf[j] == '0') {
				miCi++;
			} else {
				printf("%c", buf[j]);
				break;
			}
		}
		if (j != n) {
			printf(".");
			for (j++; j <= n; j++) {
				printf("%c", buf[j]);
			}
		}
		printf("e%d", -miCi);
	}

}

