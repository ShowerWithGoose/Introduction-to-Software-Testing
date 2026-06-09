#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ll{
	char word[100];
	int time;
	struct ll *link;
}List;
void lowyourword(char line[]){
	int i;
	for(i=0;i<strlen(line);i++){
		if(line[i]>='A'&&line[i]<='Z'){
			line[i]=line[i]-'A'+'a';
		}
	}
}
List * findword(char line[],List *first){
	List *p=NULL,*q=NULL;
	int i,j,num=0;
	char word[100];
	for(i=0;i<strlen(line);i++){
		num=0;
		if(line[i]>='a'&&line[i]<='z'){
			for(;i<strlen(line);i++){
				if(line[i]>='a'&&line[i]<='z'){
					word[num++]=line[i];
				}else{
					word[num]='\0';
					break;
				}
			}
		}
		if(num!=0){
			if(first==NULL){
				p=(List *)malloc(sizeof(List));
				strcpy(p->word,word);
				p->time=1;
				p->link=NULL;
				first=p;
				continue;
			}else{
				p=first;
				if(strcmp(p->word,word)>0){
					q=(List *)malloc(sizeof(List));
					strcpy(q->word,word);
					q->time=1;
					q->link=p;
					first=q;
					continue;
				}else if(strcmp(p->word,word)==0){
					p->time++;
					continue;
				}else{
					int flag=0;
					while(p->link!=NULL){
						if(strcmp(p->word,word)<0&&strcmp(p->link->word,word)>0){
							q=(List *)malloc(sizeof(List));
							strcpy(q->word,word);
							q->time=1;
							q->link=p->link;
							p->link=q;
							flag=1;
							break;
						}else if(strcmp(p->word,word)==0){
							p->time++;
							flag=1;
							break;
						}p=p->link;
					}
					if(p->link==NULL&&flag==0){
						if(strcmp(p->word,word)==0){
							p->time++;
						}else if(strcmp(p->word,word)<0){
							q=(List *)malloc(sizeof(List));
							q->time=1;
							strcpy(q->word,word);
							q->link=NULL;
							p->link=q;
						}
					}
				}
			}
		}
	}
	return first;
}
int main(){
	char line[10000];
	FILE *in;
	List *first=NULL;
	in=fopen("article.txt","r");
	while(fgets(line,10000,in)!=NULL){
		lowyourword(line);
		first=findword(line,first);
	}
	while(first!=NULL){
		printf("%s %d\n",first->word,first->time);
		first=first->link;
	}
	fclose(in);
}



