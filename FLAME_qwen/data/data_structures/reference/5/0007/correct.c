#include<stdio.h> 
#include<math.h>
#include<stdlib.h> 
#include<string.h> 
#include<stdbool.h> /*10 80000 2 6000 7 300 5 10 18 0
3 6000 5 20 8 10 6 0*/
struct NODE{
long long	int  num;
long long	int  power;
	struct NODE *next;	
};
typedef struct NODE node; 	
typedef struct NODE* nodep;
void node_sort(nodep L);
void merge(nodep L,int count);
int main(){ 
	int i,j;
int n=0,flag1=1,flag2=1;
nodep head1=NULL,head2=NULL,p,q;
head1=(struct NODE*)malloc(sizeof(struct NODE));
head2=(struct NODE*)malloc(sizeof(struct NODE));
p=head1;
for(i=0;i<300;i++){
	scanf("%d %d",&p->num,&p->power);
	p->next=(struct NODE*)malloc(sizeof(struct NODE));
	p=p->next;
	if(getchar()=='\n'){
		p->next=NULL;
		break;
	}
	flag1++;
}
p=head1;

p=head2;
for(i=0;i<300;i++){
	scanf("%d %d",&p->num,&p->power);
	p->next=(struct NODE*)malloc(sizeof(struct NODE));
	p=p->next;
	if(getchar()=='\n'){
		p->next=NULL;
		break;
	}
	flag2++;
}
nodep head_ans,t=NULL;
p=NULL;
head_ans=(struct NODE*)malloc(sizeof(struct NODE));
for(i=0;i<flag1;i++){// 外循环遍历前面多项式 
if(p==NULL){//p空就去头否则就后移 
	p=head1;
	}else{
	p=p->next;
}	
q=head2;	
	for(j=0;j<flag2;j++){//内循环遍历后面多项式 
	   n++;
	   if(t==NULL){
	   	t=head_ans;
	   }else{
	   	t->next=(struct NODE*)malloc(sizeof(struct NODE));
	   	t=t->next;
	   }
	   t->num=p->num*q->num;
	   t->power=p->power+q->power;
	   q=q->next;

	}
	q=head2;
}
node_sort(head_ans);
int len=flag1*flag2;
merge(head_ans,len);
t=head_ans;
while(t->next!=NULL){
printf("%d %d ",t->num,t->power);
	t=t->next;
}
printf("%d %d",t->num,t->power);
return 0;
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
			if (p->power < p->next->power)
			{
				int temp = p->power;
				p->power = p->next->power;
				p->next->power= temp;
				    temp = p->num;
				p->num = p->next->num;
				p->next->num = temp;
			}
			p = p->next;
		}
		tail = p;
		p = head;
	}
}
void merge(nodep head,int count){
	int i,j;	
	nodep p=head,q=NULL,t=NULL;
	if (p == NULL || p->next == NULL)
	{
		return;
	}	
while(p!=NULL){
	q=p->next;
   while(q!=NULL){
   	if(q->power==p->power){
   		p->num+=q->num;
   		p->next=q->next;
   		t=q;
   		free(t);
	   }
	q=q->next;
   }
   p=p->next;
}
	
}

