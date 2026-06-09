#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node{
	char voca[100];
	int count ;
}Node;
Node vol[1000];
int cmp(const void *a,const void *b);
int cut=0;
void getword(FILE *p);
int main(){
	FILE *fp;
	char c;
	
	fp=fopen("article.txt","r");getword(fp);
	qsort(vol,cut,sizeof(Node),cmp);
	for(int i=0;i<cut;i++){
		printf("%s %d\n",vol[i].voca,vol[i].count);
	}
	return 0;
}
void getword(FILE *p){
	char c;
	char temp[100];
	int i=0;
	
	while((c=fgetc(p))!=EOF){
		if(c>'z'||(c>'Z'&&c<'a')||c<'A')continue;
		int flag=0;
		if(isalpha(c)){
			memset(temp,0,sizeof(temp));
			i=0;
			if(c<92)
			c+=32;
			temp[i]=c;
			i++;
			flag=2;
			while((c=fgetc(p))!=EOF&&isalpha(c)){
			if(c<92)
			c+=32;
			temp[i]=c;
			i++;
			}
		}
		temp[i]='\0';
		for(int j=0;j<cut;j++){
			if(strcmp(vol[j].voca,temp)==0){
				vol[j].count++;
				flag=1;
			}
		}
		if(flag==2){
			strcpy(vol[cut].voca,temp);
			vol[cut].count++;
			cut++;
		}
	}
}
int cmp(const void *a,const void *b){
	Node *p=(Node *)a;
	Node *p2=(Node *)b;
	return strcmp(p->voca,p2->voca);
}

