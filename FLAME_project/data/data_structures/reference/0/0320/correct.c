#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>







char s[2000] = {}, expand[2000] = {};


//判断是否连接符前后是否是数字、大小写字母并判断类型（体现在返回值上
int legal(int x) {
	if (s[x] >= '0' && s[x] <= '9')
		return 1;
	else if (s[x] >= 'a' && s[x] <= 'z')
		return 2;
	else if (s[x] >= 'A' && s[x] <= 'Z')
		return 3;
	else
		return -1;
}

//是否扩展
int is(int x, int y) {
	//连接符前后字符不全是数字、大小写字母
	if ((legal(x)) == -1 || (legal(y)) == -1)
		return 0;
	//连接符前后字符全是数字、大小写字母并且匹配
	if (legal(x) == legal(y) && (s[y] - s[x]) > 0)
		return 1;
	//连接符前后字符全是数字、大小写字母但不匹配
	else
		return 0;
}

int main() {
	scanf("%s", s);
	int i, k;
	for (i = 0, k = 0; s[i] != '\0'; i++) {
		if (s[i] != '-' || (s[i] == '-' && (is (i - 1, i + 1)) != 1)) {
			expand[k] = s[i];
			k++;
		}
		//when (s[i] == '-' && is(i - 1, i + 1))
		else {
			expand[k++] = s[i - 1] + 1;
			while (expand[k - 1] != s[i + 1]) {
				expand[k] = expand[k - 1] + 1;
				k++;
			}
			i++;
		}
	}
	expand[k] = '\0';

	printf("%s", expand);

	return 0;
}
//che清零

