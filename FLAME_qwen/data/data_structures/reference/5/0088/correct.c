#include<stdio.h>
#include<malloc.h>
typedef struct Node{
	int kei;
	int enn;
	struct Node *link;
	
	
}LNode,*Linklist;//定义链表 


int main()
{
	int i,j,k,e,num1;
	Linklist p,r,p1,r1,p2,r2,list1=NULL,list2=NULL;
	char c='\0',d='\0';
	for(i=1;c!='\n';i++)
	{
		scanf("%d%d",&k,&e);
		c=getchar();
		p=(Linklist)malloc(sizeof(LNode));
		p->kei=k;
		p->enn=e;
		p->link=NULL;
		if(list1==NULL)
		   list1=p;
		else
		   r->link=p;
		r=p; 
	}//构造链表1 

	scanf("%d%d",&k,&e);
	d=getchar();
	for(p1=list1;p1!=NULL;p1=p1->link)
	{
		p=(Linklist)malloc(sizeof(LNode));
		p->kei=k*p1->kei;
		p->enn=e+p1->enn;
		p->link=NULL;
		if(list2==NULL)
			list2=p;
		else
		    r->link=p;
		r=p;
	}//用第一个数和第一个多项式相乘来构造链表2； 
	
	for(;d!='\n';)
	{
		
		scanf("%d%d",&k,&e);
		d=getchar();
		for(p1=list1;p1!=NULL;p1=p1->link)
		{
			p=(Linklist)malloc(sizeof(LNode));
		    p->kei=k*(p1->kei);
		    p->enn=e+(p1->enn);
		    p->link=NULL;
		    p2=list2;
		   	while(p2!=NULL&&(p->enn)<(p2->enn))
			{
				r2=p2;
				p2=p2->link;
			}
			if(p2==list2)
		    {
				p->link=list2;
				list2=p;
		    }
			else if(p2==NULL)
			{
				r2->link=p;
				p->link=NULL;
			}
			else
			{	
				p->link=p2;
				r2->link=p;
		    }
		    
		}
		
	}//其他数值和第一个多项式相乘后插入链表2； 
	p=list2->link;
	r=list2;
	while(p!=NULL)
	{
		if(r->enn==p->enn)
		{
			r->kei=(r->kei)+(p->kei);
			
			r->link=p->link;
			p=p->link;	
		}
		else
		{
			r=p;
			p=p->link;
		}
			
	}//合并链表2； 
	p=list2;
	while(p!=NULL)
	{
		printf("%d %d ",p->kei,p->enn);
		p=p->link;
	}//输出链表2； 
			
	return 0;
	
 } 

