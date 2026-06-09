#include <stdio.h>
#include <string.h>
char w[1000];
char h[1000];
char y[1000];

int main() {
	gets(w);
	int len_w = strlen(w);
	int y = 0, g = -1;
	for (int i = 0; i < len_w; i++) {
		if (w[i] != '.') {
			h[y] = w[i];
			y++;
		} else if (w[i] == '.') {
			g = i;
			g = g - 1;
		}
	}
	if (h[0] == '0') {
		int flag = 0;
		int i;
		for (i = 0; h[i] == '0'; i++) {
			flag++;
		}
		printf("%c", h[i]);
		if (h[i + 2] != '\0')
			printf(".");
		i++;
		while (h[i] != '\0') {
			printf("%c", h[i]);
			i++;
		}
		printf("e-");
		printf("%d", flag);
//完成了收个数为0的情况
	} else {
		printf("%c", h[0]);
		printf(".");
		int t = 1;
		while (h[t] != '\0') {
			printf("%c", h[t]);
			t++;
		}
		printf("e");
		printf("%d", g);
	}
}
