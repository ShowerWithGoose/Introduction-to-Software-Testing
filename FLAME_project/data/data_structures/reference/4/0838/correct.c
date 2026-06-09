#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct readcnt {
	char word[200];
	int num;
};
typedef struct readcnt RC;
char s[200], tmp[200];
int i = 0, j, k;
int cnt = 0;
RC a[1000];
int cmp(const void *p1, const void *p2);

int main() {
	FILE *fp1 = fopen("article.txt", "r");
	char c = fgetc(fp1);
	while (c != EOF) {
		s[i++] = c;
		c = fgetc(fp1);
	}
	const int L = i;//文本字符个数
	for (i = 0; i < L; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 'a' - 'A'; //全部转小写
		}
	}
	for (i = 0; i < L; i++) {
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) { //保证都进去的是单词
			for (j = i; j < L; j++) {
				if (!((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z'))) {
					break;//空格等就截止，保证读入单词
				}
			}
			memset(tmp, 0, sizeof(tmp));
			for (k = 0; k < j - i; k++) {
				tmp[k] = s[i + k];//存储单词
			}
			/*for (int k = 0; k < j - i; k++) {
				a[cnt].word = tmp[k];
			}不行，word只能整体读入*/
			strcpy(a[cnt].word, tmp);
			cnt++;
			i = j;//跳到下一个单词开头前一格
		} else {
			continue;
		}
	}
	for (i = 0; i < cnt; i++) {
		a[i].num = 1;
	}
	for (i = 0; i < cnt - 1; i++) {
		for (j = i + 1; j < cnt; j++) {
			if (strcmp(a[i].word, a[j].word) == 0) {
				a[j].num += a[i].num;
				a[i].num = 0; //清空原本词汇
				break;
			}
		}
	}
	qsort(a, cnt, sizeof(RC), cmp);//word排序
	for (i = 0; i < cnt; i++) {
		if (a[i].num == 0) {
			continue;
		} else {
			printf("%s %d\n", a[i].word, a[i].num);
		}
	}
	fclose(fp1);
	return 0;
}

int cmp(const void *p1, const void *p2) {
	struct readcnt *a = (struct readcnt *)p1;
	struct readcnt *b = (struct readcnt *)p2;
	return strcmp(a->word, b->word);
}





