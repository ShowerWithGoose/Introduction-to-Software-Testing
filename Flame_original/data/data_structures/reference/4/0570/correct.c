#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define MAX 100
struct node {
	char word[MAX];
	int count;
	struct node *left, *right;//
};
typedef struct node BSTNode;
typedef struct node* BSTNodeptr;
BSTNodeptr WORDLIST;
char WORD[30];

int getWORD(FILE* op)
{
	int i=0; 
	char c;
	while((c=fgetc(op))!=EOF)
	{
		if((c>=65&&c<=90)||(c>=97&&c<=122)){
			if(c>=65&&c<=90) {
				c+=32;
				WORD[i]=c;
			}
			else WORD[i]=c;
			i++;
		}
		else {
			if(i>=1) return 1;
		}
	}
	return -1;
	
}

BSTNodeptr insertWORD(BSTNodeptr p)
{
	if(p==NULL)
	{
		p=(BSTNodeptr)malloc(sizeof(BSTNode));	 
		strcpy(p->word,WORD);
		p->count=1;
		p->left=p->right=NULL;
	} 
	else
	{
	if(strcmp(p->word,WORD)>0)   p->left=insertWORD(p->left);
	else if(strcmp(p->word,WORD)<0)   p->right=insertWORD(p->right);
	else if(strcmp(p->word,WORD)==0)	p->count++;	
	}
	return p;
}

void printTREE(BSTNodeptr p)
{
	if(p!=NULL){
		printTREE(p->left);
		printf("%s %d\n",p->word,p->count);
		printTREE(p->right); 
	} 
}

int main()
{
	FILE* op;
	op=fopen("article.txt","r");
	while(getWORD(op)!=-1)
	{
		WORDLIST=insertWORD(WORDLIST);
		memset(WORD,0,sizeof(WORD));
	}
	fclose(op); 
	
	/*printf("%s ",WORDLIST->word);
	 printf("%s ",WORDLIST->right->word);
	 printf("%s\n",WORDLIST->right->right->word);*/
	
	printTREE(WORDLIST);
}


