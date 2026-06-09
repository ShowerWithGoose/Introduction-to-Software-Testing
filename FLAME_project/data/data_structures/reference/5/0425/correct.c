#include <stdio.h>
#include <string.h>
int a1[100], a2[100], b1[100], b2[100], c1[10000], c2[10000];
char s[1000], str[1000];
int main() {
	int i, j, n = 0, m = 0, k = 0, temp, sum;
	gets(s);
	s[strlen(s)] = '\n';
	while (sscanf(s, "%d %d%[^\n]", &a1[n], &a2[n], str) == 3) {
		strcpy(s, str);
		n++;
	}
	n++;
	gets(s);
	s[strlen(s)] = '\n';
	while (sscanf(s, "%d %d%[^\n]", &b1[m], &b2[m], str) == 3) {
		strcpy(s, str);
		m++;
	}
	m++;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++, k++) {
			c1[k] = a1[i] * b1[j];
			c2[k] = a2[i] + b2[j];
		}
	}
	for (i = 0; i < k - 1; i++) {
		for (j = 0; j < k - i - 1; j++) {
			if (c2[j] < c2[j + 1]) {
				temp = c2[j];
				c2[j] = c2[j + 1];
				c2[j + 1] = temp;
				temp = c1[j];
				c1[j] = c1[j + 1];
				c1[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < k; i = j + 1) {
		for (j = i, sum = c1[j]; c2[j] == c2[j + 1]; j++) {
			sum += c1[j + 1];
		}
		if(sum!=0){
			printf("%d %d ", sum, c2[i]);
		}
	}
	return 0;
}



