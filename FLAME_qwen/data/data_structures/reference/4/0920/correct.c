#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node {
	char word[50];
	int cnt;
	struct node *link;
}; 
struct node *Wordlist=NULL;//单词表头指针
int insertWord(struct node *p,char *w){
	struct node *q;
	q=(struct node *)malloc(sizeof(struct node));
	if(q==NULL) return -1;//没有内存空间
	strcpy(q->word,w);
	q->cnt=1;
	q->link=NULL;
	if(Wordlist==NULL) Wordlist=q;//空链表
	else if(p==NULL){//插入到头结点前 
		q->link=Wordlist;
		Wordlist=q;
	}
	else{//q插到p后 
		q->link=p->link;
		p->link=q;
	}
	return 0; 
}	
int searchWord(char *w){//在链表中查找一单词，若找到，cnt++；否则执行插入该单词函数 
	struct node *p,*q=NULL;//q为p的前序结点指针
	for(p=Wordlist;p!=NULL;q=p,p=p->link){
		if(strcmp(w,p->word)<0) break;
		else if(strcmp(w,p->word)==0){
			p->cnt++;
			return 0;
		}
	}
	return insertWord(q,w); 
}
int getWord(FILE *in,char word[]){//读入一个单词，并将其转换为小写字母 
	int i=0;
	char tmp;
	while((tmp=fgetc(in))!=EOF){
		if(isalpha(tmp)){
			word[i]=tolower(tmp);
			i++;
		}
		else if(i>0){
			word[i]='\0';
			return 0;
		}
	}
	return EOF;
}
int main(){
	char word[50];
	FILE *in;
	struct node *p;
	if((in=fopen("article.txt","r"))==NULL){
		fprintf(stderr,"%s can't open!","artical");
		return 0;
	}
	while(getWord(in,word)!=EOF){
		if(searchWord(word)==-1){
			fprintf(stderr,"Memory is full!\n");
		  return (-1);
		}
	}
	for(p=Wordlist;p!=NULL;p=p->link) printf("%s %d\n",p->word,p->cnt);
	return 0;
}

