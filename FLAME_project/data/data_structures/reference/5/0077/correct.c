#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
struct list{
	int coef;
	int expon;
	struct list* next;
	struct list* front;
}; 
void deleteList(struct list* one)
{
    struct list *tmp = one;
    while(tmp != NULL)
    {
        tmp = tmp -> next;
        free(one);
        one = tmp;
    }
    one = tmp;
}
int main()
{
	char c;
	int i,j;
	int cnta=1;
	int cntb=1; 
	int cntc=1;
	struct list *first,*p,*q=NULL;
	struct list *head,*x,*y=NULL;
	struct list *one,*m,*n,*t=NULL;
	//A
	q=(struct list*)malloc(sizeof(struct list));
	q->next=NULL;
	first=p=q;
	q=(struct list*)malloc(sizeof(struct list));
	q->next=NULL;	
	scanf("%d%d",&q->coef,&q->expon);
	p->next=q;
	p=p->next;
	while(c=getchar()==' '){
		q=(struct list*)malloc(sizeof(struct list));
		q->next=NULL;
		scanf("%d%d",&q->coef,&q->expon);	
		p->next=q;
		p=p->next;
		cnta++;
	}
	//B
	y=(struct list*)malloc(sizeof(struct list));
	y->next=NULL;
	head=x=y;
	y=(struct list*)malloc(sizeof(struct list));
	y->next=NULL;	
	scanf("%d%d",&y->coef,&y->expon);
	x->next=y;
	x=x->next;
	while(c=getchar()==' '){
		y=(struct list*)malloc(sizeof(struct list));
		y->next=NULL;
		scanf("%d%d",&y->coef,&y->expon);	
		x->next=y; 
		x=x->next;
		cntb++;
	}//输入数据完毕，m和n都指向第cnta个结点，x和y都指向第cntb个结点 
	q=first;
	y=head;
	q=q->next;//使q和y指向第一个结点 
	y=y->next;
	//创建链表c，和第一个结点 
	n=(struct list*)malloc(sizeof(struct list));
	n->next=NULL;
	one=m=n;
	n->expon=-1;
//现在m,n指向头结点 
	//遍历两个链表，两两相乘，存入c链表
	for(i=0;i<cnta;i++){
		for(j=0;j<cntb;j++){
			if(m->expon==-1){  //c是空表 
			n=(struct list*)malloc(sizeof(struct list));
			n->next=NULL;
			n->front=NULL; 
			n->front=one;
			n->coef=q->coef * y->coef;
			n->expon=q->expon + y->expon;
			m->next=n;
			m=m->next;
			if(y!=x)
			y=y->next;
			else
			y=head->next;				
			}
			else {//c不是空表 
				n=(struct list*)malloc(sizeof(struct list));
				n->next=NULL;
				n->front=NULL; 
				n->coef=q->coef * y->coef;
				n->expon=q->expon + y->expon;
				if(n->expon < m->expon){   //直接连在后面 
					m->next=n;
					n->front=m;
					m=m->next;
					if(y!=x)
					y=y->next;
					else
					y=head->next;
					cntc++;
				}
				else if(n->expon > m->expon){ //需要找到位置插入 
					t=m->front;
					while(t->expon < n->expon){
						t=t->front;
					}
					if(t->expon > n->expon){  //把n插在t后面 
						n->next=t->next;
						t->next->front=n;
						t->next=n;
						n->front=t;
						if(y!=x)
						y=y->next;
						else
						y=head->next;
						cntc++;
					}
					else if(t->expon == n->expon) { //改t数据，删n ,cntc不变 
						t->coef+=n->coef;
						free(n);
						n=NULL;
						if(t->coef==0){
						free(t);
						t=NULL;
						cntc--;
						}
						if(y!=x)
					y=y->next;
					else
					y=head->next;
					
					}
					t=NULL;
				}
				else{   //直接改动m指向的结点内容，删n   
					m->coef+=n->coef;
					free(n);
					n=NULL;
					if(m->coef==0){
						t=m;
						free(t);
						t=NULL;
						cntc--;
					}
					if(y!=x)
					y=y->next;
					else
					y=head->next;
				}
			}
		}
		y=head->next;
		q=q->next;
	}
	 n=one->next;
	 for(i=0;i<cntc;i++){
	 	printf("%d %d ",n->coef,n->expon);
	 	n=n->next;
	 }
	 deleteList(one);
 return 0;
}
/*
1、把输入数据存在两个链表A,B里 √ 
2、两个链表的内容依次对应相乘，生成一个新结点，存入相乘的系数和相加的指数
3、第一个结点直接加入c链表，在首元结点的位置
4、第二次生成的新结点的指数部分，和c的上一个比较，如果大于，就插入头结点和首元结点之间
如果小于，就直接连在该结点后面，如果相等，另c中对应的结点的系数部分加上新的系数
5、依次输出系数和指数部分 


*/

