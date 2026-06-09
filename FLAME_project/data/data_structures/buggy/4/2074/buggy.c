#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int comp(const void* x1, const void* x2) {
	return strcmp((char*)x1, (char*)x2);
}
char wordlist[666][88] = { 0 };
int time[666] = { 0 };
char strin[10001] = { 0 };
char strins[1001];
int main() {
	FILE* fin;
	fin = fopen("filein.txt", "r");


	while ((fgets(strins, 10000, fin)) != NULL) {
		strcat(strin, strins);
	}
		for (int i = 0; i < strlen(strin); i++) {
			if (strin[i] >= 'A' && strin[i] <= 'Z') {
				strin[i] = strin[i] - 'A' + 'a';
			}
		}

		int num = 0;
		for (int i = 0; i < strlen(strin); i++) {
			char word[88] = { 0 }; int len = 0;
			if (strin[i] >= 'a' && strin[i] <= 'z') {

				word[len++] = strin[i];
				for (int j = i + 1; j < strlen(strin); j++) {

					if (strin[j] >= 'a' && strin[j] <= 'z') {
						word[len++] = strin[j];
					}
					else {
						i += len - 1;
						break;
					}
				}
			}int sign = 0;
			for (int j = 0; j < num; j++) {
				if (strcmp(wordlist[j], word) == 0) {
					time[j]++;
					sign = 1;
					break;
				}
			}
			if (sign == 0) {
				time[num]++;
				strcpy(wordlist[num++], word);

			}


		}
		char timec[666][4] = { 0 };

		for (int i = 0; i < num; i++) {
			int slen = strlen(wordlist[i]);
			wordlist[i][slen] = ' ';
			wordlist[i][slen + 1] = '\0';
			sprintf(timec[i], "%d", time[i]);
			strcat(wordlist[i], timec[i]);
		}

		qsort(wordlist, num, 88 * sizeof(char), comp);
		for (int i = 1; i < num; i++) {
			printf("%s\n", (wordlist[i]));
		}
		

	fclose(fin);
	
	return 0;
}
