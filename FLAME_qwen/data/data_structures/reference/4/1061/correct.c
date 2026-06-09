#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<ctype.h>

#define MAXLEN 40

int fgetword(FILE *in,char *w);

struct node{
	char word[MAXLEN];
	int cnt;
	struct node* next;
};
typedef struct node Node;
typedef struct node* Nodeptr;

char WORD[MAXLEN];

int main()
{
	FILE *in;
	Nodeptr walk1,walk2,H1,q;
	
	in = fopen("article.txt","r");
	H1 = NULL;
	while((fgetword(in,WORD))!=EOF){
		q = malloc(sizeof(Node));
		strcpy(q->word,WORD);
		
		if(H1 == NULL){
			H1 = q;
			q->next = NULL;	
		}
		
		for(walk1 = H1;walk1!= NULL && strcmp(WORD,walk1->word)>=0;walk2 = walk1,walk1 = walk1->next){};
		if(walk1 == H1){
			q->next = H1;
			H1 = q;
			q->cnt = 1;
		}else if(strcmp(walk2->word,WORD) == 0){
			walk2->cnt++;
		}else{
			q->next = walk1;
			walk2->next = q;
			q->cnt = 1;
		}
	
	}
	for(walk1 = H1;walk1!=NULL;walk1 = walk1->next){
		printf("%s %d\n",walk1->word,walk1->cnt);
	}
	
	
	return 0;
}

int fgetword(FILE *in,char *w){
	int c = 0;
	
	do{
		if(c == EOF) return EOF;
	}while(!isalpha(c = fgetc(in)));
	do{
		*w++ = tolower(c);
	}while(isalpha(c = fgetc(in)));
	*w = '\0';
	return 1;
}
