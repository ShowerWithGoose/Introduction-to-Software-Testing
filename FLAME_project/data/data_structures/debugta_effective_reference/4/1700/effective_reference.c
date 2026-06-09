#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct node{
	char word[50];
	int count;
	struct node *link;
};
struct node *wordlist=NULL;
int getword(FILE *bfp,char *word);
int searchword(char *word);
int insertword(struct node *p,char *word);
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
int insertword(struct node *p,char *word){
	struct node *q;
	q=(struct node*)malloc(sizeof(struct node));
	if(q==NULL)  return -1;
	strcpy(q->word,word);
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
int searchword(char *word)
{
	struct node *p,*q=NULL;
	for(p=wordlist;p!=NULL;q=p,p=p->link)
	{
		if(strcmp(word,p->word)<0)
		   break;
		else if(strcmp(word,p->word)==0)
		{
			p->count++;
			return 0;
		}
	}
	return insertword(q,word);
}
int getword(FILE *fp,char *word)
{
	int c;
	while(!isalpha(c=fgetc(fp)))
	    if(c==EOF) return c;
	    else  continue;
	    do{
	    	*word++=tolower(c);
		}while(isalpha(c=fgetc(fp)));
		*word='\0';
		return 1;
}

