#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
	char key[128];
	int times;
	struct node *l,*r;
};
struct node *root;

struct node* newNode(struct node *next){//新建并初始化结点
	next=(struct node*)malloc(sizeof(struct node));
	next->l=next->r=NULL;
	memset(next->key,0,sizeof(next->key));
	next->times=0;
	return next;
}

void writeIn(struct node *now,char* word){
	int cmp=strcmp(now->key,word);
	struct node *temp;
	if(now->key[0]=='\0'){
		strcpy(now->key,word);
		now->times=1;
	}else if(cmp==0){
		now->times++;
	}else if(cmp<0){
		if(now->r==NULL){
			now->r=newNode(now->r);
			now=now->r;
			now->times=1;
			strcpy(now->key,word);
		}else if(strcmp(now->r->key,word)<=0){
			writeIn(now->r,word);
		}else{
			temp=now->r;
			now->r=newNode(now->r);
			strcpy(now->r->key,word);
			now->r->times=1;
			now->r->r=temp;
		}
	}else{
		if(now->l==NULL){
			now->l=newNode(now->l);
			now=now->l;
			now->times=1;
			strcpy(now->key,word);
		}else if(strcmp(now->l->key,word)>=0){
			writeIn(now->l,word);
		}else{
			temp=now->l;
			now->l=newNode(now->l);
			strcpy(now->l->key,word);
			now->l->times=1;			
			now->l->l=temp;			
		}
	}
	return;
}
void writeOut(struct node *now){
	if(now->times==0) return;
	if(now->l!=NULL) writeOut(now->l);
	printf("%s %d\n",now->key,now->times);
	if(now->r!=NULL) writeOut(now->r);
	return;
}
int main(){
	root=newNode(root);
	//读入每一个单词
	FILE *fp=fopen("article.txt","r");
	char word[128]="";
	char c;
	int i=0;
	while((c=getc(fp))!=EOF){
		if(c>='a'&&c<='z'){
			word[i++]=c;
		}else if(c>='A'&&c<='Z'){
			word[i++]=c-'A'+'a';
		}else if(i!=0){
			word[i]='\0';
			writeIn(root,word);
			memset(word,0,sizeof(word));
			i=0;
		}
	}
	if(word[0]!='\0')
		writeIn(root,word);
	writeOut(root);
	
	return 0;
}



