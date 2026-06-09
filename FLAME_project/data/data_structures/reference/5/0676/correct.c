#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
	long long  a;
	long long  n;
	struct node *link;
};
typedef struct node Node;
typedef struct node* Nodeptr;

int main()
{
	long long A,N;
	char ch;
	Nodeptr p,q,list_1=NULL,list_2=NULL;
	
	while(1)//输入第一个多项式 
	{   
	    scanf("%lld %lld",&A,&N); 
		q=(Nodeptr)malloc(sizeof(Node));
		q->a=A;
		q->n=N;
		q->link=NULL;
		if(list_1==NULL)
			list_1=p=q;
		else
		{
			p->link=q;
			p=q;
		}
		ch=getchar();
		if(ch=='\n')
		   break;
	}
	Nodeptr p1=list_1;
	scanf("%lld %lld",&A,&N);
	for(p1=list_1;p1!=NULL;p1=p1->link)//第二个多项式的第一项乘以第一个多项式 
	{
		q=(Nodeptr)malloc(sizeof(Node));
	    q->a=A*(p1->a);
	    q->n=N+(p1->n);
		q->link=NULL;
		if(list_2==NULL)
		   list_2=p=q;
		else
		{
			p->link=q;
			p=q;
		}
	}
	Nodeptr p2=list_2;
	
	ch=getchar();
	while(ch!='\n')
	{
		scanf("%lld %lld",&A,&N);
		for(p1=list_1;p1!=NULL;p1=p1->link)
		{
			q=(Nodeptr)malloc(sizeof(Node));//创建链节 
	        q->a=A*(p1->a);
	        q->n=N+(p1->n);
	        q->link=NULL;
	        
	        p2=list_2;
	        while(1)
	        {
	        	if(p2->link==NULL)
	        	{
	        		p2->link=q;
	        		break;
				}
	        	if((p2->link->n)<(q->n))//p2指向的后一项指数小于新增项,插入 
	        	{
	        		q->link=p2->link;
	        		p2->link=q;
	        		break;
				}
	        	else if((p2->link->n)==(q->n))//合并同类项 
	        	{
	        		(p2->link->a)+=q->a;
	        		break;
				}
				else
				{
					p2=p2->link;//p2 移向下一项 
				}
			}
		}   
	ch=getchar();
	if(ch=='\n')
	   break;    
	}
	
	for(p2=list_2;p2!=NULL;p2=p2->link)
	{
		if(p2->a==0)
		   continue;
		
		printf("%lld %lld ",p2->a,p2->n);
	}

	return 0;
}



