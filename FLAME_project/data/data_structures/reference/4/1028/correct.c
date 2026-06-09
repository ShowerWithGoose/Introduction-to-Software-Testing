#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#define ll long long
int selfjudge(char* ch1, char* ch2) {
	int x = strlen(ch1);
	int y = strlen(ch2);
	int i;
	if (x != y) {
		return 0;
	} else {
		for (i = 0; i < x; i++) {
			if (ch1[i] != ch2[i]) {
				return 0;
			}
		}
	}
	return 1;
}
int sort(char *ch1, char*ch2) { //ÅÅÐò
	int i = 0;
	while (ch1[i] != '\0' || ch2[i] != '\0') {
		if (ch1[i] < ch2[i]) {
			return 1;
		} else if (ch1[i] > ch2[i]) {
			return -1;
		}
		i++;
	}
	return 1;
}
int main () {
	FILE *in;
	in = fopen("article.txt", "r");

	int l = 0, u, flag;
	char alph[100][15] = {','};
	int cishu[100] = {0};
	char s[100];
	int sequence[100];

	while (fgets(s, 100, in) != NULL) {
		int y = strlen(s);
		char S[100] = {'\n'};
		for (int i = 0; i <= y; i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				S[i] = s[i] - 'A' + 'a';
			} else S[i] = s[i];
		}


		for (int i = 0; S[i] != '\0' && S[i] != '\n'; i++) {
			char ch[15] = {","};
			u = 0;
			while (S[i] >= 'a' && S[i] <= 'z' && S[i] != '\0' && S[i] != '\n') {
				ch[u++] = S[i++];
			}
			if (u >= 1) ch[u] = '\0';
			else continue;
			flag = 0;
			for (int j = 0; j < l; j++) {
				if (selfjudge(ch, alph[j])) {
					flag = 1;
					cishu[j]++;
					break;
				}
			}
			if (flag == 0) {
				strcpy(alph[l], ch);
				cishu[l]++;
				l++;
			}
		}

	}

	for (int i = 0; i < l; i++) {
		sequence[i] = i;
	}
	for (int i = 0; i < l; i++) {
		for (int j = i + 1; j < l; j++) {
			if (sort(alph[sequence[i]], alph[sequence[j]]) == 1) {
			} else {
				int tpm = sequence[i];
				sequence[i] = sequence[j];
				sequence[j] = tpm;
			}
		}
	}
	for (int i = 0; i < l; i++) {
		printf("%s %d\n", alph[sequence[i]], cishu[sequence[i]]);
	}
	fclose(in);
	return 0;
}

