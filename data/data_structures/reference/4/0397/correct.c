#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct _word {
	char ch[50];
	char num;
} Word;
Word words[300];
int cmp(const void* p1, const void* p2){
	Word* a = (Word*)p1;
	Word* b = (Word*)p2;
	return strcmp(a->ch, b->ch);
}
int main() {
	freopen("article.txt", "r", stdin);
	char ch = getchar();
	int n = 0;
	while (ch != EOF) {
		if (isalpha(ch)) {
			int k = 0;
			Word* p = (Word*)malloc(sizeof(Word));
			p->num = 1;
			while (isalpha(ch)) {
				if (ch >= 65 && ch <= 90) ch += 32; /*´óÐ´×ÖÄ¸*/
				p->ch[k++] = ch;
				ch = getchar();
			}
			p->ch[k] = 0;
			memcpy(&words[n++], p, sizeof(Word));
		}else ch = getchar();
	}
	int skip=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(!strcmp(words[i].ch, words[j].ch) && words[i].num){
				words[i].num += words[j].num;
				memset(&words[j], 0, sizeof(Word));
				skip++;
			}
		}
	}
	qsort(words, n, sizeof(Word), cmp);
	
	
	for(int i=skip;i<n;i++){
		printf("%s %d\n",words[i].ch, words[i].num);
	}

	return 0;
}

