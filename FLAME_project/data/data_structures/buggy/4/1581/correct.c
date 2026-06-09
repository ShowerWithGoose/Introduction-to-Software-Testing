#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
FILE *in;
char line[10005];
char W[1005];
struct node{
	char word[1005];
	int num;
	struct node *link;
};
struct node *list=NULL;
int search(char *x);
int insert(char *x,struct node* p);
int main(){
	in=fopen("article.txt","r");
	int top=0,i;
	while((fgets(line,10000,in))!=NULL){
		int len=strlen(line);
		for(i=0;i<len;i++){
			if(line[i]<='z'&&line[i]>='a'){
				W[top++]=line[i];
			}else if(line[i]<='Z'&&line[i]>='A'){
				W[top++]=line[i]+'a'-'A';
			}else if(top>0){
				W[top]='\0';
				top=0;
				search(W);
			}
		}
	}
	struct node *p;
	for(p=list;p!=NULL;p=p->link){
		printf("%s %d\n",p->word,p->num);
	}
	fclose(in);
	return ;
}
int insert(char *x,struct node *p){
	struct node *q;
	q=(struct node*)malloc(sizeof(struct node));
	if(q==NULL)return -1;
	strcpy(q->word,x);
	q->num=1;
	q->link=NULL;
	if(list==NULL){
		list=q;
		return;
	}
	if(p==NULL){
		q->link=list;
		list=q;
		return;
	}
	q->link=p->link;
	p->link=q;
	return 0;
}
int search(char *x){
	struct node *p,*q=NULL;
	for(p=list;p!=NULL;q=p,p=p->link){
		if(strcmp(x,p->word)<0)break;
		if(strcmp(x,p->word)==0){
			p->num++;
			return 0;
		}
	}
	return insert(x,q);
}


