#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define MAXWORD 32
typedef struct tnode{
	char word[MAXWORD];
	int count;
	struct tnode *left,*right;
}tnode,*tnodepr;
void getWord(FILE *bfp,char *w);
tnodepr treeWords(tnodepr p,char *w);
void treeprint(tnodepr p);
void beLight(char*w);
int beWord(int);
int main(){
	char filename[32],word[MAXWORD];
	memset(word,'\0',sizeof(word));
	FILE *bfp;
	tnodepr root=NULL;
	if((bfp=fopen("article.txt","r"))==NULL){
		printf("can't open!\n");
		return -1;
	}
	while(1){
		if(feof(bfp)){
			break;
		}
		getWord(bfp,word);
		beLight(word);
		root=treeWords(root,word);
		memset(word,'\0',sizeof(word));
	}
	/*if(root!=NULL){
		printf("%s ",root->word);
		if(root->right!=NULL){
			printf("%s ",root->right->word);
			if(root->right->right!=NULL){
				printf("%s\n",root->right->right->word);
			}else{
				printf("\n");
			}
		}else{
			printf("\n");
		}
	}*/
	treeprint(root);
	return 0;
}
void beLight(char*w){
	int i=0,j,k;
	for(i=0;i<strlen(w);i++){
		if(w[i]>='A'&&w[i]<='Z'){
			w[i]=w[i]+32;
		}
	}
}
tnodepr treeWords(tnodepr p,char*w){
	if(w[0]=='\0'){
		return p;
	} 
	int cond;
	if(p==NULL){
		p=(tnodepr)malloc(sizeof(tnode));
		strcpy(p->word,w);
		p->count=1;
		p->left=p->right=NULL;
	}else if((cond=strcmp(w,p->word))==0){
		p->count++;
	}else if(cond<0){
		p->left=treeWords(p->left,w);
	}else{
		p->right=treeWords(p->right,w);
	}
	return p;
}
void treeprint(tnodepr p){
	if(p!=NULL){
		treeprint(p->left);
		printf("%s %d\n",p->word,p->count);
		treeprint(p->right);
	}
}
void getWord(FILE *bfp,char *w){
	int a,i=0;
	while(1){
		if(feof(bfp)){
			break;
		}
		a=fgetc(bfp);
		if(beWord(a)){
			w[i++]=a;
		}else{
			break;
		}
	}
}
int beWord(int n){
	char c=(char)n;
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
		return 1;
	}else{
		return 0;
	}
}

