/*【问题描述】（建议用链表实现）

编写一个程序实现两个一元多项式相乘。

【输入形式】

首先输入第一个多项式中系数不为0的项的系数和指数，以一个空格分隔。且该多项式中各项的指数均为0或正整数，系数和最高幂次不会超过int类型的表示范围。对于多项式 anxn +a n-1 x n-1 +......+ a1x1 + a0x0 的输入方法如下：
an  n  a n-1  n-1 ......  a1  1  a0  0
即相邻两个整数分别表示表达式中一项的系数和指数。在输入中只出现系数不为0的项。最后一项的指数后没有空格，只有一个回车换行符。
按照上述方式再输入第二个多项式。

【输出形式】

将运算结果输出到屏幕。将系数不为0的项按指数从高到低的顺序输出，每次输出其系数和指数，均以一个空格分隔，最后一项的指数后也可以有一个空格。

【样例输入】

10 80000 2 6000 7 300 5 10 18 0
3 6000 5 20 8 10 6 0

【样例输出】

30 86000 50 80020 80 80010 60 80000 6 12000 21 6300 10 6020 31 6010 66 6000 35 320 56 310 42 300 25 30 130 20 174 10 108 0

【样例说明】

输入的两行分别代表如下表达式：
10x80000 + 2x6000 + 7x300 + 5x10 + 18
3x6000 + 5x20 + 8x10 + 6
相乘结果为：
30x86000 + 50x80020 + 80x80010 + 60x80000 + 6x12000 + 21x6300 + 10x6020 + 31x6010 + 66x6000 + 35x320 + 56x310 + 42x300 + 25x30 + 130x20 + 174x10 + 108

提示：利用链表存储多项式的系数和指数。

【评分标准】

该题要求输出相乘后多项式中系数不为0的系数和指数，共有5个测试点。上传C语言文件名为multi.c。*/

#include<stdio.h>
#include<stdlib.h>
typedef struct linklist {
	int a,b;
	struct linklist * pnext;
} list;
list *add(list *x,list *y) {//此函数用于将两个多项式相加
	list *ll=(list *)malloc(sizeof(list));
	list *currentnode=ll,*m=x,*n=y;
//	if(currentnode==NULL) {
//		printf("TOUR LINKLIST IS NULL!!!!\n");
//		return ll;
//	}
//	if(n==NULL){
//		printf("YOUR LINKLIST IS NULL\n");
//		return n;
//	}
	list *p, *q, *first = NULL;
	while(m!=NULL||n!=NULL){
		p = (list *)malloc(sizeof(list));
		p->pnext = NULL;
		if(n==NULL && m!=NULL){
			p->a = m->a;
			p->b = m->b;
			m = m->pnext;
		}else if(m==NULL && n!=NULL){
			p->a = n->a;
			p->b = n->b;
			n = n->pnext;
		}
		else if(m->b>n->b){
			p->a = m->a;
			p->b = m->b;
			m = m->pnext;
		}else if(m->b<n->b){
			p->a = n->a;
			p->b = n->b;
			n = n->pnext;
		}else{
			p->a = m->a + n->a;
			p->b = m->b;
			m = m->pnext;
			n = n->pnext;
		}
		
		if(first == NULL){
			first = p;
			q = p;
		}else{
			q->pnext = p;
			q = q->pnext;
		}
	}
	return first;
//	while(m!=NULL&&n!=NULL){
//		if(m->b>n->b){
//			currentnode->a=m->a;
//			currentnode->b=m->b;
//			currentnode->pnext=(list *)malloc(sizeof(list));
//			currentnode=currentnode->pnext;
//			m=m->pnext;
//		}else if(m->b<n->b){
//			currentnode->b=n->b;
//			currentnode->a=n->a;
//			currentnode->pnext=(list *)malloc(sizeof(list));
//			currentnode=currentnode->pnext;
//			n=n->pnext;
//		}else{
//			currentnode->a=m->a+n->a;
//			currentnode->b=n->b;
//			currentnode->pnext=(list *)malloc(sizeof(list));
//			currentnode=currentnode->pnext;
//			m=m->pnext;
//			n=n->pnext;
//		}
//	}
//	if(n==NULL&&m==NULL){
//		currentnode=NULL;
//		return ll;
//	}
//	if(n!=NULL){
//		while(n!=NULL){
//			currentnode->a=n->a;
//			currentnode->b=n->b;
//			currentnode->pnext=(list *)malloc(sizeof(list));
//			currentnode=currentnode->pnext;
//			n=n->pnext;
//		}
//	}else if(m!=NULL){
//		while(m!=NULL){
//			currentnode->a=m->a;
//			currentnode->b=m->b;
//			currentnode->pnext=(list *)malloc(sizeof(list));
//			currentnode=currentnode->pnext;
//			m=m->pnext;
//		}
//	}
//	currentnode=NULL;
//	return ll;
}
list *multi(int m,int n,list *head) {//此函数用于将一个多项式与一个单项m*x^(n) 相乘
    list *p,*q,*first=NULL;
	list *currentnode=head;
	while(currentnode!=NULL){
		p=(list *)malloc(sizeof(list));
		p->pnext=NULL;
		p->a=m*currentnode->a;
		p->b=n+currentnode->b;
		currentnode=currentnode->pnext;
		if(first==NULL){
			first=q=p;		
		}else{
			q->pnext=p;
			q=q->pnext;
		}
	} 
	return first;
}
int main() {
	int num1=0,num2=0,num3=0,i;
	list *head1=NULL,*head2=NULL,*p=NULL,*q=NULL,*tail1=NULL,*tail2=NULL;
	while(1) {//读入head1
		p=(list *)malloc(sizeof(list)); 
		scanf("%d%d",&p->a,&p->b);
		p->pnext = NULL;//
		if(getchar()=='\n') {
			if(num1==0) {
				head1=tail1=p;
				tail1->pnext=NULL;
				break;
			}
			tail1->pnext=p;
			tail1=tail1->pnext;
			tail1->pnext=NULL;
			break;
		}
		if(head1==NULL) {
			head1=tail1=p;
			tail1->pnext=NULL;
		} else {
			tail1->pnext=p;
			tail1=tail1->pnext;
			tail1->pnext==NULL;
		}
		num1++;
	}
	p=NULL;
	q=NULL;
	for(num2=0; num2<5000; num2++) {//读入head2
		p=(list *)malloc(sizeof(list));
		scanf("%d%d",&p->a,&p->b);
		if(getchar()=='\n') {
			if(num2==0) {
				head2=p;
				tail2=p;
				tail2->pnext=NULL;
				break;
			}
			tail2->pnext=p;
			tail2=tail2->pnext;
			tail2->pnext=NULL;
			break;
		}
		if(head2==NULL) {
			head2=p;
			tail2=p;
			tail2->pnext=NULL;
		} else {
			tail2->pnext=p;
			tail2=tail2->pnext;
			tail2->pnext=NULL;
		}
	}
	list *currentnode=head1,*ans=NULL;
	list *temp=NULL,*l=NULL;
	while(head1!=NULL) {
		temp=multi(head1->a,head1->b,head2);//将head1拆成很多个a*x^b与head2相乘
		ans=add(ans,temp);//将这些乘式的结果相加
		head1=head1->pnext;
	}
	while(ans!=NULL) {
		printf("%d %d ",ans->a,ans->b);
		ans=ans->pnext;
	}
	return 0;
}

