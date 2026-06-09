#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct node{
	char word[50];
	int count;
	struct node *link;
};
struct node *wordlist=NULL;
int getword(FILE *bfp,char *w);
int searchword(char *w);
int insertword(struct node *p,char *w);
int main()
{
	char filename[50]={"article.txt"};
	char word[50];
	FILE *bfp;
	struct node *p;
	if((bfp = fopen(filename, "r")) == NULL){ 
        fprintf(stderr, "%s  can¡¯t open!\n",filename);
        return -1;
    }
	while(getword(bfp,word)!=EOF)
        if(searchword(word)==-1){
        	fprintf(stderr,"Memory is full!\n");
        	return -1;
		}
	for(p=wordlist;p!=NULL;p=p->link)
	{
		printf("%s %d\n",p->word,p->count);
	}
	return 0;
}
int insertword(struct node *p,char *w){
	struct node *q;
	q=(struct node*)malloc(sizeof(struct node));
	if(q==NULL)  return -1;
	strcpy(q->word,w);
	q->count=1;
	q->link=NULL;
	if(wordlist==NULL){
		wordlist=q;
	}
	else if(p==NULL){
		q->link=wordlist;
		wordlist=q;
	}
	else{
		q->link=p->link;
		p->link=q;
	}
	return 0;
}
int searchword(char *w)
{
	struct node *p,*q=NULL;
	for(p=wordlist;p!=NULL;q=p,p=p->link)
	{
		if(strcmp(w,p->word)<0)
		   break;
		else if(strcmp(w,p->word)==0)
		{
			p->count++;
			return 0;
		}
	}
	return insertword(q,w);
}
int getword(FILE *in,char *w)
{
	int c;
	while(!isalpha(c=fgetc(in)))
	    if(c==EOF) return c;
	    else  continue;
	    do{
	    	*w++=tolower(c);
		}while(isalpha(c=fgetc(in)));
		*w='\0';
		return 1;
}

