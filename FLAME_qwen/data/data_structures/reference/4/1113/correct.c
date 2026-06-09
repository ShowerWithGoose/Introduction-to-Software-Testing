#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define information count
#define name word
FILE* in;
#define max 10000000
char sentence[max];
char words[50];
typedef struct count {
	char word[50];
	int count;
	struct count* next;
}dictory;
dictory* first1 , * a, * p;
dictory* check(dictory* a,dictory* first1) {
	dictory* first = NULL, * flag = NULL;
	first = first1;
	while (strcmp(a->word,first->word) > 0 && strcmp( first->word,"zzzz") != 0) flag=first,first = first->next;
	if (strcmp(a->word, first->word) == 0) (first->count)++;
	else {
		if (strcmp(first1->word, a->word) > 0) {
			a->count = 1;
			a->next = first1;
			first1 = a;
		}
		else {
			a->count = 1;
			flag->next = a;
			a->next = first;
		}
	}
	
	return first1;
}
int main()
{	
	a= (dictory*)malloc(sizeof(dictory));
	strcpy(a->word, "zzzz");
	a->count = 0;
	first1 = a;
	in = fopen("article.txt", "r");
	while(fgets(sentence, max, in)!=NULL){
		int flag = 0;
		for (int i = 0; i < max && sentence[i] != '\n'; i++) {
			if ((sentence[i]<='z'&&sentence[i]>='a')||(sentence[i]>='A'&&sentence[i]<='Z')) {
				
				if ((sentence[i+1] <= 'z' && sentence[i+1] >= 'a') || (sentence[i+1] >= 'A' && sentence[i+1] <= 'Z')) {
				words[flag] = tolower(sentence[i]);
				flag++;
				}
				else{
					words[flag] = tolower(sentence[i]);
					flag++;
					a = (dictory*)malloc(sizeof(dictory));
					strcpy(a->word, words);
					first1 = check(a, first1);
					memset(words, '\0', 50);
					flag = 0;
				}
			}
			
		}
		memset(sentence, '\0', max);
	}
	while ((strcmp(first1->word, "zzzz") != 0)) {
		printf("%s %d\n", first1->word, first1->count);
		first1 = first1->next;
	}
	return 0;
}
