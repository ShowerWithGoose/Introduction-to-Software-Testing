#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 32
#define LE 'a'
struct node{
	char word[MAX];
	int count;
	struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
struct node *list=NULL;
char type(char c);
int insertWord(Nodeptr p,char *s); 
int getWord(FILE *in,char *s);
int searchWord(char *s);
char type(char c)
{
	if(c>='a'&&c<='z'||c>='A'&&c<='Z')
	return(LE);
	else return (c);
}
int getWord(FILE *in,char *s)
{
	int i=0;
	char c;
	while(type(c=fgetc(in))!=LE)
	if(c==EOF)return c;
	else continue;
	if(c>='A'&&c<='Z')
	c=c-'A'+'a';
	s[i++]=c;
	while((c=fgetc(in))!=EOF){
		if(c>='A'&&c<='Z')
	    c=c-'A'+'a';
		if(type(c)!=LE)
		break;
		s[i++]=c;
	}
    s[i]='\0';
	return 1;
}
int searchWord(char *s)
{
	Nodeptr p,q=NULL;
	for(p=list;p!=NULL;q=p,p=p->link){
		if(strcmp(s,p->word)<0)
		break;
		else if(strcmp(s,p->word)==0){
			p->count++;
			return 0;
		}
	}
	return insertWord(q,s);
}
int insertWord(Nodeptr p,char *s)
{
	Nodeptr t=NULL;
	t=(Nodeptr)malloc(sizeof(Node));
	strcpy(t->word,s);
	t->count=1;
	t->link=NULL;
	if(list==NULL)
	list=t;
	else if(p==NULL){
		t->link=list;
		list=t;
	}else{
		t->link=p->link;
		p->link=t;
	} 
	return 0;
}

int main()
{
	FILE *in;
	char file[32],word[MAX],c,a;
	Nodeptr p;
	in=fopen("article.txt","r");
	while(getWord(in,word)!=EOF){
		if(searchWord(word)==-1){
		fclose(in);
		return -1;
	}
	}
	for(p=list;p!=NULL;p=p->link)
	printf("%s %d\n",p->word,p->count);
	fclose(in);
	return 0;
}

