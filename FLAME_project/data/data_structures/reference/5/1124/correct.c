#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int expon;
	int coe;
	struct Node *pNext;
}NODE,*PNODE;
PNODE create_list();
void traverse_list(PNODE pHead);
void insert_list(PNODE pHead,int pos,int expon,int coe);
void attch_list(int e,int c,PNODE *pear);
void delete_list(PNODE pHead,int pos);
PNODE mutiply(PNODE pHead_a,PNODE pHead_b);

int main()
{
    PNODE pHead_a=NULL,pHead_b=NULL,pHead_c=NULL;
	pHead_a=create_list();
	pHead_b=create_list(); 
	pHead_c=mutiply(pHead_a,pHead_b);
	traverse_list(pHead_c);
	return 0;    	
}

PNODE create_list()
{
	int i,n,val_expon,val_coe;
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	PNODE pTail=pHead;
	pTail->pNext = NULL;
	if(pHead==NULL)
	{
		printf("分配失败");
		exit(-1);
	}
	
	do{
		scanf("%d%d",&val_coe,&val_expon);
	    PNODE pNew=(PNODE)malloc(sizeof(NODE));
	    if(pNew==NULL)
	    {
	    	printf("分配失败");
			exit(-1); 
		}
		pNew->coe = val_coe;
		pNew->expon = val_expon;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew; 
	}while(getchar()!='\n');
	return pHead;
}
void traverse_list(PNODE pHead)
{
	PNODE p=pHead->pNext ;
	while(p!=NULL)
	{
		printf("%d %d ",p->coe ,p->expon );
		p=p->pNext ;
	}
	printf("\n");
	return;
}

void insert_list(PNODE pHead,int pos,int val_expon,int val_coe)
{
	PNODE p=pHead;
	int i=0;
	while(NULL!=p&&i<pos-1)
	{
		p=p->pNext ;
		i++;
	}
	if(i>pos-1||p==NULL)
	{
		printf("数据非法");
		exit(-1); 
	}
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	pNew->coe = val_coe;
	pNew->expon = val_expon;
	if(NULL == pNew)
	{
		printf("内存分配失败");
		exit(-1); 
	}
	PNODE q=p->pNext ;
	p->pNext = pNew;
	pNew->pNext = q  ;
	return ;
}

void delete_list(PNODE pHead,int pos)
{
	
	PNODE p = pHead;
	int i=0;
	while(i<pos-1&&NULL!=p->pNext )  
	{
		p=p->pNext ;
		i++;
	}
	if(i>pos-1||p->pNext ==NULL)
	{
		printf("数据非法");
		exit(-1); 
	}
	PNODE q=p->pNext ;
	p->pNext = p->pNext->pNext ;
	free(q);
	q=NULL;
	return ;
}
void attch_list(int e,int c,PNODE *pear)
{
	PNODE P=(PNODE)malloc(sizeof(NODE));
	P->coe =c;
	P->expon =e;
	P->pNext =NULL;
	(*pear)->pNext=P;
	*pear=P;
}
PNODE mutiply(PNODE pHead_a,PNODE pHead_b)
{
	PNODE pHead_c=(PNODE)malloc(sizeof(NODE));
	pHead_c->pNext = NULL; 
	PNODE pear=pHead_c,p_a=pHead_a->pNext ,p_b=pHead_b->pNext ;
	int e,c,cnt;//cnt用来记录pear指向第几个c的节点; 
	while(p_b!=NULL)
	{
		if(p_a->coe*p_b->coe!=0)
		attch_list(p_a->expon+p_b->expon,p_a->coe*p_b->coe,&pear);
		p_b=p_b->pNext ;
	}
	p_a=p_a->pNext ;
	while(p_a!=NULL)
	{
	    p_b=pHead_b->pNext;
		
		while(p_b!=NULL)
		{   
		    pear=pHead_c->pNext;
			cnt=0;
			e=p_a->expon + p_b->expon ;
			c=p_a->coe * p_b->coe ;
			while(pear->pNext&&e<pear->pNext->expon)
			{
				cnt++;
				pear=pear->pNext ;
			}
			if(pear->pNext == NULL)
			{
				attch_list(e,c,&pear);
			}
			else if(pear->pNext->expon==e)
			{
				pear->pNext->coe+=c;
				if(pear->pNext->coe ==0)
				delete_list(pHead_c,cnt+1);
			}
			else if(pear->pNext->expon < e)
			{ 
			    cnt+=2;
				insert_list(pHead_c,cnt,e,c);
			}
			p_b=p_b->pNext; 
		}
		p_a=p_a->pNext ;
	}
	return pHead_c;
}

