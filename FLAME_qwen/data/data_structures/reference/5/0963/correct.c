#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct multi{
	int an;
	int n;
	struct multi *next;
}linklist;
void hebing(linklist *t){
	linklist *q=t->next;
	t->an =t->an+t->next->an;
	t->next=t->next->next;
	free(q);
}
int main(){
	linklist *head,*end,*node,*t,*in;
	head=(linklist*)malloc(sizeof(linklist));
	end=head;
	char p;
	int cnt=0,an1,n1,i,cnt1=0;
	scanf("%d%d",&head->an,&head->n);
	scanf("%c",&p);
	while(p==' '){
		node=(linklist*)malloc(sizeof(linklist));
		scanf("%d%d",&node->an,&node->n);
		scanf("%c",&p);
		end->next=node;
		end=node;
		cnt++;
		}
		t=head;
		in=head;
	do{
		scanf("%d%d%c",&an1,&n1,&p);
		for(i=0;i<=cnt;i++){
			node=(linklist*)malloc(sizeof(linklist));
			node->an =an1*t->an;
			node->n=n1+t->n;
			end->next=node;
			end=node;
			t=t->next;
			cnt1++;
		}
		t=head;
	}while(p==' ');
	end->next=NULL;
	for(i=0;i<=cnt;i++){
		in=in->next;
	}
	head=in;
	in=NULL;
	t=head;
	while(t!=in){
		while(t->next!=in){
			if(t->n<=t->next->n){
				int temp=t->an;
				t->an=t->next->an;
				t->next->an=temp;
				temp=t->n;
				t->n=t->next->n;
				t->next->n=temp;
			}
			t=t->next;
		}
		in=t;
		t=head;
	}
	t=head;
	while(t->next!=NULL){
		while(t->n==t->next->n)
		hebing(t);
		t=t->next;
	}
	t=head;
	while(t!=NULL){
		printf("%d %d ",t->an,t->n);
		t=t->next;
	}
	return 0;
}


