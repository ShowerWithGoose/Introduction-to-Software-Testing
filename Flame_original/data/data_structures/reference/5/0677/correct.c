#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	struct node{
		int coe;
		int index;
		struct node *link;
	};
	typedef struct node Node;
	typedef struct node* Nodeptr;
	Nodeptr list1,list2,list3,end1,end2,end3,p,p1,p2,p3;	//定义三个链表 
	list1=list2=end1=end2=p=list3=end3=NULL;	//初始化
	int a=0,b=0;
	char c='\0';
	while(c!='\n')	//输入第一个多项式 
	{
		scanf("%d %d%c",&a,&b,&c);
		p=(Nodeptr)malloc(sizeof(Node));
		p->coe = a;
		p->index = b;
		p->link = NULL;
		if(list1==NULL)
			list1=end1=p;
		else
			end1->link=p;
		end1 = p;
	}
	p=list2;
	c='\0';
	while(c!='\n')	//输入第二个多项式 
	{
		scanf("%d %d%c",&a,&b,&c);
		p=(Nodeptr)malloc(sizeof(Node));
		p->coe = a;
		p->index = b;
		p->link = NULL;
		if(list2==NULL)
			list2 = end2 = p;
		else
			end2->link = p;
		end2 = p;
	}
	
	p2=list2;
	p1=list1;

	while(p2!=NULL)		//遍历计算 
	{
		p1=list1;
		while(p1!=NULL)
		{
			int temp_coe = p2->coe * p1->coe;
			int temp_index = p2->index + p1->index;
			p3=list3;
			while(1)
			{
				Nodeptr temp = (Nodeptr)malloc(sizeof(Node));
				temp->coe = temp_coe;
				temp->index = temp_index;
				temp->link = NULL;
				if(list3==NULL)
				{	
					list3=end3=temp;
					break;
				}	
				if(p3->index == temp_index)
				{
					p3->coe += temp_coe;
					free(temp);
					break;
				}else if(p3->link==NULL){
					p3->link = temp;
					end3 = temp;
					break;
				}else if(p3->link->index < temp_index){
					temp->link = p3->link;
					p3->link = temp;
					break;
				}
				p3=p3->link;
			}
			p1=p1->link;
		}
		p2=p2->link;
	}
	p=list3;	//输出结果 
	while(p!=NULL)
	{
		printf("%d %d ",p->coe,p->index);
		p=p->link;
	}
	return 0;
}

