#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int count;
	char word[32];
	struct node *link;
}Lnode,*Linklist;
Linklist head=NULL;
int main(){
	FILE*in;
	in=fopen("article.txt","r");
	char word[32];
	Linklist p,q;
	while(getword(in,word)!=EOF)
		searchword(word);
	for(p=head;p!=NULL;p=p->link){
		printf("%s %d\n",p->word,p->count);
	}
	fclose(in);
	return 0;
}

int getword(FILE *in,char *w){
	int c;
	while(!isalpha(c=fgetc(in)))
		if(c==EOF) return c;
	    else continue;
	do{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(in)));
	*w='\0';
	return 1;
}
//在链表中查找一单词。若找到则次数加一；否则插入到相应位置，同时置次数为1
int searchword(char *w){
	//q为p的前驱
	Linklist p,q=NULL;
	for(p=head;p!=NULL;q=p,p=p->link){
		if(strcmp(w,p->word)<0)
			break;
		else if(strcmp(w,p->word)==0){
			p->count++;
			return 0;
		}
	}
	return insertword(q,w);
}
//在链表中p结点后插入给定单词的结点，同时置次数为1
int insertword(Linklist p,char *w){
	Linklist q;
	q=(Linklist)malloc(sizeof(Lnode));
	strcpy(q->word,w);
	q->count=1;
	q->link=NULL;
	if(head==NULL)
		head=q;
	else if(p==NULL){//插到头结点前
		q->link=head;
		head=q;
	}
	else{
		q->link=p->link;
		p->link=q;
	}
	return 0;
}

