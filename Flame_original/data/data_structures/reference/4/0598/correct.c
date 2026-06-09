#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct WordNode
{
	int count;
	char* word;
	struct WordNode* next;
}WordNode;

void lower(char* str) {
	int i = 0;
	while (str[i]) {
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
		i++;
	}
}

int isAlpha(char ch) {
	if (ch >= 'A' && ch <= 'Z') return 1;
	if (ch >= 'a' && ch <= 'z') return 1;
	return 0;
}

int main() {
	char ch;

	char word[10000];
	int length = 0;

	WordNode* prev;
	WordNode* curr;

	WordNode* dummyHead = (WordNode*)malloc(sizeof(WordNode));
	dummyHead->count = 0;
	dummyHead->word = NULL;
	dummyHead->next = NULL;

	FILE* article = fopen("article.txt", "r");

	while ((ch = fgetc(article)) != EOF) {

		if (isAlpha(ch))

			word[length++] = ch;

		else if (length) {

			word[length] = '\0';
			lower(word);

			prev = dummyHead;
			curr = prev->next;

			while (curr) {
				if (strcmp(word, curr->word) <= 0) break;
				curr = curr->next;
				prev = prev->next;
			}

			if (!curr) {
				prev = prev->next = (WordNode*)malloc(sizeof(WordNode));
				prev->count = 1;
				prev->word = (char*)malloc((length + 1) * sizeof(char));
				prev->next = NULL;
				strcpy(prev->word, word);
			}

			else if (strcmp(word, curr->word) < 0) {
				prev = prev->next = (WordNode*)malloc(sizeof(WordNode));
				prev->count = 1;
				prev->word = (char*)malloc((length + 1) * sizeof(char));
				prev->next = curr;
				strcpy(prev->word, word);
			}

			else {
				curr->count++;
			}

			length = 0;
		}
	}

	WordNode* head = dummyHead->next;
	curr = head;
	free(dummyHead);
	while (curr) {
		printf("%s %d\n", curr->word, curr->count);
		curr = curr->next;
	}
	
	return 0;
}
