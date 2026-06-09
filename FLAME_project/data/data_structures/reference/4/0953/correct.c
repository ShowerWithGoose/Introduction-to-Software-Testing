#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 10005
struct node{
	int a;
	char x[100];
}m[N];
char word1[1005];
int cmp(const void*a,const void *b){
	struct node* p=(struct node*)a;
	struct node* q=(struct node*)b;
	return strcmp(p->x,q->x);
}
int check(char word[],int h){
	for(int i=0;i<h;i++){
		if(strcmp(word,m[i].x)==0){
			m[i].a++;
			return 1;
		}
	}
	return 0;
}
int main(){
	FILE *in;
	int h=0;
	char word[100];
//	for(int)
	in=fopen("article.txt","r");
	while(fgets(word1,1000,in)!=NULL){
		int l=0;
		for(int i=0;i<strlen(word1)+1;i++){
		if(isalpha(word1[i])){
			if(word1[i]>='A'&&word1[i]<='Z') word[l++]=word1[i]+'a'-'A';
			else word[l++]=word1[i];
		}	
		else{
		if(l>0){
		word[l]='\0';	
		if(check(word,h)){
		}
		else{
			strcpy(m[h].x,word);
			m[h].a=1;
			h++;
		}	
		l=0;
		word[0]='\0';
		}
		else continue;
		}
		}
	}
	qsort(m,h,sizeof(struct node),cmp);
	for(int i=0;i<h;i++)
	printf("%s %d\n",m[i].x,m[i].a);
	return 0;
}



