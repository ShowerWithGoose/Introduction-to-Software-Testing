#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct multi{
	int an;
	int xn;
	struct multi *lower;
}multi;
int main()
{
	multi *lista=NULL,*listb=NULL,*a,*b,*p,*q,*list=NULL,*r;
	int an,xn;
	while (~scanf("%d%d",&an,&xn)){//建立链表(有序输入)
		q=malloc(sizeof(multi));
		q->an=an;
		q->xn=xn;
		q->lower=NULL;
		if (lista==NULL)
			a=lista=p=q;
		else if (p->xn<=q->xn){//a,b两表输入时已按降序，不降点即为b表起点
			p->lower=NULL;
			b=listb=p=q;
		}
		else{
			p->lower=q;
			p=q;
		}
	}
	while (a!=NULL){//建一个乘积的降序新链表
		q=malloc(sizeof(multi));
		q->an=a->an*b->an;
		q->xn=a->xn+b->xn;
		q->lower=NULL;
		if (list==NULL)//乘积第一项为最高次项
			list=p=q;
		else if (p->xn==q->xn)//次数相等则常数相加
			p->an=p->an+q->an;
		else if (p->xn>q->xn){//本项次数低于现表最后一项次数
			p->lower=q;
			p=q;
		}
		else{//本项次数高于现表最后一项系数
			r=list;
			while (r->lower->xn>=q->xn)//从表头开始降序查找
				r=r->lower;
			if (r->xn==q->xn)//次数相等则常数相加
				r->an=r->an+q->an;
			else{//本项次数低于现表前一项次数
				q->lower=r->lower;
				r->lower=q;
			}
		}
		if ((b=b->lower)==NULL){//遍历两表相乘
			b=listb;
			a=a->lower;	
		}
	}
	r=list;
	while (r!=NULL){//按list顺序降序输出
		printf("%d %d ",r->an,r->xn);
		r=r->lower;
	}
	return 0;
}



