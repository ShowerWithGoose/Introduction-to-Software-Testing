#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct math{
	int coef;
	int index;
	struct math* link;
};

struct math* Read();//读入多项式并用链表储存系数和指数 
void insert(int,int,struct math**);//在链表末尾插入一个新元素 
struct math* multi(struct math* t1,struct math* t2);//计算两个多项式乘积
 
int main(){
	struct math* t1,*t2,*t;
	t1=Read();
	t2=Read();
	t=multi(t1,t2); 
	for(t=t->link;t!=NULL;t=t->link){
		printf("%d %d ",t->coef,t->index);
	}
	return 0;
} 
struct math* Read(){
	int co,in;
	struct math *p1,*last,*t;
	p1=(struct math*)malloc(sizeof(struct math));
	p1->link=NULL; 
	last=p1;
	char c='\0';
	while(c!='\n'){
		scanf("%d%d",&co,&in);
		c=getchar();
		insert(co,in,&last);
	}
	t=p1;
	p1=p1->link;
	free(t);
	return p1;
}

void insert(int co,int in,struct math** last){
	struct math *p;
	p=(struct math*)malloc(sizeof(struct math));
	p->coef=co;
	p->index=in;
	p->link=(*last)->link;
	(*last)->link=p;
	*last=p;
}

struct math* multi(struct math* t1,struct math* t2){
	struct math* q1,*q2,*last,*q0,*q;
	int co,in;
	q1=t1;
	q2=t2; 
	q=(struct math*)malloc(sizeof(struct math)); 
	q->link=NULL;
	last=q;
	q0=q;
	for(;q2!=NULL;q2=q2->link){
		co=(q1->coef)*(q2->coef);
		in=q1->index+q2->index;
		insert(co,in,&last);
	}
	for(q1=q1->link;q1!=NULL;q1=q1->link){
		for(q2=t2;q2!=NULL;q2=q2->link){
			co=(q1->coef)*(q2->coef);
			in=q1->index+q2->index;
			for(last=q;last!=NULL;last=last->link){
				q0=last->link;
				if(in<last->index&&last->link==NULL){
					insert(co,in,&last);
				}
				if(q0==NULL){
					break;
				}
				if(in>(q0->index)&&last==q){
					insert(co,in,&last);
				}
				if(in==q0->index){
					q0->coef=q0->coef+co;
				}
				if(in<last->index&&in>q0->index){
					insert(co,in,&last);
				}	
			}
		}
	}
	return q;
}

