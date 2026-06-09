#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int coef;
    int exp;
    struct node*next;
}node,*nodeptr;

nodeptr head1=NULL,head2=NULL,ans=NULL;
int num1,num2,num; 

nodeptr creatlist(nodeptr head)//创立链表，输入节点的系数和指数
{
    int m,n;
    char c='0';
    nodeptr q,p;
    while(c!='\n')//检验c是不是\n 
    {  
		scanf("%d%d%c",&m,&n,&c);
        q=(nodeptr)malloc(sizeof(node));
        q->coef=m;
        q->exp=n;
        q->next=NULL;
        num1++;
        if(head==NULL)
            head=p=q;
        else 
            p->next=q;
        p=q;
    }
    return head;
}

int length(nodeptr head)
{
	int i=0;
	nodeptr p;
	for(p=head;p!=NULL;p=p->next)
		i++;
	return i;
}
nodeptr multi_node(nodeptr p,nodeptr q)//节点相乘：系数相乘，指数相加
{
    nodeptr r;
    r=(nodeptr)malloc(sizeof(node));
    r->coef=(p->coef)*(q->coef);
    r->exp=(p->exp)+(q->exp);
    r->next=NULL;
    return r;
}

void insert_node(nodeptr r,nodeptr target)//该函数的作用是将节点r插入到target所指的节点
{
    r->next=target->next;
    target->next=r;
}
nodeptr insertfirst(nodeptr r)
{
	r->next=ans;
	return r;
}
void insert_last(nodeptr r)
{
	nodeptr p;
	for(p=ans;p->next!=NULL;p=p->next)
		;
	insert_node(r,p);
}
void insert(nodeptr r)//此函数的作用是将确定插入节点的位置并插入节点 
{
    nodeptr p;
    int flag=0;
    if(ans==NULL)
    {
    	ans=insertfirst(r);
    	flag=1;
	}	
	else if((r->exp)>(ans->exp))
	{
		ans=insertfirst(r);
		flag=1;
	}	
    else 
	{
		for(p=ans;p->next!=NULL;p=p->next)
		{
			if((r->exp)>(p->next->exp))
            {
            	insert_node(r,p);
            	flag=1;
            	//printf("%d %d\n",r->exp,p->exp);
				break;
			}				
		}
	} 
	if(flag==0)
		insert_last(r);		            
}
void multi()//此函数的作用是将完成乘法的部分
{
    nodeptr p,q;
    for(p=head1;p!=NULL;p=p->next)//挨个做乘法 
        for(q=head2;q!=NULL;q=q->next)
            insert(multi_node(p,q));
}

/*void prt()
{
    nodeptr p=ans->next;
    int coef_sum,exp_sum;
    exp_sum=(ans->exp);
    coef_sum=(ans->coef);
    for(;p!=NULL;p=p->next)
    {
        if((p->exp)==exp_sum)
            coef_sum+=(p->coef);
        else
        {
            printf("%d %d ",coef_sum,exp_sum);
            coef_sum=p->coef;
            exp_sum=p->exp;
        }
    }
}*/

int main()
{
	nodeptr p;
	int coef_sum,exp_sum;
    head1=creatlist(head1);
    head2=creatlist(head2);
    multi(head1,head2);
    exp_sum=(ans->exp);
    coef_sum=(ans->coef);
    for(p=ans->next;p!=NULL;p=p->next)
    {
        if((p->exp)==exp_sum)
            coef_sum+=(p->coef);
        else
        {
            printf("%d %d ",coef_sum,exp_sum);
            coef_sum=p->coef;
            exp_sum=p->exp;
        }
    }
    printf("%d %d",coef_sum,exp_sum);
    return 0;
}

