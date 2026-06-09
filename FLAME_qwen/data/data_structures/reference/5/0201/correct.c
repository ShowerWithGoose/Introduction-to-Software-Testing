#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct node{
	int coe;
	int pow;
	struct node *next;
};
typedef struct node *nodeptr;
typedef struct node node;

void sort(nodeptr head){//把指数从大到小排 
	nodeptr r,tail;
	r=head;
	tail=NULL;
	if (r == NULL || r->next == NULL){
		return;
	}//这个链表里没有东西 ；或者这个链表里只有一个东西，所以不需要排序了 
	int temp1,temp;
	while(r!=tail){//还有的排 
		while(r->next!=tail){//r后面还有需要排的，不止一个元素 
			if(r->pow < r->next->pow){
				temp=r->pow;
				r->pow=r->next->pow;
				r->next->pow=temp;//交换 
				temp1=r->coe;
				r->coe=r->next->coe;
				r->next->coe=temp1;
			}
			r=r->next;
		}//确定链表最后一个是最小的，下一步是把前n-1个再排序，让前n-1个数的最后一位是最小的
		tail=r;//tail指最后一个;把找到的最小值从下一轮排序里面剔除；
		r=head;//重新开始一遍 
	}
}

void multiply(nodeptr a, nodeptr b){
	nodeptr p1=NULL, p2=NULL, t=NULL, r=NULL, p=NULL, list=NULL;
	for(p1=a;p1!=NULL;p1=p1->next){
		for(p2=b;p2!=NULL;p2=p2->next){
			t=(nodeptr)malloc(sizeof(node));
			t->coe=p1->coe*p2->coe;
			t->pow=p1->pow+p2->pow;//t中存储了相乘后的结果  
		if(list==NULL){
			list=p=t;
		}
		else{
			p->next=t;//把t一个一个地存进p这个链表
			p=p->next;//把p往后推 
		}
		}
	}
	p->next=NULL;//尾指针赋为空 
	//把指数相同的项的系数加起来 
	for(p=list;p->next!=NULL;p=p->next){
		nodeptr r1=p,r2=NULL;
		for(r2=p->next;r2!=NULL;r2=r2->next){
			if(p->pow==r2->pow){
				p->coe+=r2->coe;
				r1->next=r2->next;
				free(r2);
				r2=r1;
			}
			else{
				r1=r2;//r2变成r2后一个了，所以r1永远是r2前一个，用来删除指数相同的r2
			} 
		}
	}
	sort(list);
	for(p=list;p!=NULL;p=p->next){
		printf("%d %d ",p->coe,p->pow);
	}
}

int main(){
	//创建链表
	nodeptr p=NULL,q=NULL,r=NULL,head=NULL,head1=NULL;
	int a,n;
	char c;
	do{
		scanf("%d%d%c",&a,&n,&c);
		if(head==NULL){
			head=q=(nodeptr)malloc(sizeof(node));
		}
		else{
			q->next=(nodeptr)malloc(sizeof(node));
			q=q->next;
		} 
		q->coe=a;
		q->pow=n;
		q->next=NULL;//好习惯
	}while(c!='\n');//c=='\n'说明输入第一行完了，这个链表里存了第一个等式的各个值 
	
	int b,m;
	char d;
	head1=NULL;
	do{
		scanf("%d%d%c",&b,&m,&d);
		if(head1==NULL){
			head1=p=(nodeptr)malloc(sizeof(node));
		}
		else{
			p->next=(nodeptr)malloc(sizeof(node));
			p=p->next;
		} 
		p->coe=b;
		p->pow=m;
		p->next=NULL;//好习惯
	}while(d!='\n');//已读入两个式子 
	
	multiply(head,head1);
	return 0;
}

