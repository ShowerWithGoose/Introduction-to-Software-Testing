#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int sign;
    int index;
    struct node* next;

} node;
typedef node* num;

num create_num();

void print_num(num p);
void num_add(num p1,num p2);
num num_muti(num p1,node*p2);


int main()
{
    num num1=create_num();
    num num2=create_num();
    node*p1=num1,*p2=num2;
    
    int temp_index,temp_sign;
    while(1)
	{ 
        scanf("%d%d",&temp_sign,&temp_index);      
        p1->next=malloc(sizeof(node));
        p1 = p1->next;
        p1->sign=temp_sign;
        p1->index=temp_index;
        p1->next=NULL;
        if(getchar()=='\n')break;
    }
    
    
    while(scanf("%d %d",&temp_sign,&temp_index)!=EOF)
	{       
        p2->next=malloc(sizeof(node));
        p2=p2->next;
        p2->sign=temp_sign;
        p2->index=temp_index;
        p2->next=NULL;
        if(getchar()=='\n')break;
    }
    
    num ans=create_num();
    node*p=num2->next;
    while(p!=NULL)
	{
        num_add(ans,num_muti(num1,p));
        p=p->next;
    }
    print_num(ans);

    return 0;
}


num create_num()
{
    node* list=malloc(sizeof(node));
    list->next=NULL;
    return list;
}


void print_num(num p)
{
    p=p->next;//第一个是哑结点
    while(p!=NULL)
	{
        printf("%d %d ",p->sign,p->index);
        p=p->next;
    }
}


void num_add(num p1,num p2)

{
    node*p=p1;
    p1=p1->next;
    p2=p2->next;
    while(p1!=NULL&&p2!=NULL)
	{
        if(p1->index>p2->index)
		{
            p->next=p1;
            p1=p1->next;
        }
		else if(p1->index<p2->index)
		{
            p->next=p2;
            p2=p2->next;
        }
		else 
		{
            p1->sign+=p2->sign;
            p->next=p1;
            p1=p1->next;
            p2=p2->next;
        }
        p=p->next;        
    }
    if(p1==NULL)
    {
    	p->next=p2;
	}
	
    else if(p2==NULL)
    {
    	p->next=p1;
	}
	
    else
    {
    	p->next=NULL;
	}
	   
}


//计算一个多项式和一个项之积
num num_muti(num p1, node*p2)

{
    num result=create_num();
    node*final=result;
    node*p=p1->next;
    while(p!=NULL)
	{
        final->next=malloc(sizeof(node));
        final=final->next;
        final->sign=p->sign * p2->sign;
        final->index=p->index + p2->index;
        p=p->next;
        final->next=NULL;      
    }   
    return result;
}




