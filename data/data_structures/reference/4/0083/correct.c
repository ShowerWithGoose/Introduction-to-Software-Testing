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
struct node *Wordlist=NULL;
char type(char c);
int insertWord(Nodeptr p,char *w); 
int getWord(FILE *in,char *w);
int searchWord(char *w);
char type(char c)
{
	if(c>='a'&&c<='z'||c>='A'&&c<='Z')
	return(LE);
	else return (c);
}
int getWord(FILE *in,char *w)
{
	int i=0;
	char c;
	while(type(c=fgetc(in))!=LE)
	if(c==EOF)return c;
	else continue;
	if(c>='A'&&c<='Z')
	c=c-'A'+'a';
	w[i++]=c;
	while((c=fgetc(in))!=EOF){
		if(c>='A'&&c<='Z')
	    c=c-'A'+'a';
		if(type(c)!=LE)
		break;
		w[i++]=c;
	}
    w[i]='\0';
	return 1;
}
int searchWord(char *w)
{
	Nodeptr p,q=NULL;
	for(p=Wordlist;p!=NULL;q=p,p=p->link){
		if(strcmp(w,p->word)<0)
		break;
		else if(strcmp(w,p->word)==0){
			p->count++;
			return 0;
		}
	}
	return insertWord(q,w);
}
int insertWord(Nodeptr p,char *w)
{
	Nodeptr t=NULL;
	t=(Nodeptr)malloc(sizeof(Node));
	strcpy(t->word,w);
	t->count=1;
	t->link=NULL;
	if(Wordlist==NULL)
	Wordlist=t;
	else if(p==NULL){
		t->link=Wordlist;
		Wordlist=t;
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
	for(p=Wordlist;p!=NULL;p=p->link)
	printf("%s %d\n",p->word,p->count);
	fclose(in);
	return 0;
}

