#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PolyNode * Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
};
void Attach(int coef, int exp, Polynomial * tail);//将新读入的系数和指数加到多项式的末尾 
Polynomial ReadPoly();//读入多项式 
Polynomial MultyPoly(Polynomial poly1, Polynomial poly2);//计算两个多项式积 
void PrintPoly(Polynomial result);
int main()
{
	Polynomial poly1 = ReadPoly();
	Polynomial poly2 = ReadPoly();
	Polynomial product = MultyPoly(poly1, poly2);
	PrintPoly(product);
}
void Attach(int coef, int exp, Polynomial * tail)
{
	Polynomial input = (Polynomial)malloc(sizeof(struct PolyNode));
	//申请新节点并赋初值 
	input->coef = coef;
	input->expon = exp;
	input->link = NULL;
	(*tail)->link = input;
	*tail = input; //修改末尾指针，因为是修改指针，故此处使用指针的指针 
}
Polynomial ReadPoly()
{
	Polynomial poly1, tail, temp;
	int coef,exp;//用来暂存系数和指数 
	poly1 = (Polynomial)malloc(sizeof(struct PolyNode));//申请头节点 
	//申请头节点是为了方便使用Attach函数时，不用区分rear是空还是非空，有了头节点都是非空，插入方便 
	poly1->link = NULL;
	
	tail = poly1;//尾指针指向头节点
	char chara;
	while(scanf("%d%d%c",&coef,&exp,&chara)) 
	{
		Attach(coef, exp, &tail);
		if(chara=='\n')
		break;
	}
	temp = poly1; 
	poly1 = poly1->link;
	free(temp);//头节点方便插入的使命完成，释放头节点
	return poly1; 
}

Polynomial MultyPoly(Polynomial poly1, Polynomial poly2)
{
	Polynomial result, i, j, temp, tail;
	int coef, exp;
	result = (Polynomial)malloc(sizeof(struct PolyNode));
	result->link = NULL;
	
	i = poly1;
	j = poly2;
	tail = result;
	
	if(!i || !j)//如果有一个多项式为空，则乘法结果为空 
		return NULL;
		
	while(j)//先用P1的第一项乘以P2生成一个多项式用于插入 
	{
		coef = i->coef * j->coef;
		exp = i->expon + j->expon;
		Attach(coef, exp, &tail);
		j = j->link;
	}
	i = i->link;//t1指向第二项 
	while(i)
	{
		j = poly2;//将指针重新指向P2的开头 
		tail = result;//用作寻找合适的插入位置 
		while(j)
		{
			coef = i->coef * j->coef;
			exp = i->expon + j->expon;
			while(tail->link && tail->link->expon > exp)//将rear指向指数与e相等或比e小的节点之前一个位置	
				tail = tail->link;
			if(tail->link && tail->link->expon == exp)//如果rear不为空且rear之后的节点指数和e相等，则进行相加 
			{
				if(coef + tail->link->coef)//如果相加不为0
				{
					tail->link->coef += coef;	
					tail = tail->link;
				} 
				else//相加结果为0 ,删除rear之后的节点 
				{
					temp = tail->link;
					tail->link = temp->link;
					free(temp);
				} 
			}
			else //构造一个新节点插入到rear之后 
			{
				temp = (Polynomial)malloc(sizeof(struct PolyNode));
				temp->coef = coef;
				temp->expon = exp;
				temp->link = tail->link;
				tail->link = temp;
				tail = tail->link;
			}
			j = j->link;
		} 
		i = i->link;
	}
	temp = result; 
	result = result->link;
	free(temp);//释放掉头节点
	return result; 
} 
void PrintPoly(Polynomial result)
{
	int isFirstTerm = 0;
	if(!result)
	{
		printf("0 0\n");
		return;
	}
	while(result)
	{
		if(!isFirstTerm)
			isFirstTerm = 1;
		else
			printf(" ");
		printf("%d %d",result->coef, result->expon);
		result = result->link;		
	}
	printf("\n");
}

