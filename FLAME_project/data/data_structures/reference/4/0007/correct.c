#include<stdio.h> 
#include<math.h>
#include<stdlib.h> 
#include<string.h> 
#include<stdbool.h> 
#include<ctype.h>
struct Node{
	char word[60];
	int times;
	struct Node* next;
};
typedef struct Node node;
typedef struct Node* nodep;
struct Node* word_list(FILE *);
void node_sort(nodep head);
void merge(node *head);
int main(){ 
FILE *in;
in=fopen("article.txt","r");
int i;
nodep p,head;
head=word_list(in);
node_sort(head);
merge(head);
p=head->next;
while(p!=NULL){
for(i=0;i<strlen(p->word);i++){
	printf("%c",p->word[i]);
};
printf(" %d\n",p->times);
	p=p->next;
}
fclose(in);
return 0;
}



struct Node* word_list(FILE *in){
	
char ch,s[60];
int i,j;
bool flag=0;
nodep p,head;
head=(nodep)malloc(sizeof(node));
p=head;
i=0;
ch=fgetc(in);
while(ch!=EOF){
	if(ch<='Z'&&ch>='A'){
	s[i]=tolower(ch);
	i++;
	flag=1;
	}else if(ch<='z'&&ch>='a'){
	s[i]=ch;
	i++;
	flag=1;
	}else{
		if(flag==1){
			p->next=(nodep)malloc(sizeof(node));//头结点无数据; 
			p=p->next;
			p->times=1;
			memset(p->word,0,sizeof(p->word));
			for(j=0;j<strlen(s);j++){
				p->word[j]=s[j];
			}
			//strcpy(p->word,s);
			memset(s,0,sizeof(s));
			i=0;
			flag=0;
		}
	}
	ch=fgetc(in);	
}
p->next=NULL;	
return head;	
}
void node_sort(nodep head){
	node *p, *tail;
	p = head;
	tail = NULL;
	if (p == NULL || p->next == NULL)
	{
		return;
	}
	while (p != tail)
	{
		while (p->next != tail)
		{
			if (strcmp(p->word,p->next->word)>0)
			{
				char temp[60]={0};
				 strcpy(temp,p->word);
				 memset(p->word,0,sizeof(p->word));
				 strcpy(p->word,p->next->word);
				 memset(p->next->word,0,sizeof(p->next->word));
		         temp;strcpy(p->next->word,temp);
		        
			}
			p = p->next;
		}
		tail = p;
		p = head;
	}
}

void merge(node *head){
	node *p=NULL,*q=NULL;
	p=head;
	while(p->next !=NULL){
		p=p->next;
		q=p->next;
		while(q!=NULL){
			
			if(strcmp(q->word,p->word)==0){
				p->times++;
				p->next=q->next;
				free(q);	
			}else{
				break;
			}		
			q=p->next;
		}
	}
	
	
}

