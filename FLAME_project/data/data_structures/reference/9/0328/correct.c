#include <stdio.h>
#include <string.h>

struct line {
	int startx;
	int starty;
	int endx;
	int endy;
	int length;
};

int main() {
	int n;
	struct line s[100 + 10];
	struct line h[100 + 10];
	int flag[100 + 10] = {0};
	int flag_1 = 0;
	int cnt = 1;
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d%d", &s[i].startx, &s[i].starty, &s[i].endx, &s[i].endy);
	for (int i = 1; i <= n; i++) {
		if (flag[i] == 0) {
			flag[i] = 1;
			h[cnt] = s[i];
			h[cnt].length = 1;
			cnt++;
		} else
			continue;
		int now = cnt - 1;
		do {
			flag_1 = 0;
			for (int j = 1; j <= n; j++) {
				if (flag[j] != 0)
					continue;
				if (h[now].endx == s[j].startx && h[now].endy == s[j].starty) {
					flag_1 = 1;
					flag[j]++;
					h[now].length++;
					h[now].endx = s[j].endx;
					h[now].endy = s[j].endy;
				}
				if (h[now].startx == s[j].endx && h[now].starty == s[j].endy) {
					flag_1 = 1;
					flag[j]++;
					h[now].length++;
					h[now].startx = s[j].startx;
					h[now].starty = s[j].starty;
				}
			}
		} while (flag_1 == 1);
	}
	int max = 0;
	int num = 0;
	for (int i = 1; i < cnt; i++) {
		if (h[i].length > max)
			max = h[i].length, num = i;
	}
	printf("%d %d %d", h[num].length, h[num].startx, h[num].starty);
	return 0;
}
