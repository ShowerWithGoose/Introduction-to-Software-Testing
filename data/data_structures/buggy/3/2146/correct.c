#include <stdio.h>

int main() {
	char s[101];
	scanf("%s", s);
	int d = 0, dygsz = -1; //d代表小数点位置，dygsz代表第一个数字，由于第一个数字的位置可能为0，所以初始化为-1
	for (int i = 0; i < strlen(s); i++) {
		if (dygsz == -1 && s[i] != '0' && s[i] != '.') {
			dygsz = i; //找到第一个有效数字的位置
			putchar(s[i]);
			if (i != strlen(s) - 1) //此步判断是否需要输出小数点，如0.02转变为科学计数法不需要小数点
				putchar('.');
			continue;
		}
		if (d == 0 && s[i] == '.')
			d = i; //找到小数点的位置
		if (dygsz != -1 && s[i] != '.') //输出除第一位有效数字和小数点以外的其他数字
			putchar(s[i]);
	}
	if (s[0] == '0')
	d++; //小数点前第一位为0的情况
	printf("e%d", d - dygsz - 1);
	return 0;
}
