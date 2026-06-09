#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct Node {
	int coe;
	int pow;
	struct Node *next;

};
struct Node* creatlist(){
	struct Node *p,*q,*first=NULL;
	int a,n;
	char c=' ';
	while(c!='\n'){
	scanf("%d%d%c",&a,&n,&c);


	q=(struct Node*)malloc(sizeof(struct Node));
	q->coe=a;  q->pow=n; q->next=NULL;
	if(first==NULL){
		first=p=q;
	}
	else{
		p->next=q;
		p=p->next;
	}
};
return first;
}

struct Node* multi(struct Node* first1,struct Node* first2){
	struct Node* ansfir=NULL;
		struct Node* q=NULL;
			struct Node* p=NULL;
				struct Node* q0=NULL;
					struct Node* p0=NULL;
	for(p=first1;p!=NULL;p=p->next){
		for(q=first2;q!=NULL;q=q->next){
			q0=(struct Node*)malloc(sizeof(struct Node));
			q0->coe=q->coe*p->coe;
			q0->pow=q->pow+p->pow;
			if(ansfir==NULL){
				ansfir=p0=q0;
			}
			else{
				p0->next=q0;
				p0=p0->next;
			}
		}
	}
	p0->next=NULL;
	
		for(p=ansfir;p!=NULL;p=p->next){
		struct Node* r1=p;
		struct Node* r2=NULL;
		for(r2=p->next;r2!=NULL;r2=r2->next){
			if(r2->pow==p->pow){
				p->coe+=r2->coe;
				r1->next=r2->next;
				free(r2);
				r2=r1->next;
			}
			r1=r2;
		}
	}
	return ansfir;
}


void sort(struct Node* ansfir){
	int temp1,temp2;
	struct Node *r, *tail;
	r = ansfir;
	tail = NULL;
	if (r == NULL||r->next == NULL)
	{
		return;
	}
	while (r!=tail)
	{
		while (r->next!= tail)
		{
			if (r->pow<r->next->pow)
			{
				temp1=r->pow;
				r->pow=r->next->pow;
				r->next->pow = temp1;
				temp2=r->coe;
				r->coe=r->next->coe;
				r->next->coe = temp2;
			}
			r = r->next;
		}
		tail=r;
		r=ansfir;
	}
	return;
}

int main(){

struct Node *first1,*first2,*ansfir,*p;

first1=creatlist();
first2=creatlist();
ansfir=multi(first1,first2);
sort(ansfir);

for(p=ansfir;p!=NULL;p=p->next){

printf("%d %d ",p->coe,p->pow);

}
}




