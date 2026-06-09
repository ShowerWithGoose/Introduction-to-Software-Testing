#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> 
typedef struct Node {
	char s[1000];
	int num;
    struct Node *next;
}*listnode; 
listnode init(){
	listnode q=(listnode)malloc(sizeof(struct Node));
	q->next=NULL;
	return q;
}
void insert_qian(listnode head,char a[1000],int n){
	listnode q=(listnode)malloc(sizeof(struct Node));
	strcpy(q->s,a);q->num=n;
	q->next=head->next;
	head->next=q;
}
void insert_hou(listnode head,char a[1000],int n){
	listnode q=(listnode)malloc(sizeof(struct Node));
	strcpy(q->s,a);q->num=n;
	listnode p;
	p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=q;
	q->next=NULL;
}
void fun(listnode head){
	listnode p,q;char temp[1000];
	p=head->next;
	while(p){
		q=p->next;
		while(q){
			if(strcmp(p->s,q->s)>0){
				strcpy(temp,p->s);strcpy(p->s,q->s);strcpy(q->s,temp);
			}
			q=q->next;
		}
		p=p->next;
	}
}
void add(listnode head){
	listnode p,q;
	p=head->next;
	do{
		q=p->next;
		if(strcmp(p->s,q->s)==0){
			p->num++;
			p->next=q->next;
		}else{
			p=p->next;
		}
		
	}while(q->next!=NULL);
}
void print(listnode head){
	listnode q=head->next;
	while (q!=NULL){
		printf("%s %d\n",q->s,q->num);
		q=q->next;
	}
}
int isNull(char c){
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
    	return 0;
	}
	return 1;
}
int getWord(FILE *fp,char *str){
    int c;
    int counter = 0;
    while((c = fgetc(fp)) != EOF){
        if( isNull(c) && (counter <= 0)){
            continue;
        }else if(isNull(c) && (counter > 0)){
            break;
        }
        str[counter++] = tolower(c);
    }
    str[counter] = '\0';
    if(counter > 0)
        return 1;
    else 
        return 0;
}
int main(){
	FILE *in;
    in=fopen("article.txt","r");
    listnode head=init();
    char s1[1000];
    int cnt=1,shu=0;
    while(getWord(in,s1)!=0){

    	insert_hou(head,s1,cnt);
	}
	fun(head);
	add(head);
    print(head);
	fclose(in);
	return 0;
}

