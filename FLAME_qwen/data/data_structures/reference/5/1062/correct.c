#include <ctype.h>
#include <iso646.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1024
struct tagnode{
	int pre;
	int pow;
	struct tagnode* next;
}; 
typedef struct tagnode node;
void Listsort(node * L)
{
	int i ,count = 0, num;//count记录链表结点的个数，num进行内层循环，
	node *p, *q, *tail;//创建三个指针，进行冒泡排序
	p = L;
	while(p->next != NULL)//计算出结点的个数
	{
		count++;//注释①
		p = p->next;
	}
	for(i = 0; i < count - 1; i++)//外层循环，跟数组冒泡排序一样
	{
		num = count - i - 1;//记录内层循环需要的次数，跟数组冒泡排序一样，
		q = L->next;//令q指向第一个结点
		p = q->next;//令p指向后一个结点
		tail = L;//让tail始终指向q前一个结点，方便交换，也方便与进行下一步操作
		while(num--)//内层循环 次数跟数组冒泡排序一样
		{
			if(q->pow< p->pow)//如果该结点的值大于后一个结点，则交换
			{
				q->next = p->next;
				p->next = q;
				tail->next = p;
			}
			tail = tail->next;//注释②
			q = tail->next;//注释②
			p = q->next;//注释②
		 } 
	} 
}
void put(node *head){
	node *tmp;
	tmp=(node*)malloc(sizeof(node));
	for(tmp=head;tmp!=NULL;tmp=tmp->next){
		printf("%d %d ",tmp->pre,tmp->pow);
		//tmp=(node*)malloc(sizeof(node));
	}
}
node *deleteNode(node *list,node *p){
      node* r;
      if(p==list){                         
             list=list->next;
             free(p);                        
       }
      else{
             for(r=list; r->next!=p  &&  r->next!=NULL; r=r->next);                          
             if(r->next!=NULL){ 
                   r->next=p->next;
                   free(p);                  
              }
      } 
      return list;
}
void order(node *first){
	node *p_order,*q_order,*tmp;
	tmp=NULL;
	q_order=p_order=(node*)malloc(sizeof(node));
	for(p_order=first;p_order!=NULL;p_order=p_order->next){ 
		for(q_order=p_order->next;q_order!=NULL;){
			
			if(q_order->pow==p_order->pow){
				p_order->pre=q_order->pre+p_order->pre;
				deleteNode(first,q_order);
				q_order=q_order->next;
			}
			else q_order=q_order->next;
		}
	}
	//put(first);
	Listsort(first);
	put(first);
	free(p_order);
	free(q_order);
}
int main()
{
	int i;
	node *p,*q,*r,*t,*l,*tag_r,*head,*first;
	head=NULL;
	first=(node*)malloc(sizeof(node));
	first=NULL;
	char note;
	p=q=(node*)malloc(sizeof(node));
	do{scanf("%d %d%c",&q->pre,&q->pow,&note);
		if(head==NULL){
			head=p=q;
		}
		else{
			p->next=q;
			p=p->next;
		}
		q->next=NULL;
		q=(node*)malloc(sizeof(node));	
	}while(note!='\n');
//	put(head);
	t=(node*)malloc(sizeof(node));
	l=(node*)malloc(sizeof(node));
	tag_r=r=(node*)malloc(sizeof(node));
	do{scanf("%d %d%c",&t->pre,&t->pow,&note);
			for(l=head;l!=NULL;l=l->next){
				tag_r->pre=(l->pre)*(t->pre);
				tag_r->pow=l->pow+t->pow;
				if(first==NULL){		
					first=r=tag_r;
				}
				else{
					r->next=tag_r;
					r=r->next;
				}
				tag_r=(node*)malloc(sizeof(node));
		}
		t=(node*)malloc(sizeof(node));
	}while(note!='\n');
	r->next=NULL;
	order(first);
    return 0;
}

