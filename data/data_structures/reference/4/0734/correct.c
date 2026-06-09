#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
		char name[10];
		int number;
	}word[100]; 

int N=0;//现有非空结构体数量

int search(char *s)
{	int i,j,k;
	for(i=0;i<N;i++){//第 i 个现有单词 
		for(j=0;s[j]!='\0'&&word[i].name[j]!='\0';j++)
			if(tolower(s[j])!=tolower(word[i].name[j])) break;
		if(word[i].name[j]=='\0'&&s[j]=='\0') return i;
	}
	return -1;
}

int compare(const void *a,const void *b){
	struct node *p1=(struct node *)a;
	struct node *p2=(struct node *)b;
	return strcmp(p1->name,p2->name);
}

int main()
{	
	FILE *in=fopen("article.txt","r");
	int i,j,k;
	char s[50]={0},Word[50]={0},*p;
	for(i=0;i<100;i++){
		memset(word[i].name,0,10);
		word[i].number=0;
	}
	
	while(fscanf(in,"%s",s)!=EOF){
		
		p=&s[0];
		
	while(*p!=' '&&*p!=0){
			
		while(*p!='\0'&&*p!=' '){
			if(!((*p<='Z'&&*p>='A')||(*p<='z'&&*p>='a')))
				p++;
			else break;
		}
		
		if(*p==0||*p==' ') {
			memset(s,0,50);
			memset(Word,0,50);
			break;
		}
		
		for(i=0;(*p<='Z'&&*p>='A')||(*p<='z'&&*p>='a');i++,p++){
			Word[i]=*p;
		}
		//
		if(search(Word)==-1) {//新单词 
			word[N].number=1;
			for(k=0;Word[k]!=0;k++)
				word[N].name[k]=Word[k]>96?Word[k]:Word[k]+32;//小写 
			N++;
		}	
		else {
			word[search(Word)].number++;
		}
		
		memset(Word,0,50);
		
	}
		memset(s,0,50);
		
	}
		
	qsort(word,N,sizeof(struct node),compare);
	for(i=0;i<N;i++)
		printf("%s %d\n",word[i].name,word[i].number);
	return 0;
}
	
	
	
	
	
	

