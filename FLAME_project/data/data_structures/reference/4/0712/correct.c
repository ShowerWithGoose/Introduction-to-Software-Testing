#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
struct w{
	char s[15];
	int time;
	struct w *next;
}word,*p,*const_start; 
char s[1024]={'0'};
void deal(char *s_now,int len);
int flag=0;

int main(){
	FILE *in;
	in=fopen("article.txt","r");
	p=(struct w*)malloc(sizeof(struct w));
	const_start=p;
	while(fgets(s,1024,in)!=NULL){
//		puts(s);
//printf("%d\n",strlen(s));
		deal(s,strlen(s));
	}
	p=const_start;	
	while(p!=NULL){
		printf("%s %d\n",p->s,p->time);
		p=p->next;
	}
	fclose(in);
	return 0;
}
void deal(char *s_now,int len){//分行处理字符串s 
	char word_bef_sto[15]={'0'};

	for(int i=0;i<len;i++){

		if(!isalpha(s_now[i])){
			continue;
		}
		int j=0;
		while(isalpha(s_now[i])){//读一个单词 
			word_bef_sto[j]=isupper(s_now[i])?_tolower(s_now[i]):s_now[i];
			i++;j++;
		}
//		printf("word is here!%s\n",word_bef_sto);
		struct w *q=const_start;//从链表的第一个单词开始查有没有被存储过 
		if(flag==0){
			strcpy(q->s,word_bef_sto);
			q->next=NULL;
			q->time=1;
			flag=1;
			continue;
		}
		while(q!=NULL){
			if(strcmp(q->s,word_bef_sto)<0){
				if(q->next==NULL){
					struct w *tem=(struct w*)malloc(sizeof(struct w));
					strcpy(tem->s,word_bef_sto);
					tem->time=1;
					tem->next=NULL;
					q->next=tem;
//					printf("upgrate:%s %d\n",tem->s,tem->time);
					break;
				}
				else if(strcmp(q->next->s,word_bef_sto)<0){
					q=q->next;
				}
				else if(strcmp(q->next->s,word_bef_sto)>0){
					struct w *tem=(struct w*)malloc(sizeof(struct w));
					strcpy(tem->s,word_bef_sto);
					tem->time=1;
					tem->next=q->next;
					q->next=tem;
//					printf("upgrate:%s %d\n",tem->s,tem->time);
					break;
				}
				else if(strcmp(q->next->s,word_bef_sto)==0){
					q->next->time++;
//					printf("upgrate:%s %d\n",q->next->s,q->next->time);
					break;
				}
			}
			else if(strcmp(q->s,word_bef_sto)>0){
				struct w *tem=(struct w*)malloc(sizeof(struct w));
				strcpy(tem->s,word_bef_sto);
				tem->time=1;
				tem->next=const_start;
				const_start=tem;
//				printf("upgrate:%s %d\n",tem->s,tem->time);
				break;
			}
			else if(strcmp(q->s,word_bef_sto)==0){
				q->time++;
//				printf("upgrate:%s %d\n",q->s,q->time);
				break;
			}
		}
//		printf("%s\n",word_bef_sto);
		memset(word_bef_sto,0,sizeof(word_bef_sto));
	}
}

