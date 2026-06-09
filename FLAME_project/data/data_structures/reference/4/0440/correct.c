#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct Word{
	char data[50];
	int num;
	struct Word *next;
};
typedef struct Word word;
typedef struct Word *wordptr;

wordptr end,judge;

int j;
wordptr search(wordptr p,wordptr head){
	wordptr i;
	i = head;
	for(i=head;(i->next)!=NULL;i=i->next){
		if(strcmp(i->next->data,p->data)>0){//i>.next对应的数据字典序小于p对应的
			return i;
		}else if(strcmp(i->next->data,p->data)==0){
			i->next->num++;
			return end;
		}
	}
	return NULL;
}

void insert(wordptr p,wordptr head){
	wordptr pr;
	pr=search(p,head);
	if(pr==NULL){
		p->num=1;
		end->next=p;
		end=p;
		end->next=NULL;
	}else if(pr==end){
		return ;
	}else{
		p->num=1;
		p->next=pr->next;
		pr->next=p;
	}
	return ;
}
int main(){
	
 	char s[10005]={0},str[50];
	FILE *in;
	in=fopen("article.txt","r");
	int i=0,flag=1;
	while(!feof(in)){
		s[i++]=fgetc(in);
	}	
	s[i-1]='\0';
//	printf("%s",s); 
	wordptr head,p;
	for(i=0;i<strlen(s);i++){
		
		while(!isalpha(s[i])&&i<strlen(s))i++;
		if(s[i]==0) break;
		for(j=0;isalpha(s[i+j]);j++){
			
			str[j]=tolower(s[i+j]);	
		}
		//printf("%s\n",str);
		//在这里构建链表。
		if(flag){
			//构建链表
			head=(wordptr)malloc(sizeof(word));
			end=(wordptr)malloc(sizeof(word));
			head->next=end;
			end->next=NULL;
			p=end;
			p->num=1;
			strcpy(p->data,str);
			memset(str,0,sizeof(str));
		}else{
			//插入数据
			p=(wordptr)malloc(sizeof(word));
			strcpy(p->data,str);
			insert(p,head);
			memset(str,0,sizeof(str));
		}
		i=i+j;
		flag=0;
	}
	wordptr q;
	for(q=head;q->next!=NULL;q=q->next){
		printf("%s %d\n",q->next->data,q->next->num);
	}
	fclose(in);
	return 0;
}

