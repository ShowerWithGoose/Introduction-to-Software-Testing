#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

char data[200] = {};

long long getnum(int index) {
	long long num = 0;
	for (int i = index; data[i] != '.' && data[i] != '\0'; i++)
		num = num * 10 + data[i] - '0';
	return num;
}

//找小数点后第一个非零数
int find(int index) {
	int i;
	for (i = index; data[i] == '0'; i++);
	return i;
}

int main() {
	gets(data);
	//找小数点的下标
	int point;
	for (point = 0; data[point] != '.'; point++);
	//x.xx
	if (point == 1) {
		int z = getnum(0);
		if (z > 0 && z < 10)
			printf("%se0\n", data);
		else { //z=0
			int tmp_1 = find(2);//找小数点后第一个非零数
			int tmp_2 = find(2) - 1; //小数点往后移动了几位
			if (data[tmp_1 + 1] == '\0') //0.00002这种
				printf("%ce-%d\n", data[tmp_1], tmp_2);
			else {//0.0234这种
				printf("%c.", data[tmp_1]);
				for (int i = find(2) + 1; data[i] != '\0'; i++)
					printf("%c", data[i]);
				printf("e-%d\n", tmp_2);
			}
		}
	}
	//xx.xx
	else {
		printf("%c.", data[0]);
		for (int i = 1; data[i] != '.'; i++)
			printf("%c", data[i]);
		for (int i = point + 1; data[i] != '\0'; i++)
			printf("%c", data[i]);
		printf("e%d\n", point - 1);
		//printf("%c.%d%de%d\n", data[0], getnum(1), getnum(point + 1), point - 1);
	}
	return 0;
}
//che清零

