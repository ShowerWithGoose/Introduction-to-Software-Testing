#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>








char origin[2000] = {}, pure[2000] = {};
int step = 0; //处理到字符数组pure[]的哪个元素

//获得数字 传参传的是下标
int getnum(int index) {
	if (pure[index] == '-')
		return (-1) * getnum(index + 1);
	else if (pure[index] == '+')
		return 1 * getnum(index + 1);
	else {
		int tmp = 0;
		for (step = index; pure[step] >= '0' && pure[step] <= '9'; step++)
			tmp = tmp * 10 + pure[step] - '0';
		return tmp;
	}
}

//处理各项 传参传的是数字或者负号
int each(int index) {
	int flag = 0;

	int num = getnum(index);//每项必然是以数字开头

	//printf("getnum(index):%d\n", step);

	while (1) {
		//printf("circulation\n");
		//每项结尾条件（待补充）
		if (pure[step] == '+' || pure[step] == '-')
			break;
		if (pure[step] == '=') //只输入一个数此时pure[step]=='='
			break;

		//进行各种乘除，乘法flag=1，除法flag=2
		if (pure[step] >= '0' && pure[step] <= '9') {
			//printf("judge 2\n");
			if (flag == 1)
				num *= getnum(step);
			else { //(flag == 2) {
				//printf("getnum[2]=%d\n", getnum(2));
				num /= getnum(step);
			}
		} else if (pure[step] == '*') {
			flag = 1;
			//printf("flag1\n");
			step++;
		} else if (pure[step] == '/') {
			flag = 2;
			//printf("flag2\n");
			step++;
			//printf("flag2：step：%d\n", step);
		}
	}
	return num;
}

//是否开始处理每项：数字（例如仅输入500）、加号和减号
int is(int index) {
	if (pure[index] >= '0' && pure [index] <= '9')
		return 1;
	else if (pure[index] == '+' || pure[index] == '-')
		return 1;
	else
		return 0;
}

int main() {
	int res = 0;
	gets(origin);
	//delete 空格
	int i, j = 0;
	for (i = 0, j = 0; origin[i] != '\0'; i++) {
		if (origin[i] != ' ')
			pure[j++] = origin[i];
	}

	//开始处理每一项
	for (; pure[step] != '=';) {
		if (is(step) == 1)
			res += each(step);
	}
	printf("%d\n", res);

	return 0;
}
//che清零

