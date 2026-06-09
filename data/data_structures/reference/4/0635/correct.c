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
pDic Find(char *s,pDic dic);
void insert(char* s,pDic rear);
int main()
{
	pDic dic=(pDic)malloc(sizeof(dictionary));
	pDic ans;
	dic->link=NULL;
	FILE * in=fopen("article.txt","r");
	char s[50];
	char c;
	int i=0;
	while((c=fgetc(in))!=EOF)
	{
		if(isalpha(c)) {s[i++]=tolower(c);}
		else 
		{
		s[i]='\0';i=0;
		if(s[0]!='\0')
		{ans=Find(s,dic);
		if(ans->link!=NULL&&strcmp(ans->link->word,s)==0) (ans->link->cnt)+=1;
		else insert(s,ans);}}
	}
	pDic cut=dic,p;
	dic=dic->link;
	free(cut);
	p=dic;
	while(p!=NULL)
	{
		printf("%s %d\n",p->word,p->cnt);
		cut=p;
		p=p->link;
		free(cut);
	}
	return 0;
}
pDic Find(char *s,pDic dic)
{
	pDic p=dic;
	for(p=dic;p->link!=NULL&&strcmp(s,p->link->word)>0;p=p->link);
	return p;
}
void insert(char* s,pDic rear)
{
	pDic ins=(pDic)malloc(sizeof(dictionary));
	ins->cnt=1;
	ins->link=rear->link;
	strcpy(ins->word,s);
	rear->link=ins;
	return;
}

