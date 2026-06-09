#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
//将struct与typedef分开定义
typedef struct node{
	int c;			//系数
	int e;			//指数
	struct node *link;
}*Linklist,LNode;
Linklist Read();//读入 
Linklist Attach(int c,int e,Linklist r);//合成 
Linklist multi(Linklist P1,Linklist P2);//乘法 

int main()
{
	Linklist list1,list2,list3;
	//读入多项式1
	list1=Read();
	//读入多项式2
	list2=Read();
	//乘法运算并输出,返回的也是指针
	list3=multi(list1,list2);
	while(list3!=NULL) {
		printf("%d %d ",list3->c,list3->e);
		list3=list3->link;
	}
	return 0;
}

Linklist Read()
{
	Linklist p,r,t;
	//p为链表，r用于遍历,t为结点 
	p=(Linklist)malloc(sizeof(LNode));
	p->link=NULL;
    r=p;
	int c,e;
	char ch;
	scanf("%d %d",&c,&e);
	r=Attach(c,e,r);
	while((ch=getchar())!='\n'){
		scanf("%d %d",&c,&e);
		r=Attach(c,e,r);
	}
	t=p;
	p=p->link;
	free(t);//删除临时生成的头结点 
	return p;
}
Linklist Attach(int c,int e,Linklist r)
{
	Linklist p;
	p=(Linklist)malloc(sizeof(LNode));
	p->c=c;
	p->e=e;
	p->link=NULL;
	r->link=p;
    return p;
}
Linklist multi(Linklist list1,Linklist list2)
{
    Linklist p,r,p1,p2,t;
    //p1,p2遍历list1,list2 
	//t用于生成新结点,r为要插入的项 
	//p为存放结果的链表,最后返回p 
	int c,e;
	p1=list1;
	p2=list2;
	p=(Linklist)malloc(sizeof(LNode));//申请空结点 
	p->link=NULL;
    r=p;
	while(p2!=NULL){
		r=Attach(p1->c*p2->c,p1->e+p2->e,r);
		p2=p2->link;	//p2往后移 
	}
	//先用p1第一项和p2生成新链表第一项 
	p1=p1->link;
	while(p1!=NULL){
		p2=list2;//p2从头开始 
		r=p;	//r开始指向p,遍历p 
		while(p2!=NULL){
			e=p1->e+p2->e;	//指数相加 
			c=p1->c*p2->c;	//系数相乘
			while(r->link&&r->link->e>e)	
		    //r的下一项的指数大于要插入的指数,所以r还要往后移 
				r=r->link;
			if(r->link&&r->link->e==e){	
			//下一项的指数等于要插入的指数,要相加 
				if(r->link->c+c)//系数相加后不等于0,c加进原来的
					r->link->c+=c;
				else{			//系数相加后等于0,删掉
					t=r->link;
					r->link=t->link;
					free(t);
				}
			}
			else{//下一项的指数小于要插入的指数,可以插入
				t=(Linklist)malloc(sizeof(LNode));	
				t->c=c;//t有数据域时要申请空间 
				t->e=e;
				t->link=r->link;
				r->link=t;
				r=r->link;
			}
			p2=p2->link;
		}
		p1=p1->link;
	}//第一个空结点要删掉!!
	p2=p;
	p=p->link;
	free(p2);
	return p;
}







