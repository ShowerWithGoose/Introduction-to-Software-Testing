#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treee
{
	char s[1000];
	struct treee*  lchild;
	struct treee*  rchild;
	int cnt;
	
}trie;
char str[1000];
trie* insert(trie* p,char str[])
{
	int temp;
	if(p == NULL)
	{
		p = (trie*)malloc(sizeof(trie));
		strcpy(p->s, str);
		p->cnt = 1;
		p->lchild= NULL;
		p->rchild= NULL;
	}
 
	else if( ( strcmp(str, p->s)) == 0)
	{
		p->cnt++;
	}
	else if( strcmp(str,p->s)<0 )
	{
		p->lchild =insert(p->lchild,str);
	}
	else 
	{
		p->rchild =insert(p->rchild,str);
	}
	return (p);
}

void search(trie* root)
{
	if(root!=NULL)
	{
		search(root->lchild);
		if(strlen(root->s)) printf("%s %d\n",root->s,root->cnt);
		search(root->rchild);
	}
}
int main()
{
	FILE* in;
	in=fopen("article.txt","r");
	char c;
	int i=0;
	trie* root=NULL; 
	while((c=fgetc(in))!=EOF)
	{
//		printf("%c",c);
  	if(isalpha(c)) str[i++]=tolower(c);
  	 
		else 
		{
		
//		 puts(str);
		root=insert(root,str);
		i=0;
		memset(str,0,sizeof(str));}
		
		
	}
	search(root);

	return 0;
	
	
}

