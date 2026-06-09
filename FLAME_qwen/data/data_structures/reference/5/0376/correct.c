#include<stdio.h>
#include<stdlib.h>
char a[999999];
char b[999999];

typedef struct mylist{
	int data;
	int mici;
	struct mylist *next;
}list,*qlist;


int main(void)
{
	qlist s1=NULL,s2=NULL,sall=NULL,temp=NULL,p=NULL,q=NULL,dot=NULL;
	int m,n;
	int i;
	int f=0;
	p = s1 = (qlist)malloc(sizeof(list));
	q = s2 = (qlist)malloc(sizeof(list));
	
	gets(a);
	for(i=0;a[i]!='\0';i++){
		sscanf(&a[i],"%d %d",&m,&n);
		temp = (qlist)malloc(sizeof(list));
		temp->data = m;
		temp->mici = n;
		p->next =temp;
		p = temp;
		p->next = NULL;
		while(a[i]!=' ') i++;
		i++;
		while(a[i]!=' '&&a[i]!='\0') i++;
	}
	
	gets(b);
	for(i=0;b[i]!='\0';i++){
		sscanf(&b[i],"%d %d",&m,&n);
		temp = (qlist)malloc(sizeof(list));
		temp->data = m;
		temp->mici = n;
		q->next =temp;
		q = temp;
		q->next = NULL;
		while(b[i]!=' ') i++;
		i++;
		while(b[i]!=' '&&b[i]!='\0') i++;
	}
	
	p = sall = (qlist)malloc(sizeof(list));
	p->next = NULL;
	dot = s1;
	
	while(s1->next != NULL){
		s1 = s1->next;
		q=s2;
		while(q->next!=NULL){
			q=q->next;
			temp = (qlist)malloc(sizeof(list));
			temp->data = (s1->data) * (q->data);
			temp->mici = s1->mici + q->mici;
			temp->next = NULL;
			p = sall;
			f=0;
			while(p->next != NULL){
				if((p->next)->mici == temp->mici) {
					(p->next)->data += temp->data;
					f=1;
					free(temp);break;
				}
				if((p->next)->mici < temp->mici){
					temp->next = p->next;
					f=1;
					p->next = temp;break;
				}
				p=p->next;
			}
			if(f==0) p->next = temp;
		}
	}
	free(dot);
	free(s2);
	for(p=sall;p!=NULL;p=p->next){
		if(p!=sall) printf("%d %d ",p->data, p->mici);
	}
	free(sall);
	return 0;
}

