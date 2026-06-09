#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int coe;
	int index;
	struct node *link;
}Node,*Nodeptr;
int main()
{
	Nodeptr p,r,s,t,P,Q,list1,list2,list3;
	char c;//每个多项式完成的标记 
	int i=0;
	int n,m;
	list1=r=NULL;
	list2=t=NULL;
	list3=Q=NULL;
	do{
		scanf("%d%d%c",&n,&m,&c);
		p=(Nodeptr)malloc(sizeof(Node));
		p->coe=n;
		p->index=m;
		p->link=NULL;
		if(list1==NULL)
		list1=r=p;
		else
		{
			r->link=p;
			r=r->link;
		}
	}while(c!='\n');//建立第一个多项式链表 
	//for(P=list1;P!=NULL;P=P->link)
	//printf("%d %d ",P->coe,P->index);
	do{
		scanf("%d%d%c",&n,&m,&c);
		s=(Nodeptr)malloc(sizeof(Node));
		s->coe=n;
		s->index=m;
		s->link=NULL;
		if(list2==NULL)
		list2=t=s;
		else
		{
			t->link=s;
			t=t->link;
		}
	}while(c!='\n');//建立第二个多项式链表
	//for(P=list2;P!=NULL;P=P->link)
	//printf("%d %d ",P->coe,P->index);
	for(p=list1,s=list2;s!=NULL;s=s->link)
	{
		P=(Nodeptr)malloc(sizeof(Node));
		P->coe=p->coe*s->coe;
		P->index=p->index+s->index;
		P->link=NULL;
		if(list3==NULL)
		list3=Q=P;
		else
		{
			Q->link=P;
			Q=Q->link;
		}
	}//建立起第三个初始链表	
	//for(P=list3;P!=NULL;P=P->link)
   	//printf("%d %d ",P->coe,P->index);
	for(p=list1->link;p!=NULL;p=p->link)
	{
		for(s=list2;s!=NULL;s=s->link)
		{
			P=(Nodeptr)malloc(sizeof(Node));
			P->coe=p->coe*s->coe;
		    P->index=p->index+s->index;
		    P->link=NULL;
		    for(r=list3;r!=NULL;t=r,r=r->link)
		    {
		    	if(P->index>r->index)
		    	{
		    		if(r==list3)
		    		{
		    			P->link=list3;
		    			list3=P;
		    			break;
					}
					else
					{
						P->link=r;
						t->link=P;
						break;
					}
				}
				else if(P->index==r->index)
				{
					r->coe+=P->coe;
					break;
				}
				
			}
			if(r==NULL)
				t->link=P;
		}
	}
	for(P=list3;P!=NULL;P=P->link)
	printf("%d %d ",P->coe,P->index);
	return 0;	  
}

