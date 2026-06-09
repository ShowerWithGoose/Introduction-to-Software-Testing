#include<stdio.h>
int main() {
	int a[101] = { 0 }, flag, x, i = 0;
	scanf("%d", &flag);
	while (flag != -1) {
		if (flag == 1) {
			if (i >= 100) 
				printf("error ");
			else {
				scanf("%d", &x);
				a[i++] = x;
			}
		}
		else if (flag == 0) {
			if (i == 0) 
				printf("error ");
			else {
				printf("%d ", a[--i]);
			}
		}
		scanf("%d",&flag);
	}
	return 0;
}

