//getword有问题，在单词不以空格分隔时会出现读入错误， 还是希望能改成调用一次函数就能读取一个单词的功能 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct node{
	int t; 
	char s[233];
	struct node *pnext;
}node;
node *head=NULL;	//dummy node
char sread[233]=" ";
int getword(FILE *);
int check(char*);
int main(){
	head =(node*)malloc(sizeof(node));
	head->pnext = NULL;
	FILE *read;
	read = fopen("article.txt", "r");
	while(getword(read) != -1){		//the last node point to NULL plz
		if(check(sread) == -1){		//new word(initialize t plz)
			if(head->pnext == NULL){	//empty list
				node *p=(node *)malloc(sizeof(node));
				strcpy(p->s, sread);
				p->t = 1;
				p->pnext = NULL;
				head->pnext = p;
				continue;
			}
			node *insert=head->pnext;
			node *beinsert = head;
			if(strcmp(sread,insert->s) < 0){
				node *p = (node *)malloc(sizeof(node));
				strcpy(p->s, sread);
				p->t = 1;
				p->pnext = insert;
				head->pnext = p;			//sread成为第一个节点 
			}
			else{
				int flag=0;
				while(strcmp(sread, insert->s) > 0){		
					if(insert->pnext != NULL){
						insert = insert->pnext;
						beinsert = beinsert->pnext;	
					}
					else if(insert->pnext == NULL){
						flag=1;
						break;
					}
				}
				if(1==flag){	//put new to the tail
					node *p=(node *)malloc(sizeof(node));
					strcpy(p->s, sread);
					p->t = 1;
					p->pnext = NULL;
					insert->pnext = p;
				}
				else if(0==flag){	//beinsert-new-insert
					node *p=(node *)malloc(sizeof(node));
					strcpy(p->s, sread);
					p->t = 1;
					p->pnext = insert;
					beinsert->pnext = p;
				}
			}
		}
		else if(check(sread) >= 0){
			node *plus=head;
			for(int k=0; k<1+check(sread); plus=plus->pnext, k++);
			plus->t += 1;
			//t+1
		}
	}
	
	node *pr=head->pnext;
	while(pr != NULL){
		printf("%s %d\n", pr->s, pr->t);
		pr = pr->pnext;
	}
	//print
	
	return 0;	
} 
int getword(FILE *r){
	char c, w[233]="";
	int i=0, flag=0;
	while((c=fgetc(r)) != EOF){
		if(!isalpha(c)){
			if(1==flag){
				memset(sread,0,sizeof(sread));
				strcpy(sread, w);
				return 0;
			}
			else if(0==flag)	continue;
		}
		else if(isalpha(c)){
			flag=1;
			w[i++] = isupper(c) ? c+'a'-'A' : c;
		}
	}
	return -1;
}
int check(char* a){
	node *p=head->pnext;
	int i;
	for(i=0; p!=NULL; p=p->pnext, i++){
		if(strcmp(a,p->s) == 0)
			return i;	//i是从head往后读的个数-1, cuz head is a dummy node
	}
	return -1;
}



