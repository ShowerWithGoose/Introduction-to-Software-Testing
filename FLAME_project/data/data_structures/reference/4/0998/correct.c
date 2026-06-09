#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
typedef struct l {
	char word[15];
	int n;
} list;

list w[100];
char tmp[105];
char tmpw[105];
int num;//word的个数

int cmp(const int *_a, const int * _b) {
	list *a = (list *)_a;
	list *b = (list *)_b;
	if (strcmp(a->word, b->word) < 0) return -1;
	return 1;
}

int hash;

int main() {
	FILE *in;
	in = fopen("article.txt", "r");

	while (fscanf(in, "%s", tmp) != EOF) {

		int n = strlen(tmp);

		for (int i = 0, j = 0; i < n; i++) { //大小写转换
			if (tmp[i] >= 'a' && tmp[i] <= 'z') {
				tmpw[j++] = tmp[i];
			} else if (tmp[i] <= 'Z' && tmp[i] >= 'A') tmpw[j++] = tmp[i] - 'A' + 'a';
			else if(isalpha(tmp[i+1]))  {
				int nw = strlen(tmpw);
				int i, k;
				for (i = 0; i <= num; i++) { //比较单词
					for ( k = 0; k < nw; k++) {
						if (tmpw[k] != w[i].word[k]) break;
					}
					if (tmpw[k] == 0 && w[i].word[k] == 0) {
						w[i].n++;
						hash = 1;
					} //匹配成功
				}

				if (hash == 0) {
					for (k = 0; k < nw; k++) {
						w[num].word[k] = tmpw[k];

					}
					w[num].n = 1;
					num++;
				}

				hash = 0;
				
				j = 0;
				memset(tmpw, 0, sizeof(tmpw));
				continue;
			}
		}
		int nw = strlen(tmpw);
		int i, j;
		for (i = 0, j; i <= num; i++) { //比较单词
			for ( j = 0; j < nw; j++) {
				if (tmpw[j] != w[i].word[j]) break;
			}
			if (tmpw[j] == 0 && w[i].word[j] == 0) {
				w[i].n++;
				hash = 1;
			} //匹配成功
		}

		if (hash == 0) {
			for (j = 0; j < nw; j++) {
				w[num].word[j] = tmpw[j];

			}
			w[num].n = 1;
			num++;
		}

		hash = 0;
		memset(tmp, 0, sizeof(tmp));
		memset(tmpw, 0, sizeof(tmpw));

	}

	qsort(w, num, sizeof(w[0]), cmp);

	for (int i = 0; i < num; i++) {
		printf("%s %d\n", w[i].word, w[i].n);
	}

	return 0;
}
//
//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//#include<stdio.h>
//#include<ctype.h>
//typedef struct l {
//	char word[15];
//	int n;
//} list;
//
//list w[100];
//char tmp[105];
//char tmpw[105];
//int num;//word的个数
//
//int cmp(const int *_a, const int * _b) {
//	list *a = (list *)_a;
//	list *b = (list *)_b;
//	if (strcmp(a->word, b->word) < 0) return -1;
//	return 1;
//}
//
//int hash;
//
//int main() {
//	FILE *in;
//	in = fopen("article.txt", "r");
//
//	while (fscanf(in, "%s", tmp) != EOF) {
//
//		int n = strlen(tmp);
//
//		for (int i = 0, j = 0; i < n; i++) { //大小写转换
//			if (tmp[i] >= 'a' && tmp[i] <= 'z') {
//				tmpw[j++] = tmp[i];
//			} else if (tmp[i] <= 'Z' && tmp[i] >= 'A') tmpw[j++] = tmp[i] - 'A' + 'a';
//		}
//		int nw = strlen(tmpw);
//		int i, j;
//		for (i = 0, j; i <= num; i++) { //比较单词
//			for ( j = 0; j < nw; j++) {
//				if (tmpw[j] != w[i].word[j]) break;
//			}
//			if (tmpw[j] == 0&&w[i].word[j]==0) {
//				w[i].n++;
//				hash = 1;
//			} //匹配成功
//		}
//
//		if (hash == 0) {
//			for (j = 0; j < nw; j++) {
//				w[num].word[j] = tmpw[j];
//
//			}
//			w[num].n = 1;
//			num++;
//		}
//
//		hash = 0;
//		memset(tmp, 0, sizeof(tmp));
//		memset(tmpw, 0, sizeof(tmpw));
//
//	}
//
//	qsort(w, num, sizeof(w[0]), cmp);
//
//	for (int i = 0; i < num; i++) {
//		printf("%s %d\n", w[i].word, w[i].n);
//	}
//
//	return 0;
//}



