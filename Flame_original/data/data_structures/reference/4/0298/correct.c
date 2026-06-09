#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct WORD {
	char con[100];
	int count;
	struct WORD* link;
} dicword, *dicptr;

dicptr list = NULL;
int getword(char w[]);
void search(char w[]);
void insert(char w[], dicptr p); 

int main() {
	char word[100];
	freopen("article.txt","r",stdin);
	while(getword(word) != EOF) {
		search(word);
	} 
	for(dicptr i = list; i != NULL; i = i->link) {
		printf("%s %d\n", i->con, i->count);
	}
	fclose(stdin);
	return 0;
}

int getword(char w[]){
	int i = 0;
	char a;
	while((a = getchar()) != EOF){
		if(isalpha(a)) {
			w[i] = tolower(a);
			i++;
		}
		else if(i > 0) {
			w[i] = '\0';
			i = 0;
			return 1;
		}
	}
	return EOF;
}

void search(char w[]){
	dicptr i, j = NULL;
	for(i = list; i != NULL; j = i, i = i->link){
		if(strcmp(w, i->con) < 0){
			break;
		}
		else if(strcmp(w, i->con) == 0){
			i->count ++;
			return ;
		}
	}
	insert(w, j);
	return ;
}

void insert(char w[], dicptr p){
	dicptr q;
	q = (dicptr) malloc (sizeof(dicword));
	strcpy(q->con, w);
	q->count = 1;
	q->link = NULL;
	if(list == NULL){
		list = q;
		return ;
	} 
	else if(p == NULL){
		q->link = list;
		list = q;
		return ;
	}
	else {
		q->link = p->link;
		p->link = q;
		return ;
	}
}

