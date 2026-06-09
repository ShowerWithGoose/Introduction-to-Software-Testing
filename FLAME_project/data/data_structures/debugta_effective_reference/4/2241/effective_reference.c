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

	int word = 0, u, flag;
	char S[100][15] = {','};
	int time[100] = {0};
	char c[100];
	int sequence[100];

	while (fgets(c, 100, in) != NULL) {
		int y = strlen(c);
		char S[100] = {'\n'};
		for (int i = 0; i <= y; i++) {
			if (c[i] >= 'A' && c[i] <= 'Z') {
				S[i] = c[i] - 'A' + 'a';
			} else S[i] = c[i];
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
			for (int j = 0; j < word; j++) {
				if (selfjudge(ch, S[j])) {
					flag = 1;
					time[j]++;
					break;
				}
			}
			if (flag == 0) {
				strcpy(S[word], ch);
				time[word]++;
				word++;
			}
		}

	}

	for (int i = 0; i < word; i++) {
		sequence[i] = i;
	}
	for (int i = 0; i < word; i++) {
		for (int j = i + 1; j < word; j++) {
			if (sort(S[sequence[i]], S[sequence[j]]) == 1) {
			} else {
				int tpm = sequence[i];
				sequence[i] = sequence[j];
				sequence[j] = tpm;
			}
		}
	}
	for (int i = 0; i < word; i++) {
		printf("%s %d\n", S[sequence[i]], time[sequence[i]]);
	}
	fclose(in);
	return 0;
}

