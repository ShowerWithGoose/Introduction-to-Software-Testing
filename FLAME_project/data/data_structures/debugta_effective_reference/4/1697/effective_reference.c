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
int read(char[]),i=0;
Nodeptr update(Nodeptr,char[]);
void print(Nodeptr);

int main(int argc, char *argv[]) {
	in=fopen("article.txt","r");
	if(in==NULL)return -2;
	char c[32];
	Nodeptr list=NULL; 
	while(read(c)!=-1) {
	if(i)list=update(list,c);	
	}
	print(list);
	fclose(in);
		return 0;
}

int read(char word1[]){
	char ch,flag;
	i=0;
	int i;
	for(i=0;~(flag=fscanf(in,"%c",&ch));i++){
		if(ch>='a'&&ch<='z')word1[i]=ch,i++;
		else if(ch>='A'&&ch<='Z')word1[i]=ch-'A'+'a',i++;
		else 	break;	
	}
	word1[i]='\0';
	return flag+i;
}
Nodeptr update(Nodeptr list,char c[]){
	Nodeptr p=NULL,r=NULL,q=NULL,s;
	int a;
		
		q=(Nodeptr)malloc(sizeof(Node));
		q->time=1;
		strcpy(q->word,c);
		q->link=NULL;
		
	if(list==NULL)	return q;//未生成链表 
	
	for(p=list,r=list;
	r!=NULL&&((a=strcmp(c,r->word))>0);
	p=r,r=r->link);
	
	if(a==0){//链表里有这个词 
		r->time++;
		free(q);
	}
	else{
		if(r==list){//插入首词 
		q->link=r;
		return q;
		}
	
		else{//正常插入 
		q->link=r;
		p->link=q;
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


