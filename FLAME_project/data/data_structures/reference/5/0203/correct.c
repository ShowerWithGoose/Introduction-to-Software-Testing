#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int coef;
	int exp;
	struct node *link;
}Node,*Linklist;


Linklist ATTACH(int a,int n,Linklist r){//传入的是：系数 指数 指向当前积链表尾部的指针 
	Linklist w;
	w=(Linklist)malloc(sizeof(Node));
	w->coef=a;
	w->exp=n;
	w->link=NULL;
	r->link=w;
	return w;//返回的是当前链表最后结点的位置 
}
Linklist Getsta()
{
	Linklist L,r,t;
	int c,e,flag=1;
	char tmp; 
	L=(Linklist)malloc(sizeof(Node));
	L->link=NULL;
	r=L;
	while(flag){
		scanf("%d %d%c",&c,&e,&tmp);
		if(tmp=='\n') flag=0;
		r=ATTACH(c,e,r);
	}
	t=L;
	L=L->link;
	free(t);
	return L;
}
 
Linklist MUL(Linklist A,Linklist B){//对AB链表进行乘法生成新的积链表C 
	Linklist C;
	Linklist r,t,p=A,q=B;
	int c,e;
	C=(Linklist)malloc(sizeof(Node));
	C->link=NULL;
	r=C;
	
	while(q!=NULL){
		r=ATTACH(p->coef * q->coef,p->exp + q->exp,r);
		q=q->link;
	}//A链第一项与B链所有项相乘 
	p=p->link;
	while(p!=NULL){
		q=B;
		r=C;
		while(q!=NULL){
			c=p->coef * q->coef;
			e=p->exp + q->exp;//新项的系数指数 往哪儿插 
			while(r->link!=NULL&&r->link->exp>e)
			r=r->link;//按降幂排列 一直退到指数刚好不小于待插入项的指数 
			if(r->link!=NULL&&r->link->exp==e){//如果有恰好相等的 合并同类项 
				if(r->link->coef+c!=0)//系数不为零 
				r->link->coef+=c;
			else{//系数为零 删项 
				t=r->link;
				r->link=t->link;
				free(t);
			}
			}
			else{//没有指数相等的  插入一个全新的项 
				t=(Linklist)malloc(sizeof(Node));
				t->coef=c;t->exp=e;
				t->link=r->link;
				r->link=t;
				r=r->link;
			}
			q=q->link;
		}
		p=p->link;
	}
		q=C;
		C=C->link;
		free(q);
		return C;
}
int main(){
	Linklist A,B,C;
	A=Getsta();
	B=Getsta();
	C=MUL(A,B);
	while(C){
		printf("%d %d ",C->coef,C->exp);
		C=C->link;
	}
	return 0;
}


