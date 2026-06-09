#define _CRT_SECURE_NO_WARNINGS 1
#define POLY_MAX 10000
#include<stdio.h>
#include<string.h>
typedef struct POLY {
	long long int coco;
	long long int power;
}poly;
poly p1[POLY_MAX], p2[POLY_MAX],p3[POLY_MAX];//分别用来记录原来两个多项式，以及乘法结果
int one_cnt = 0, two_cnt = 0,three_cnt = 0;
char pre[POLY_MAX],tmp;
int main() {
	int flag = 0;
	while ((scanf("%lld %lld%c", &p1[one_cnt].coco, &p1[one_cnt].power,&tmp) != 0)) {
		//printf("%lld %lld\n", p1[one_cnt].coco, p1[one_cnt].power);
		one_cnt++;
		if (tmp == '\n') break;
	}//跳出时，one_cnt为总项数，下标加1
	while (scanf("%lld %lld%c", &p2[two_cnt].coco, &p2[two_cnt].power, &tmp) != 0) {
		//printf("%lld %lld\n", p2[two_cnt].coco, p2[two_cnt].power);
		two_cnt++;
		if (tmp == '\n') break;
	}
	long long int co;
	long long int po;
	for (int i = 0; i < one_cnt; i++) {
		for (int j = 0; j < two_cnt; j++) {//用p1的每一项去乘p2的每一项
			co = p1[i].coco * p2[j].coco;//系数相乘
			po = p1[i].power + p2[j].power;//幂次相加
			for (int k = 0; k < three_cnt; k++) {
				if (p3[k].power == po) {//如果有相同幂次，只需合并同类项
					p3[k].coco = p3[k].coco + co;
					flag = 1;//标记有同类项
				}
			}//查找是否有同类项
			if (flag == 0) {
				p3[three_cnt].coco = co;
				p3[three_cnt].power = po;
				three_cnt++;
			}//没有同类项，新建一个幂次项 three_cnt跳出时为总数
			else flag = 0;//重置flag
		}
	}
	for (int i = 0; i < three_cnt; i++) {
		if (p3[i].coco == 0) {
			for (int j = i; j < three_cnt - 1; j++) {
				p3[j] = p3[j + 1];//删除系数为零的项
			}
			three_cnt--;//总项数减1
		}
	}
	poly tmp;
	for (int i = 0; i <three_cnt; i++) {
		for (int j = 0; j < three_cnt; j++) {
			if (p3[i].power > p3[j].power) {
				tmp = p3[i];
				p3[i] = p3[j];
				p3[j] = tmp;
			}
		}
	}
	for (int i = 0; i < three_cnt; i++) {
		printf("%lld %lld ", p3[i].coco, p3[i].power);
	}
	return 0;
}

