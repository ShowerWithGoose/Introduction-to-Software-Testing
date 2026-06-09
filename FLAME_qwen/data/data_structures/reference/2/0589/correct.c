#include <stdio.h>
#include <string.h>
char a[10000];
int s[10000];
char st[10000];
int t1 = -1, t2 = -1, ans = 0;

int main(void) {
	fgets(a, 9998, stdin);
	int l = strlen(a);
	for (int i = 0; i < l; i++) {
		if (a[i] == ' ')
			continue;
		if ('9' < a[i] || a[i] < '0') {
			s[++t1] = ans;
			ans = 0;
			if (st[t2] == '*') {
				s[t1 - 1] *= s[t1];
				t1--;
				t2--;
			} else if (st[t2] == '/') {
				s[t1 - 1] /= s[t1];
				t1--;
				t2--;
			}
			st[++t2] = a[i];
		} else {
			ans = ans * 10 + a[i] - '0';
		}
	}
	t2--;
	int t = 0;
//	for (int i = 0; i <= t1; i++)
//		printf("%d", s[i]);
	for (int i = 0; i <= t2; i++) {
		if (st[i] == '+') {
			s[t] += s[t + 1];
			s[t + 1] = s[t];
			t++;
		} else {
			s[t] -= s[t + 1];
			s[t + 1] = s[t];
			t++;
		}
	}
	printf("%d", s[t]);

	return 0;
}

