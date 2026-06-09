#include <stdio.h>
#include <stdlib.h>
 
typedef struct Polynode
{
	int coef;
	int exp;
	struct Polynode *next;
}Polynode, *Polylist;
 
// 初始化多项式
Polylist InitPoly(Polylist *Poly) // 二级指针
{
	*Poly = (Polylist)malloc(sizeof(Polynode));  //产生头结点，并使L指向此头节点
	if (!(*Poly))   // 存储分配失败
		return 0;
	(*Poly)->next = NULL;
	return *Poly;
}
 
// 外插法建立一元多项式单链表,n代表多项式非零系数的个数
void PolyCreate(Polylist head)
{
	Polynode *rear, *s;  //rear为尾指针，s为新结点指针
	int c, e;
	char d;
	rear = head;
	do{
		scanf("%d%d%c",&c,&e,&d);
		s = (Polynode*)malloc(sizeof(Polynode));
		s->coef = c;
		s->exp = e;
		rear->next = s;  // 当前结点作为表尾插入
		rear = s;        //  插入的结点作为新的尾节点		
	}while(d != '\n');
	rear->next = NULL;   // 将表尾的最后一个结点置为空
	
}
 
// 多项式相加
void Polyadd(Polylist polya, Polylist polyb)
{
 
	Polynode *p, *q, *pre, *temp;
	int sum;
	p = polya->next; // p指向polya第一个结点
	q = polyb->next; // q指向polyb第一个结点
	pre = polya;     // pre表示和多项式的尾节点,初始与polya相同
	while (p != NULL && q != NULL)
	{
		if (p->exp > q->exp)  // a的结点加入和多项式
		{
			pre->next = p;   // p所指的结点加入和多项式
			pre = p;         // pre向后移动，尾插
			p = p->next;     // 扫描下一个p
		}
		else if (p->exp == q->exp)  // 系数相等，对应系数相加
		{
			sum = p->coef + q->coef;
			if (sum != 0)
			{
				p->coef = sum;   // 修改p
				pre->next = p;   // 将p加入表尾
				pre = p;
				p = p->next;     // p向后移动
				temp = q;
				q = q->next;
				free(temp);      // 释放系数相同的q结点
 
			}
			else
			{
				// 系数相同情况
				temp = p;
				p = p->next;
				free(temp); // 释放原来p指针
				temp = q;
				q = q->next;
				free(temp);
			}
		}
		else
		{
			pre->next = q;  //将q加入到和多项式尾部
			pre = q;        // 将pre移动到q
			q = q->next;
		}	
	}
	if (p != NULL)
		pre->next = p; // 将p剩余结点加入到和多项式
	else
		pre->next = q;
	
}
 
// 在尾部插入一个节点
void Attach(int c, int e, Polylist* pRear)
{
	Polynode *P;
    P = (Polynode*)malloc(sizeof(Polynode));
	P->coef = c;
	P->exp = e;
	P->next = NULL;
	(*pRear)->next = P;
	*pRear = P;
}
 
void clearPoly(Polylist poly)
{
	Polynode* pTemp = poly;
	while (poly)
	{
		pTemp = poly;
		// 向后移动一个
		poly = poly->next;
		free(pTemp);
	}
}
 
void PrintPoly(Polylist poly)
{
	Polynode *p;
	p = poly->next;
	if (!p)
	{
		printf("0 0\n");
		return;
	}
	printf("%d", p->coef);
	printf(" %d", p->exp);
	p = p->next;
	while (p != NULL)
	{
		printf(" %d", p->coef);
		printf(" %d", p->exp);
		p = p->next;
	}
	printf("\n");
}
 
Polylist PolyMult(Polylist polya, Polylist polyb)
{
	Polylist polyc;
	Polynode *p, *q, *temp, *Rear;
	int coef, exp;
	InitPoly(&polyc);
	Rear = polyc;
	p = polya->next; // p指向polya第一个结点
	q = polyb->next; // q指向polyb第一个结点
	if (!p||!q)
	{
		return polyc;
	}
	q = polyb->next;
	// 先用polya的第一项与polyb相乘
	while (q)
	{
		Polynode *P;
		P = (Polynode*)malloc(sizeof(Polynode));
		P->coef = p->coef*q->coef;
		P->exp = p->exp+q->exp;
		P->next = NULL;
		Rear->next = P;
		Rear = P;
		q = q->next;
	}
	p = p->next;
	// 下面依次将元素插入到polyc中
	while (p)
	{
		q = polyb->next;
		Rear = polyc;
		while (q)
		{
			exp = p->exp + q->exp;
			coef = p->coef*q->coef;
			while (Rear->next&&Rear->next->exp > exp)
			{
				Rear = Rear->next;
			}
			// 如果这个指数已存在
			if (Rear->next&&Rear->next->exp == exp)
			{
				// 如果这个指数对应的系数不为0
				if (Rear->next->coef + coef)
				{
					Rear->next->coef += coef;
				}
				// 否则删去这个节点
				else
				{
					temp = Rear->next;
					Rear->next = temp->next;
					free(temp);
				}
			}
			// 如果这个指数不存在,添加这个节点到链表中
			else
			{
				temp = (Polynode*)malloc(sizeof(Polynode));
				temp->coef = coef;
				temp->exp = exp;
				temp->next = Rear->next;
				Rear->next = temp;
				Rear = Rear->next;
			}
			q = q->next;
		}
		p = p->next;
	}
	return polyc;
	
	
}
 
 
 
 
 
int main()
{
	Polylist Polya, Polyb, Polyc;
	InitPoly(&Polya);
	InitPoly(&Polyb);
	InitPoly(&Polyc);
	PolyCreate(Polya);
	PolyCreate(Polyb);
	Polyc = PolyMult(Polya, Polyb);
	PrintPoly(Polyc);

}

