#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXWORDLEN 32

typedef struct WordNode{
	char word[MAXWORDLEN];
	int cnt;
	struct WordNode *next;
} Node, *NodePtr;

int GetWord(FILE *fp, char *word);
NodePtr UpdateList(NodePtr head, char *word);
NodePtr InsertNode(NodePtr head, NodePtr p_previous, char *word);

int main(void)
{
	FILE *fp = NULL;
	char *file = "article.txt";
	
	NodePtr head = NULL;
	char word[MAXWORDLEN];
	
	if((fp = fopen(file, "r")) == NULL){
		printf("Can't open %s!\n", file);
		return 1;
	}

	while(GetWord(fp, word) != EOF)
		head = UpdateList(head, word);
		
	for(NodePtr p = head; p != NULL; p = p->next)
		printf("%s %d\n", p->word, p->cnt);
	
	return 0;
}

int GetWord(FILE *fp, char *word)
{
	int c;
	
	while(!isalpha(c = fgetc(fp))){
		if(c == EOF)
			return c;
	}
	
	*word++ = tolower(c);
	while(isalpha(c = fgetc(fp)))
		*word++ = tolower(c);
	*word = '\0';
	
	return 1;
}

NodePtr UpdateList(NodePtr head, char *word)
{
	NodePtr head_new = NULL;
	NodePtr p_current = NULL;
	NodePtr p_previous = NULL;
	
	for(p_current = head; p_current != NULL; p_previous = p_current, p_current = p_current->next){
		if(strcmp(word, p_current->word) < 0)
			break;
		else if(strcmp(word, p_current->word) == 0){
			p_current->cnt += 1;
			return head;
		}
	}
	head_new = InsertNode(head, p_previous, word);
	
	return head_new;
}

NodePtr InsertNode(NodePtr head, NodePtr p_previous, char *word)
{
	NodePtr p_insert = (NodePtr)malloc(sizeof(Node));
	NodePtr head_new = NULL;
	
	strcpy(p_insert->word, word);
	p_insert->cnt = 1;
	p_insert->next = NULL;
	
	if(head == NULL){
		head_new = p_insert;
	}
	else if(p_previous == NULL){
		p_insert->next = head;
		head_new = p_insert;
	}
	else{
		p_insert->next = p_previous->next;
		p_previous->next = p_insert;
		head_new = head;
	}
	
	return head_new;
}


