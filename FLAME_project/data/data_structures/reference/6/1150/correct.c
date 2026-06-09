#include<stdio.h>
int st[1002], top;
int main() {
	int x, y;
	while(scanf("%d", &x) != EOF) {
		if(x == -1) return 0;
		if(x == 1) {
			scanf("%d", &y);
			if(top == 100) printf("error ");
			else st[++ top] = y;
		}
		else {
			if(top) printf("%d ", st[top --]);
			else printf("error ");
		}
	}
	return 0;
}
/*
1 3 1 5 1 7 0 0 1 8 0 1 12 1 13 0 0 0 0 1 90 1 89 0 -1
*/

