#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
	int coe,pow;
	struct node *next;
};
typedef struct node *Nodeptr;
typedef struct node Node;

int main()
{
	int a,b,A,B;
	char c;
	Node *link1,*link2,*n,*p1,*p2,*q1,*q2,*p0;
	link1 = p1 = NULL;
	
	do//创建一个列表存放第一个多项式 
	{
		scanf("%d%d%c",&a,&b,&c);
		q1 = (Nodeptr)malloc(sizeof(Node));
		q1 -> coe = a,q1 -> pow = b,q1 -> next =NULL;
		if(link1 == NULL)
		link1 = p1 = q1;
		else
		{
			p1 -> next = q1;
			p1 = p1 -> next;
		}
	}while(c != '\n');
	
	do 
	{
		scanf("%d%d%c",&a,&b,&c);
		for(p1 = link1;p1 != NULL;p1 = p1 -> next)
		{
			//相乘 
			A = a * p1 ->coe;
			B = b + p1 ->pow;
			
			//插入第三个链表的相应位置 
			q2 = (Nodeptr)malloc(sizeof(Node));
			q2 -> coe = A,q2 -> pow = B,q2 -> next = NULL;
			
			if(link2 == NULL)
			link2 = p2 = q2;//如果是空链表 
			else
			{
				for(p2 = link2;p2 != NULL;p0 = p2,p2 = p2 -> next)
				{
					if(p2 -> pow < q2 -> pow)
					{
						if(p2 == link2)//将q插入到头结点前面 
						{
							q2 -> next = link2,link2 = q2;
							break; 
						}
						else//将q插入到p前面 
						{
							q2 -> next = p2,p0 -> next = q2;
							break;
						} 
					}
					else if(p2 -> pow == q2 -> pow)//指数相等，系数相加 
					{
						p2 -> coe += q2 -> coe;
						break;
					}
				}
				if(p2 == NULL)//将q插入到尾结点后面 
				p0 -> next = q2;
			}
		}
	}while(c != '\n');
	
	for(p2 = link2;p2 != NULL;p2 = p2 -> next) 
	printf("%d %d ",p2 ->coe,p2 ->pow);
	
	return 0;
}

