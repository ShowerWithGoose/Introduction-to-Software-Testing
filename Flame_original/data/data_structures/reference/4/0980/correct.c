#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

char temp[32]={};
struct LINK{
	char word[32];
	int cnt;
	struct LINK *pre;
	struct LINK *next;
};

int getWord(FILE *in,char temp[]){
	memset(temp,'\0',32);
	int c;
	while(!isalpha(c=fgetc(in))){
		if(c==EOF){
			return c;
		}
		else{
			continue;
		}
	}
	do{
		*temp++=tolower(c);
	}while(isalpha((c=fgetc(in))));
	*temp='\0';
	return 1;
}


struct LINK *article,*head=NULL,*tail=NULL,*find;

int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	while(getWord(in,temp)==1){
		if(head==NULL){
			article=(struct LINK*)malloc(sizeof(struct LINK));
			strcpy(article->word,temp);
			article->pre=NULL;
			article->next=NULL;
			head=tail=article;
			article->cnt=1;
		}
		else{
			int flag=0;
			find=head;
			while(find!=NULL){
				if(strcmp(find->word,temp)==0){
					flag=1;
					break;
				}
				if(strcmp(find->word,temp)>0){
					flag=2;
					break;
				}
				find=find->next;
			}
			if(flag==2){//找到了在链表内部的插入位置
				if(find==head){
					article=(struct LINK*)malloc(sizeof(struct LINK));
					strcpy(article->word,temp);
					article->next=find;
					article->pre=find->pre;	
					find->pre=article;
					head=article;
					article->cnt=1;
					continue;			
				}
				article=(struct LINK*)malloc(sizeof(struct LINK));
				strcpy(article->word,temp);
				article->next=find;
				article->pre=find->pre;
				find->pre->next=article;
				find->pre=article;	
				article->cnt=1;	
			}
			else if(flag==1){//在链表内找到了相同的单词 
				article=find;
				article->cnt++;
				continue;
			}
			else if(find==NULL){//链表内没有此单词 
				article=(struct LINK*)malloc(sizeof(struct LINK));
				strcpy(article->word,temp);
				tail->next=article;
				article->pre=tail;
				tail=tail->next;
				tail->next=NULL;
				article->cnt=1;
			}
		}
	}
	tail->next=NULL;//establish the LINKLIST
	
	article=head;
	while(article!=NULL){
		printf("%s %d\n",article->word,article->cnt);
		article=article->next;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

