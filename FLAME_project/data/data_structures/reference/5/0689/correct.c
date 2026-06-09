#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PolyNode * Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
};
void Attach(int c, int e, Polynomial * rear);//将新读入的系数和指数加到多项式的末尾 
Polynomial ReadPoly();//读入多项式 
Polynomial MultyPoly(Polynomial P1, Polynomial P2);//计算两个多项式积 
void PrintPoly(Polynomial P);
int main()
{
	Polynomial P1 = ReadPoly();
	Polynomial P2 = ReadPoly();
	Polynomial PP = MultyPoly(P1, P2);
	PrintPoly(PP);
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
	int c,e;//用来暂存系数和指数 
	P1 = (Polynomial)malloc(sizeof(struct PolyNode));//申请头节点 
	//申请头节点是为了方便使用Attach函数时，不用区分rear是空还是非空，有了头节点都是非空，插入方便 
	P1->link = NULL;
	
	rear = P1;//尾指针指向头节点
	char chara;
	while(scanf("%d%d%c",&c,&e,&chara)) 
	{
		Attach(c, e, &rear);
		if(chara=='\n')
		break;
	}
	t = P1; 
	P1 = P1->link;
	free(t);//头节点方便插入的使命完成，释放头节点
	return P1; 
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
}

