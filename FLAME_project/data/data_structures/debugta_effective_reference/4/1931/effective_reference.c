#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Node{
	char word[50];
	int cnt;
	struct Node * link;
}; 
typedef struct Node dictionary;
typedef struct Node* pDic;
pDic Find(char *tmp,pDic base);
void insert(char* tmp,pDic rear);
int main()
{
	pDic base=(pDic)malloc(sizeof(dictionary));
	pDic ans;
	base->link=NULL;
	FILE * in=fopen("article.txt","r");
	char tmp[50];
	char c;
	int j=0;
	while((c=fgetc(in))!=EOF)
	{
		if(isalpha(c)) {tmp[j++]=tolower(c);}
		else 
		{
		tmp[j]='\0';j=0;
		if(tmp[0]!='\0')
		{ans=Find(tmp,base);
		if(ans->link!=NULL&&strcmp(ans->link->word,tmp)==0) (ans->link->cnt)+=1;
		else insert(tmp,ans);}}
	}
	pDic cut=base,p;
	base=base->link;
	free(cut);
	p=base;
	while(p!=NULL)
	{
		printf("%s %d\n",p->word,p->cnt);
		cut=p;
		p=p->link;
		free(cut);
	}
	return 0;
}
pDic Find(char *tmp,pDic base)
{
	pDic p=base;
	for(p=base;p->link!=NULL&&strcmp(tmp,p->link->word)>0;p=p->link);
	return p;
}
void insert(char* tmp,pDic rear)
{
	pDic ins=(pDic)malloc(sizeof(dictionary));
	ins->cnt=1;
	ins->link=rear->link;
	strcpy(ins->word,tmp);
	rear->link=ins;
	return;
}

