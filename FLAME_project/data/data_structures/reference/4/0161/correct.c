#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char word[500][50];

typedef struct w{
	char c[100];
	int num;
	struct w *next;
}Word;

typedef struct w *Wordptr;
void into_islower(char a[]){
	int i;
	for(i=0;i<strlen(a);i++)
	if(a[i]<='Z'&&a[i]>='A') a[i]=a[i]-'A'+'a';
}


int cut(char b[]){
	int i,k=0,r=0;
	for(i=0;i<strlen(b);i++){
		if(islower(b[i])!=0){
			for(r=0;islower(b[i])!=0;i++,r++)
			word[k][r]=b[i];
			word[k++][r]='\0';
		}
	}
	return k;
}

Wordptr insert(char som[],Word *head){
	Word *p,*q,*r;
	r=(Word *)malloc(sizeof(Word));
	strcpy(r->c,som);
	r->num=1;
	r->next=NULL;
	if(head==NULL)
	return r;
	for(p=head;p!=NULL&&strcmp(som,p->c)>0;q=p,p=p->next);
	if(p==NULL){
		q->next=r;
		return head;
	}
	if(p==head&&strcmp(som,p->c)<0){
		r->next=p;
		return r;
	} 
	else if(strcmp(som,p->c)==0)
	p->num++;
	else{
		q->next=r;
		r->next=p;
	}
	return head;
}
FILE *in;
int main(){
	int i,len;
	char line[1024];
	Word *list=NULL,*p;
	in=fopen("article.txt","r");
	if(in==NULL)
    {
       perror("Can&rsquo;t open article.txt!");
       return -1;
    }
    while(fgets(line,1024,in)!=NULL){
    	memset(word,'\0',sizeof(word));
    	into_islower(line);
		len=cut(line);
		for(i=0;i<len;i++)
		list=insert(word[i],list);
		memset(line,'\0',1024);
	}
	for(p=list;p!=NULL;p=p->next)
	printf("%s %d\n",p->c,p->num);
	for(p=list;p!=NULL;p=p->next)
	free(p);
    fclose(in);
    return 0;
}

