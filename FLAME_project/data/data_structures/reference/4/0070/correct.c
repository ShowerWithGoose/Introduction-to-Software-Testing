#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct node{
	char word[32];
	int num;
	struct node *link;
}node;
node *head=NULL;
int getWord(FILE *fp,char *w);
 int searchWord(char *w);
 int insertWord(node *x,char *w);

int main(){
	node *p;
	char filename[32],word[32];
	//p=(node *)malloc(sizeof(node));
	FILE *IN;
	
	//scanf("%s",filename);
	IN=fopen("article.txt","r");
	/*if((IN=fopen(filename,"r"))==NULL){
		fprintf(stderr,"can't open!\n",filename);
		return -1;
	}*/
	while(getWord(IN,word)!=EOF){
		searchWord(word);
	}
	for(p=head;p!=NULL;p=p->link){
		printf("%s %d\n",p->word,p->num);
	}
	//free(p);
	return 0;
}

int getWord(FILE *fp,char *w){
	char c;
	while(!isalpha(c=fgetc(fp))){
		if(c==EOF){
			return c;
		}else{
			continue;
		}
	}
	do{
		*w=tolower(c);
		w++;
	}while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}

int insertWord(node *x,char *w){
	node *y;
	y=(node *)malloc(sizeof(node));
	if(y==NULL){
		free(y);
		return -1;//没有内存空间 
	}
	strcpy(y->word,w);
	y->num=1;
	y->link=NULL;
	if(head==NULL){
		head=y;
	}else if(x==NULL){
		y->link=head;
		head=y;
	}else{
		y->link=x->link;
		x->link=y;
	}
//	free(y);
//	free(x);
	return 0;
}
int searchWord(char *w){
	node *p=NULL,*q=NULL;
	//p=(node *)malloc(sizeof(node));
	//q=(node *)malloc(sizeof(node));
	for(p=head;p!=NULL;q=p,p=p->link){
		if(strcmp(w,p->word)<0){
			break;
		}else if(strcmp(w,p->word)==0){
			p->num++;
			//free(p);
			//free(q);
			return 0;
		}
	}
	//free(p);
	
	return insertWord(q,w);
}


























