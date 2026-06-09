#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
FILE* in ;
typedef struct node{
	char word[32];
	int time;
	struct node *link; 
} Node,*Nodeptr;
//Nodeptr create(Nodeptr ,int);
int read(char[]),l=0;
Nodeptr update(Nodeptr,char[]);
void print(Nodeptr);

int main(int argc, char *argv[]) {
	in=fopen("article.txt","r");
	if(in==NULL)return -2;
	char word0[32];
	Nodeptr list=NULL; 
	while(read(word0)!=-1) {
	if(l)list=update(list,word0);	
	}
	print(list);
	fclose(in);
		return 0;
}

int read(char word1[]){
	char ch,flag;
	l=0;
	int i;
	for(i=0;~(flag=fscanf(in,"%c",&ch));i++){
		if(ch>='a'&&ch<='z')word1[i]=ch,l++;
		else if(ch>='A'&&ch<='Z')word1[i]=ch-'A'+'a',l++;
		else 	break;	
	}
	word1[l]='\0';
	return flag+l;
}
Nodeptr update(Nodeptr list,char word0[]){
	Nodeptr p=NULL,q=NULL,r=NULL,s;
	int a;
		
		r=(Nodeptr)malloc(sizeof(Node));
		r->time=1;
		strcpy(r->word,word0);
		r->link=NULL;
		
	if(list==NULL)	return r;//未生成链表 
	
	for(p=list,q=list;
	q!=NULL&&((a=strcmp(word0,q->word))>0);
	p=q,q=q->link);
	
	if(a==0){//链表里有这个词 
		q->time++;
		free(r);
	}
	else{
		if(q==list){//插入首词 
		r->link=q;
		return r;
		}
	
		else{//正常插入 
		r->link=q;
		p->link=r;
		}
	}
	return list;
	
}
void print(Nodeptr list){
	Nodeptr p=list;
	for(;p!=NULL;p=p->link){
		printf("%s %d\n",p->word,p->time);
	}
	
}


