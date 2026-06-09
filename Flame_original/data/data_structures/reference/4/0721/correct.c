#include<stdio.h>
#include<ctype.h>
#include<string.h> 
#include<stdlib.h>

//int cmp(const void *a, const void *b) {
//	int* c = (int *)a;
//	int* d = (int *)b;
//	return *c - *d;
//}

struct wordCnter {
	char word[105];
	int cnt;
} w[200];

int num = 0;

int cmp(const void *a, const void *b) {
	struct wordCnter *s1 = (struct wordCnter *)a;
	struct wordCnter *s2 = (struct wordCnter *)b;
	return strcmp(s1->word, s2->word);
}

int main()
{
	FILE *in;
	char article[100000] = {};
	in = fopen("article.txt", "r");
	int len = fread(article, 1, 100000, in);
	char s[100][50] = {};
	char tmp[50];
	char ch;
	int i = 0, j = 0,k;
	
	while (i < len) {
		j = 0;
		if (isalpha(article[i])) {
			while(isalpha(article[i])) {
				tmp[j] = tolower(article[i]);
				i++;
				j++;
			}
			tmp[j] = '\0';
			for (k = 0; k < num; k++) {
				if (strcmp(w[k].word, tmp) == 0) {
					w[k].cnt++;
					break;
				}
			}
			if (k == num) {
				strcpy(w[num].word, tmp);
				w[num].cnt++;
				num++;
			}
		}
		i++;
	}
	qsort(w, num, sizeof(w[0]), cmp);
	for(i = 0; i < num; i++)
	{
		printf("%s %d\n", w[i].word, w[i].cnt);
	}
	return 0;
 } 

