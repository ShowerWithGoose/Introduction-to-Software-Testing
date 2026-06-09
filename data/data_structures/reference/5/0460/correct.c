#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int xishu;
	int mi;
	struct Node*next;
} LNode, *LinkList;

/*将系数与幂存在链表中*/
LinkList CreatLinkList() {
	LinkList p, r, list;
	char c;
	list = (LinkList)malloc(sizeof(LNode));
	list->next = NULL;
	r = list;
	do {
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d %d", &p->xishu, &p->mi);
		p->next = NULL;
		c = getchar();
		r->next = p;
		r = p; //确保r始终为尾指针
	} while (c != '\n');
	return list;
}
LinkList ListMulti(int tmpxi, int tmpmi, LinkList p) { //将单项式与多项式相乘
	LinkList list = (LinkList)malloc(sizeof(LNode));
	list->next = NULL;
	LinkList q, r;
	r = list;
	do {
		q = (LinkList)malloc(sizeof(LNode));
		q->xishu = tmpxi * p->xishu; //q的系数和q的幂
		q->mi = tmpmi + (p->mi);
		//printf("%d %d ",q->xishu,q->mi);
		q->next = NULL;
		r->next = q;
		r = q;
		p = p->next; //p后移
	} while (p);
	return list;
}
LinkList ListPlus(LinkList a, LinkList b) {
	LinkList r, list;
	list = (LinkList)malloc(sizeof(LNode));
	list->next = NULL;
	r = list;
	a=a->next;
	b=b->next;
	while (a && b) {
		int ami = a->mi;
		int bmi = b->mi;
		if (ami > bmi) {
			//a的幂次比b大，就把a的结点接到r后面
			//a与c的指针后移
			r->next = a;
			r = r->next;
			a = a->next;
		}
		else if (ami < bmi) {
			r->next = b;
			r = r->next;
			b = b->next;
		}
		else {
			int x = (a->xishu) + (b->xishu);
			if (x != 0) {
				//将x赋给b,再将b赋给r
				b->xishu = x;
				r->next = b;
				r = r->next;
			}
			//如果系数为零，就不管了
			a = a->next;
			b = b->next;
		}
	}
	if (a != NULL)
		r->next = a;
	else if (b != NULL)
		r->next = b;
	else{
		r->next=NULL;
	}
	return list;
}
int main() {
	LinkList a, c, d;
	int tmpxi, tmpmi; //tmpxi是系数，tmpmi是指数
	c = NULL;
	/*读入链表a*/
	a = CreatLinkList();
	a = a->next;
	/*a的存储没有问题*/
	while (scanf(" %d %d", &tmpxi, &tmpmi) != EOF) {
//			printf("%d %d ",tmpxi,tmpmi);
		d = (LinkList)malloc(sizeof(LNode));
		d = ListMulti(tmpxi, tmpmi, a); //把每个单项式与多项式a相乘的结果存到d里
		/*d的生成没有问题*/
		if (c == NULL) {
			c = d; //如果c是空表，那d直接给c
//			{//test
//				printf("c是：\n");
//				LinkList p=c;
//				p=p->next;
//				do{
//					
//					printf("%d %d ",p->xishu,p->mi);
//					p=p->next;
//				}while(p);
//				printf("\n");
//			}
			continue;
		}
			
		c = ListPlus(c, d);
//		{//test
//			printf("c是：\n");
//			LinkList p=c;
//			p=p->next;
//			do{
//				printf("%d %d ",p->xishu,p->mi);
//				p=p->next;
//			}while(p);
//			printf("\n");
//		}
		free(d);
	}
	//输出c就可以了
	c = c->next;
	do {
		printf("%d %d ", c->xishu, c->mi);
		c = c->next;
	} while (c);
	free(c);
	return 0;
}

