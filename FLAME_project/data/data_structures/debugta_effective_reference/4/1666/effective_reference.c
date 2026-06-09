#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct WORD {
	char s[100];
	int con;
	struct WORD* link;
} dicword, *dicptr;

dicptr list = NULL;
int getword(char w[]);
void search(char w[]);
void insert(char w[], dicptr p); 

int main() {
	char c[100];
	freopen("article.txt","r",stdin);
	while(getword(c) != EOF) {
		search(c);
	} 
	for(dicptr p = list; p != NULL; p = p->link) {
		printf("%s %d\n", p->s, p->con);
	}
	fclose(stdin);
	return 0;
}

int getword(char w[]){
	int p = 0;
	char a;
	while((a = getchar()) != EOF){
		if(isalpha(a)) {
			w[p] = tolower(a);
			p++;
		}
		else if(p > 0) {
			w[p] = '\0';
			p = 0;
			return 1;
		}
	}
	return EOF;
}

void search(char w[]){
	dicptr p, p1 = NULL;
	for(p = list; p != NULL; p1 = p, p = p->link){
		if(strcmp(w, p->s) < 0){
			break;
		}
		else if(strcmp(w, p->s) == 0){
			p->con ++;
			return ;
		}
	}
	insert(w, p1);
	return ;
}

void insert(char w[], dicptr p){
	dicptr q;
	q = (dicptr) malloc (sizeof(dicword));
	strcpy(q->s, w);
	q->con = 1;
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

