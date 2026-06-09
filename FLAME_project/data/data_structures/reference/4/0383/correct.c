#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	char *s;
	int cnt;
	int fkh;
	struct node *nxt;
	struct node *lst;
}node;
void vtol(char *s){
	if(*s>='A'&&*s<='Z')*s=*s-'A'+'a';
}
void addn(node *p,char *s){
	node *tmp=(node *)malloc(sizeof(node));
	tmp->s=s;tmp->cnt=1;
	tmp->lst=p;
	p->nxt=tmp;
	tmp->nxt=0;
}
void addhl(node **head,char *s){
	node *tmp=(node *)malloc(sizeof(node));
	tmp->s=s;tmp->cnt=1;
	tmp->nxt=*head;
	(*head)->lst=tmp;
	*head=tmp;
	(*head)->lst=0;
}
void addl(node *p,char *s){
	node *tmp=(node *)malloc(sizeof(node));
	tmp->s=s;tmp->cnt=1;
	tmp->nxt=p;
	tmp->lst=p->lst;
	p->lst->nxt=tmp;
	p->lst=tmp; 
}
void print_link(node *head){
	while(head){
		if(head->s[0])printf("%s %d\n",head->s,head->cnt);
		head=head->nxt;
	}
}
void free_link(node *head){
	node *lst=head;
	while(head->nxt){head=head->nxt;free(lst);lst=head;}
}
int main(){
	node *head=(node *)malloc(sizeof(node));
	head->fkh=0;
	head->lst=0;
	head->nxt=0;
	head->cnt=1;
	char *s=(char *)malloc(10000);
	freopen("article.txt","r",stdin);
	while(gets(s)){
		int i=0,j=0;
		while(s[i]){vtol(&s[i]);i++;}
		i=0;
		while(s[i]){
			char *stmp=(char *)malloc(100);
			while(s[i]>='a'&&s[i]<='z'){
				stmp[j++]=s[i++];
			}
			stmp[j]=0;
			if(stmp[0]){
				if(!head->nxt&&!head->fkh){head->s=stmp;head->fkh++;}
				else if(strcmp(stmp,head->s)<0)addhl(&head,stmp);
				else if(strcmp(stmp,head->s)==0)head->cnt++;
				else{
					node *tmp=head;
					int flag=0;
					while(1){
						if(strcmp(stmp,tmp->s)<0){addl(tmp,stmp);flag++;break;}
						if(strcmp(stmp,tmp->s)==0){tmp->cnt++;flag++;break;}
						if(!tmp->nxt)break;
						tmp=tmp->nxt;
					}
					if(!flag)addn(tmp,stmp);
				}
			}
			j=0;
			if(!s[i])break;
			i++;
		}
	}
	print_link(head);
	//free_link(head);
	fclose(stdin);
	return 0;
} 

