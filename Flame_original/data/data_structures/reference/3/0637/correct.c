#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char putin[1000];//i
char qian[1000];//k
int main(){
	int i, h=0, z, x,j=0, k=0;
	double q = 0.0;
	gets(putin);
	if (putin[0] == '0'&&putin[1] == '.'){//整数部分是0，即只有小数
		i = 2;
		while (putin[i] == '0') i++;
		h = -(i - 1);
		while (putin[i] >= '0'&&putin[i] <= '9'){
			if (k == 1){
				qian[k] = '.';
				k++;
			}
			else{
				qian[k] = putin[i]; k++; i++;
			}
		}
		qian[k] = '\0';
		printf("%se%d", qian, h);
	}
	else{//整数部分不是0
		i = 0;
		while (putin[i] != '.') i++;
		h = i-1;
		i = 0;
		while ((putin[i] >= '0'&&putin[i] <= '9') || putin[i] == '.'){
			if (putin[i] == '.') i++;
			else{
				if (k == 1){
					qian[k] = '.';
					k++;
				}
				else{
					qian[k] = putin[i]; k++; i++;
				}
			}
		}
		qian[k] = '\0';
		printf("%se%d", qian, h);
	}
	return 0;
}


