#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct word {
	char w[20];
	int times;
	struct word* next;
} WORD;

int main() {
	char temp[20];
	int len = 0, sign = 1;
	char c;
	FILE *in = fopen("article.txt", "r");
	WORD *Root = (WORD*)malloc(sizeof(WORD));
	Root -> next = NULL;
	while(sign) {
		if((c = fgetc(in))== EOF)
			sign = 0;
		if(isalpha(c))
			temp[len++] = tolower(c);
		else {
			temp[len] = '\0';
			if(len != 0) {
				WORD *p = Root;
				while(p -> next != NULL) {
					if(strcmp(temp, p -> next -> w) <= 0)
						break;
					p = p -> next;
				}
				if(p -> next == NULL) {
					p -> next = (WORD*)malloc(sizeof(WORD));
					p -> next -> times = 1;
					p -> next -> next = NULL;
					strcpy(p -> next -> w, temp);
				} else if(strcmp(temp, p -> next -> w) < 0) {
					WORD *q = (WORD*)malloc(sizeof(WORD));
					q -> times = 1;
					strcpy(q -> w, temp);
					q -> next = p -> next;
					p -> next = q;
				} else {
					p -> next -> times ++;
				}
				len = 0;
			}
		}
	}
	for(WORD* p = Root -> next; p != NULL; Root = p, p = p -> next) {
		printf("%s %d\n", p -> w, p -> times);
		free(Root);
	}
	free(Root);
	return 0;
}

