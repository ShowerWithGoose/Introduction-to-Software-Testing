#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int coef;
	int exp;
	struct node *link;
}PNode,*PLinkList;

PLinkList read()
{
	int a,n;
	char c;
	PLinkList p,head,q,r;
	head=p=NULL;
	do{
		scanf("%d%d%c",&a,&n,&c);
		q=(PLinkList)malloc(sizeof(PNode));
		q->coef=a;
		q->exp=n;
		q->link=NULL;
		if(head==NULL)
		head=p=q;
		else
		{
			p->link=q;
			p=p->link;
		}
	}
	while(c!='\n');
	return head;
}

PLinkList attach(int co,int ex,PLinkList r)
{
	PLinkList w;
	w=(PLinkList)malloc(sizeof(PNode));
	w->exp=ex;
	w->coef=co;
	r->link=w;
	return w;
}

PLinkList Pmulti(PLinkList A,PLinkList B)
{
	PLinkList C;
	PLinkList r,p=A,q=B,head,hold;
	int x,ex,co;
	C=(PLinkList)malloc(sizeof(PNode));
	C->link=NULL;
	r=C;
	while(q)
	{
		co=p->coef*q->coef;
		ex=p->exp+q->exp;
		r=attach(co,ex,r);
		q=q->link;
	}
	p=p->link;
	while(p)
	{
		q=B;
		r=C;
		while(q)
		{
			co=p->coef*q->coef;
		    ex=p->exp+q->exp;
		    while(r->link&&r->link->exp>ex)
		    r=r->link;
		    if(r->link&&r->link->exp==ex)
		    {
		    	if(r->link->coef+co)
		    	{
		    		r->link->coef=r->link->coef+co;
		    	    r=r->link;
				}
		    	else
		    	{
		    		hold=r->link;
		    		r->link=hold->link;
		    		free(hold);
				}
			}
			else
			{
				hold=(PLinkList)malloc(sizeof(PNode));
				hold->coef=co;
				hold->exp=ex;
				hold->link=r->link;
				r->link=hold;
				r=r->link;
			}
			q=q->link;
		}
		p=p->link;
	}
	hold=C;
	C=C->link;
	free(hold);
	return C;
}
int main()
{
	PLinkList p1,p2,r;
	p1=read();
	p2=read();
	r=Pmulti(p1,p2);
	while(r)
	{
		printf("%d %d ",r->coef,r->exp);
		r=r->link;
	}
	return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
 
typedef struct PolyNode * Polynomial;
 
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
};
 
void Attach(int c, int e, Polynomial * rear);//将新读入的系数和指数加到多项式的末尾 
 
Polynomial ReadPoly();//读入多项式 
 
Polynomial AddPoly(Polynomial P1, Polynomial P2);//计算两个多项式之和 
 
Polynomial MultyPoly(Polynomial P1, Polynomial P2);//计算两个多项式积 
 
void PrintPoly(Polynomial P);
 
int main()
 
{
	Polynomial P1 = ReadPoly();
	Polynomial P2 = ReadPoly();
	Polynomial PA = AddPoly(P1, P2);
	Polynomial PP = MultyPoly(P1, P2);
	PrintPoly(PP);
	PrintPoly(PA);
}
 
void Attach(int c, int e, Polynomial * rear)
{
	Polynomial input = (Polynomial)malloc(sizeof(struct PolyNode));
	//申请新节点并赋初值 
	input->coef = c;
	input->expon = e;
	input->link = NULL;
	(*rear)->link = input;
	*rear = input; //修改末尾指针，因为是修改指针，故此处使用指针的指针 
}
 
Polynomial ReadPoly()
{
	Polynomial P1, rear, t;
	int N;//多项式项数 
	int c,e;//用来暂存系数和指数 
	P1 = (Polynomial)malloc(sizeof(struct PolyNode));//申请头节点 
	//申请头节点是为了方便使用Attach函数时，不用区分rear是空还是非空，有了头节点都是非空，插入方便 
	P1->link = NULL;
	rear = P1;//尾指针指向头节点 
 
	scanf("%d",&N);
	while(N--) 
	{
		scanf("%d %d",&c, &e);
		Attach(c, e, &rear);
	}
	t = P1; 
	P1 = P1->link;
	free(t);//头节点方便插入的使命完成，释放头节点
	return P1; 
}
 
Polynomial AddPoly(Polynomial P1, Polynomial P2)
{
	Polynomial t1,t2,rear,t;
	t1 = P1;
	t2 = P2;
	Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	rear = P;
	while(t1 && t2)
	{
		if(t1->expon == t2->expon)//如果指数相同则进行相加 
		{
			if(t1->coef + t2->coef)//如果系数相加不为零，则将计算结果加入P中 
			{
				Attach(t1->coef + t2->coef, t1->expon, &rear);
			}
			t1 = t1->link;
			t2 = t2->link;
		}
		else if(t1->expon > t2->expon)//找到指数大的加入到P中 
		{
			Attach(t1->coef, t1->expon, &rear);
			t1 = t1->link;
		}
		else
		{
			Attach(t2->coef, t2->expon, &rear);
			t2 = t2->link;
		}
	}
	while(t1)//如果t1还有多余节点，则继续加入 
	{
		Attach(t1->coef, t1->expon, &rear);
		t1 = t1->link;
	}
	while(t2)//如果t2还有多余节点，则继续加入 
	{
		Attach(t2->coef, t2->expon, &rear);
		t2 = t2->link;
	}
	t = P;
	P = P->link;
	free(t);//释放头节点 
	return P;
}
 
Polynomial MultyPoly(Polynomial P1, Polynomial P2)
{
	Polynomial P, t1, t2, t, rear;
	int c, e;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	
	t1 = P1;
	t2 = P2;
	rear = P;
	
	if(!t1 || !t2)//如果有一个多项式为空，则乘法结果为空 
		return NULL;
 
	while(t2)//先用P1的第一项乘以P2生成一个多项式用于插入 
	{
		c = t1->coef * t2->coef;
		e = t1->expon + t2->expon;
		Attach(c, e, &rear);
		t2 = t2->link;
	}
	t1 = t1->link;//t1指向第二项 
	while(t1)
	{
		t2 = P2;//将指针重新指向P2的开头 
		rear = P;//用作寻找合适的插入位置 
		while(t2)
		{
			c = t1->coef * t2->coef;
			e = t1->expon + t2->expon;
			while(rear->link && rear->link->expon > e)//将rear指向指数与e相等或比e小的节点之前一个位置	
				rear = rear->link;
			if(rear->link && rear->link->expon == e)//如果rear不为空且rear之后的节点指数和e相等，则进行相加 
			{
				if(c + rear->link->coef)//如果相加不为0
				{
					rear->link->coef += c;	
					rear = rear->link;
				} 
				else//相加结果为0 ,删除rear之后的节点 
				{
					t = rear->link;
					rear->link = t->link;
					free(t);
				}
			}
			else //构造一个新节点插入到rear之后 
			{
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expon = e;
				t->link = rear->link;
				rear->link = t;
				rear = rear->link;
			}
			t2 = t2->link;
		} 
		t1 = t1->link;
	}
	t = P; 
	P = P->link;
	free(t);//释放掉头节点
	return P; 
} 
 
void PrintPoly(Polynomial P)
{
	int flag = 0;
	if(!P)
	{
		printf("0 0\n");
		return;
	}
	while(P)
	{
		if(!flag)
			flag = 1;
		else
			printf(" ");
		printf("%d %d",P->coef, P->expon);
		P = P->link;		
	}
	printf("\n");
}*/
 

