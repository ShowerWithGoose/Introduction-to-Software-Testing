#include<stdio.h>
int s[100];
int main() {
	int o, n, i = -1;

	while(1) {
		scanf("%d", &o);
		if(o != -1) {
			if(o == 1) {
				if(i == 99) printf("error ");
				else {
					scanf("%d", &n);
					s[++i] = n;
				}
			}

			if(o == 0) {
				if(i == -1) printf("error ");
				else printf("%d ", s[i--]);
			}
		}

		else break;
	}
	return 0;
}

