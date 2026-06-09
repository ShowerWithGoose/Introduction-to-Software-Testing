#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct word{
	char word[40];
	int num;
	struct word *next;
} wordnode;
char line[1024],tmp[1024];
wordnode list[3000];
wordnode *first;
int idx;

void strcpy2(int l,int r,char word[])
{
	int i,j;
	for(i=l,j=0;i<=r;i++,j++){
		word[j]=tolower(line[i]);
	}
}

void insert(char word[])
{
	strcpy(list[idx].word,word);
	list[idx].num=1;
	idx++;
}

void find(char word[])
{
	int jd,i;
	if(idx==0) insert(word);
	else{
		for(i=0;i<idx;i++){
			jd=strcmp(word,list[i].word);
			if(!jd) {
				list[i].num++;
				return;
			}
		}
		insert(word);
	}
	return;
}

void order(wordnode l[],int len)
{
	first=&l[0];
	wordnode *p;
	int i,jd1,jd2;
	for(i=1;i<len;i++){
		
		if(strcmp(l[i].word,first->word)<0){
			l[i].next=first;
			first=&l[i];
		}
		
		else{
			p=first;
			while(p->next!=NULL){
				jd1=strcmp(l[i].word,p->word);
				jd2=strcmp(l[i].word,(p->next)->word);
				if(jd1>0&&jd2<0) break;
				p=p->next;
			}
			l[i].next=p->next;
			p->next=&l[i];
		}
	}
}

int main(){
	FILE *in;
	in=fopen("article.txt","r");
	int len,i,j=0,flag=0,fir;
	wordnode *p;
	
	while(fgets(line,1024,in)!=NULL){
		len=strlen(line);
		for(i=0;i<len;i++){
			if(!flag&&isalpha(line[i])){
				fir=i;
				flag=1;
			}
			if(flag&&!isalpha(line[i])){
				strcpy2(fir,i-1,tmp);
				find(tmp);
				flag=0;
				memset(tmp,'\0',1024);
			}
		}
		memset(line,'\0',1024);
	}
	
	order(list,idx);
	for(p=first;p!=NULL;p=p->next) printf("%s %d\n",p->word,p->num);
	
	return 0;
} 

