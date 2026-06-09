#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct dic {
	char alp;
	int sum;
	struct txt{
		char word[100];
		int num;
	} words[100];
	struct dlc *next;
} LinkList;

LinkList *creat(int num) {
	LinkList *head,*node,*end;
	head=(LinkList*)malloc(sizeof(LinkList));
	end=head;
	int i;
	char c='a';
	for(i=0; i<num; i++) {
		node=(LinkList*)malloc(sizeof(LinkList));
		node->alp=c;
		node->sum=0;
		c++;
		end->next=node;
		end=node;
	}
	end->next=head->next;
	return head;
}

LinkList *sech(LinkList *head,char s) {
	LinkList *node=head->next;
	while(1) {
		if(node->alp==s) {
			break;
		}
		node=node->next;
	}
	return node;
}

int comp(const void *x,const void *y) {
	struct txt *w=x;
	struct txt *q=y;
	return strcmp(w->word,q->word);
}

void store(LinkList *head,char s[]) {
	LinkList *node=sech(head,s[0]);
	int i;
	for(i=0;i<node->sum;i++){
		if(strcmp(node->words[i].word,s)==0){
			node->words[i].num++;
			break;
		}
	}
	if(i==node->sum){
		strcpy(node->words[node->sum].word,s);
		node->words[node->sum].num++;
		node->sum++;
	}
}

void read(FILE *in,LinkList *head) {
	int i;
	char ch;
	char s[100];
	ch=fgetc(in);
	while (ch!=EOF) {
		if(isalpha(ch)) {
			i=0;
			s[i]=tolower(ch);
			i++;
			while(1) {
				ch=fgetc(in);
				if(isalpha(ch)) {
					s[i]=tolower(ch);
					i++;
				} else {
					s[i]='\0';
					break;
				}
			}
			store(head,s);
		}
		ch=fgetc(in);
	}
}

int main() {
	LinkList *head=creat(26),*node;
	node=head->next;
	int i,j,k,l;
	FILE *in;
	in=fopen("article.txt","r");
	read(in,head);
	for(i=0; i<26; i++) {
		qsort(node->words,node->sum,sizeof(node->words[0]),comp);
		for(j=0;j<node->sum;j++){
			printf("%s %d\n",node->words[j].word,node->words[j].num);
		}
		node=node->next;
	}
	
}

