//输入，两个链表分别存储数据（两个成员），
//二重循环计算，得结果即存
//除重，排序
//输出

#include<stdio.h>
#include<stdlib.h>

typedef struct list {
	int coe;
	int pow;
	struct list* next;
}mul;

int cmp(void const* x1, void const* x2);
mul* input(mul* head, int data[][BUFSIZ], int num);	//输入 
mul* save(int Coe,int Pow, mul* head);	//储存结果

int a[BUFSIZ][BUFSIZ], b[BUFSIZ][BUFSIZ];
int answ[BUFSIZ][BUFSIZ];

int main()
{
	int Coe=0, Pow=0;
	int jj=0;
	int numa, numb;
	mul* f1, * f2,*ans;
	char c = ' ';

	//头结点
	f1 = (mul*)malloc(sizeof(mul));
	f1->next = NULL;
	f2 = (mul*)malloc(sizeof(mul));
	f2->next = NULL;
	ans = (mul*)malloc(sizeof(mul));
	ans->next = NULL;

	for (numa = 0, c = ' '; c != '\n'; numa++)
	{
		scanf("%d%d%c", &a[numa][0], &a[numa][1], &c);
	}
	f1 = input(f1, a, numa);
	for (numb = 0, c = ' '; c != '\n'; numb++)
	{
		scanf("%d%d%c", &a[numb][0], &a[numb][1], &c);
	}
	f2 = input(f2, a, numb);

	//输入测试点，正确
	/*for (mul* i = f1->next; i != NULL; i = i->next)
	{
		printf("%d %d ", i->coe, i->pow);
	}
	printf("\n");
	for (mul* i = f2->next; i != NULL; i = i->next)
	{
		printf("%d %d ", i->coe, i->pow);
	}*/

	//计算
	
	for (mul* i = f1->next; i != NULL; i = i->next)
		for(mul * j = f2->next; j != NULL; j = j->next)
		{
			Coe = i->coe * j->coe;
			Pow =  (i->pow) +(j->pow) ;
			//printf("%d %d ", Coe, Pow);
			ans=save(Coe, Pow, ans);
		}
	
	//计算测试点，正确
	/*for (mul* i = ans->next; i != NULL; i = i->next)
	{
		printf("%d (%d) ", i->coe, i->pow);
		
	}*/

	//转换
	for (mul* i = ans->next; i != NULL;  i = i->next)
	{
		answ[jj][0] = i->coe;
		answ[jj][1] = i->pow;
		jj++;
	}

	qsort(answ, jj, sizeof(answ[0]), cmp);

	for (int i = 0; i < jj; i++)
	{
		if (i < jj - 1) {
			if (answ[i][1] != answ[i + 1][1]) {
				//不等于，可以输出
				printf("%d %d ", answ[i][0], answ[i][1]);
			}
			else {
				answ[i + 1][0] += answ[i][0];
				continue;
			}
		}
		else {
			printf("%d %d", answ[i][0], answ[i][1]);
		}
	}
	

	return 0;
}

mul* input(mul* head, int data[][BUFSIZ], int num)
{
	mul* p;

	head->next = (mul*)malloc(sizeof(mul));
	p = head->next;

	for (int i = 0; i < num; i++)
	{
		p->coe = data[i][0];
		p->pow = data[i][1];
		if (i < num - 1)
		{
			p->next = (mul*)malloc(sizeof(mul));
			p = p->next;
		}
		else
		{
			p->next = NULL;
		}
	}
	return head;
}

mul* save(int Coe, int Pow, mul* head)
{
	mul* p = head;	//p为头结点
	//到达尾部
	while (p->next!= NULL)
	{
		p = p->next;
	}
	//添加结点
	p ->next= (mul*)malloc(sizeof(mul));
	p->next->coe = Coe;
	p->next->pow = Pow;
	p->next->next = NULL;

	return head;
}

int cmp(void const* x1, void const* x2)
{
	int* x = (int*)x1;
	int* y = (int*)x2;

	if (x[1] < y[1]) {
		return 1;
	}
	else {
		return -1;
	}
}


