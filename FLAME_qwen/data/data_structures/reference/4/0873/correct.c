#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
char cnt[1100];
struct word1 {
	int count_word;
	char word[20];
}words[100];
#define _CRT_SECURE_NO_WARNINGS 1
int Comp(const void* p1, const void* p2)
{
	return strcmp((*(struct word1*)p1).word, (*(struct word1*)p2).word);
}
int main() {
	FILE* in = fopen("article.txt", "r");
	int i = 0;
	int count_alpha = 0;
	int j, k;
	char c;
	char middle[20];
	memset(middle,0,sizeof(middle));
	c = fgetc(in);
	while (c != EOF) {
		cnt[i] = c;
		i++;
		c = fgetc(in);
	}
	cnt[i] = '\0';
	int lencnt = strlen(cnt);
	for (i = 0; i < lencnt; i++) {
		if (isalpha(cnt[i]))
			cnt[i] = tolower(cnt[i]);
	}
	//for(int i=0;i<lencnt;i++){
	//	printf("%c",cnt[i]);
	//}
	for (i = 0; i < lencnt; i++) {
		if (isalpha(cnt[i])) {
			for (j = i; j < lencnt; j++)
			{
				if (!isalpha(cnt[j]))
					break;
			}
			
			for (k = 0; k < j - i; k++)
			{
				middle[k] = cnt[k + i];
			}
			strcpy(words[count_alpha].word, middle);
			words[count_alpha].count_word = 1;
			//printf("%s\n",words[count_alpha].word);
			count_alpha++;
			i = j;
			memset(middle,0,sizeof(middle));
		}
		else
			continue;

	}
	qsort(words, count_alpha, sizeof(words[0]), Comp);
	for (i = 0; i < count_alpha; i++) {
		if (strcmp(words[i].word, words[i + 1].word)==0) {
			words[i + 1].count_word += words[i].count_word;
			words[i].count_word = 0;
		}
		else
			continue;
	}
	qsort(words, count_alpha, sizeof(words[0]), Comp);
	for (i = 0; i < count_alpha; i++) {
		if (words[i].count_word != 0) {
			printf("%s %d\n", words[i].word, words[i].count_word);
		}
	}
	fclose(in);

	return 0;
}

