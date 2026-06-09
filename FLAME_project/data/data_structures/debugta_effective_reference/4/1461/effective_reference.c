#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char w[500][50];

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
	int i,ALL=0,r=0;
	for(i=0;i<strlen(b);i++){
		if(islower(b[i])!=0){
			for(r=0;islower(b[i])!=0;i++,r++)
			w[ALL][r]=b[i];
			w[ALL++][r]='\0';
		}
	}
	return ALL;
}

Wordptr insert(char som[],Word *list){
	Word *pos,*flag,*r;
	r=(Word *)malloc(sizeof(Word));
	strcpy(r->c,som);
	r->num=1;
	r->next=NULL;
	if(list==NULL)
	return r;
	for(pos=list;pos!=NULL&&strcmp(som,pos->c)>0;flag=pos,pos=pos->next);
	if(pos==NULL){
		flag->next=r;
		return list;
	}
	if(pos==list&&strcmp(som,pos->c)<0){
		r->next=pos;
		return r;
	} 
	else if(strcmp(som,pos->c)==0)
	pos->num++;
	else{
		flag->next=r;
		r->next=pos;
	}
	return list;
}
FILE *in;
int main(){
	int i,all;
	char c[1024];
	Word *list=NULL,*pos;
	in=fopen("article.txt","r");
	if(in==NULL)
    {
       perror("Can&rsquo;t open article.txt!");
       return -1;
    }
    while(fgets(c,1024,in)!=NULL){
    	memset(w,'\0',sizeof(w));
    	into_islower(c);
		all=cut(c);
		for(i=0;i<all;i++)
		list=insert(w[i],list);
		memset(c,'\0',1024);
	}
	for(pos=list;pos!=NULL;pos=pos->next)
	printf("%s %d\n",pos->c,pos->num);
	for(pos=list;pos!=NULL;pos=pos->next)
	free(pos);
    fclose(in);
    return 0;
}

