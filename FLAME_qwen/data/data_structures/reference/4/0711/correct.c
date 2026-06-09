#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define tolower(c) (c>='A' && c<='Z'? 'a'-'A'+c:c)//宏函数，解决大小写问题 
struct word {
	char s[50];
	int a ;
} words[1024];
int cmp(const void*a, const void *b) {
	return strcmp(((struct word*)a)->s, ((struct word*)b)->s);
}
int main() {
	char c;
	int i = 0, j = 0, flag = 0;
	FILE*IN;
	if (( IN = fopen ("article.txt", "r")) == NULL) {
		printf("Can't open filein!\n");
		return 1;
	}
	while ((c = fgetc(IN)) != EOF) {
		c =	tolower(c);
		if (c >= 'a' && c <= 'z') {
			if (flag) {
				i++;
			}
			words[i].s[j] = c;
			words[i].a = 1;
			flag = 0;
			j++;
		} else {
			j = 0;
			flag = 1;
		}
	}
	qsort(words, i + 1, sizeof(words[0]), cmp);
	for (int j = 0; j <= i; j++) {
		if (strcmp(words[j].s, words[j + 1].s) == 0) {
			words[j + 1].a += words[j].a;
			words[j].a = 0;
		}
	}
	for (int j = 0; j <= i; j++) {
		if (words[j].a >= 1) {
			printf("%s %d\n", words[j].s, words[j].a);
		}
	}
	return 0;
}

