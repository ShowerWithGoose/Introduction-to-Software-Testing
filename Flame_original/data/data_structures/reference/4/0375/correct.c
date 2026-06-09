#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct dictionary *head = NULL;
struct dictionary{
	char word[1024];
	int cnt;
	struct dictionary *next;
};
int isalpha(char c){
	if (( c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
		return 1;
	}
	else return 0;
}
char tolower(char c){
	
	if (c >= 'A' && c <= 'Z'){
		return c - 'A' + 'a';
	}
	else return c;
}
int getword(FILE *in,char *w){
	char c;
	while (!isalpha(c=fgetc(in))){
		if (c == EOF){
			return c;
		}
		else continue;
	}
	do {
		*w++ = tolower(c);
		
	}while (isalpha(c=fgetc(in)));
	*w = '\0';

	return 1;
}
int insertword(char *w){
	struct dictionary *p, *q, *n;
	
	if (head == NULL){
		head = (struct dictionary*)malloc(sizeof(struct dictionary));
		if (head==NULL)return -1;
		strcpy(head->word, w);
		head->cnt =1;
		head->next = NULL;
		p = q = head;
		return 0;
	}
	p = q = head; 
	while (p != NULL && strcmp(p->word, w) < 0){
		q = p;
		p = p->next;
	}
	if (p != NULL && strcmp(p->word, w) == 0){
		p->cnt ++;
	}
	else {
		n = (struct dictionary*)malloc(sizeof(struct dictionary));
		if (n==NULL)return -1;
		strcpy(n->word, w);
		n->cnt =1;
		n->next = NULL;
		if (p == head){
			n->next = head;
			head = n;
		}
		else {
			n->next=q->next;
			q->next=n;
		}
	}
	return 0;
}



int main(){
	struct dictionary *p;
	char word[1024];

	FILE *in;
	if ((in = fopen("article.txt", "r")) == NULL){
		printf("article can't open!\n");
	}
	while ((getword(in, word)) != EOF){
		if (insertword(word) == -1){
			printf("momery is full.");
		} 
	}
	for (p=head; p!=NULL; p=p->next){
		printf("%s %d\n", p->word, p->cnt);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

