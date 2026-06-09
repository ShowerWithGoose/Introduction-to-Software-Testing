
#include <stdio.h>//生成一个链表存放数据 
#include <stdlib.h>
struct  Node { //一个多项式节点结构
	int coe; //系数
	int pow; //幂
	struct Node *next;
};
int main() {
	int a,n;
	char c;
	struct Node *head,*p,*q,*p0,*p1,*q1,*head1;
	head1 = head = p = NULL;
	do {  //创建一个链表存放第一个多项式
		scanf("%d%d%c", &a, &n, &c);
		q =  (struct Node *)malloc(sizeof(struct Node));
		q->coe = a;
		q->pow = n;
		q->next = NULL;
		if( head == NULL)
			head = p = q;
		else {
			p->next = q;
			p = p->next;
		}
	} while ( c != '\n');
	do { //将第二个多项式的每个项插入到第一个多项式链表中
		scanf("%d%d%c", &a, &n, &c);//生成第二个多项式的一个节点
		for(p1=head; p1!=NULL; p1=p1->next) {
			q=(struct Node *)malloc(sizeof(struct Node));
			q->coe=a*p1->coe;
			q->pow=n+p1->pow;
			q->next=NULL;
			if(head1==NULL)head1=p=q;
			else {
				for(p=head1; p!=NULL; p0=p,p=p->next) {//多项式相加
					if(q->pow > p->pow) {
						if(p==head) {
							q->next = head1;    //插入到头节点前
							head1 = q;
							break;
						} else {
							q->next = p;    //将q插入到p前
							p0->next = q;
							break;
						}
					} else if(q->pow == p->pow)  {
						p->coe += q->coe;    //指数相等，系数相加
						free(q);
						break;
					}
				}
				if(p== NULL)  p0->next = q;   //将q插入到尾节点后
			}
		}
	} while ( c != '\n');
	for(p=head1; p!=NULL; p=p->next)
		printf("%d %d " , p->coe,p->pow);
	return 0;

}




