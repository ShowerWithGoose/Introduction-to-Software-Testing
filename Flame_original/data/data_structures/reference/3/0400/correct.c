#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char n[10086] = "";
	scanf("%s", n);
	int sign = 0, index, e, len = strlen(n);
	for (int i = 0; i < strlen(n); i++) {
		if (n[i] == '.') {
			sign = 1;
			index = i;
		}
	}
	if (sign) {
		int z0 = 0, xf = len - 1;
		for (; z0 < index && n[z0] == '0'; z0++);
		for (; index < xf && n[xf] == '0'; xf--);
		if (z0 == index) {
			z0++;
			for (; z0 < len && n[z0] == '0'; z0++);
		}
		if (z0 == len) {
			printf("0e0");
			return 0;
		}
		printf("%c", n[z0]);
		if (z0 != index && xf != index && z0 < xf) printf(".");
		for (int i = z0 + 1; i <= xf; i++) {
			if (i - index) printf("%c", n[i]);
		}
		if (z0 < index) e = index - z0 - 1;
		else e = index - z0;
		printf("e%d", e);
	}
	else {
		int z0 = 0, xf = len - 1;
		for (; z0 < len && n[z0] == '0'; z0++);
		for (; 0 < xf && n[xf] == '0'; xf--);
		if (z0 == len) {
			printf("0e0");
			return 0;
		}
		printf("%c", n[z0]);
		if (z0 != xf) printf(".");
		for (int i = z0 + 1; i <= xf; i++) {
			printf("%c", n[i]);
		}
		 e = len - z0 - 1;
		printf("e%d", e);
	}
	return 0;
}
