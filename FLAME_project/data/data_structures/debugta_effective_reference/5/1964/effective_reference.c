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
void attch_list(int e,int c,PNODE *mark);
void delete_list(PNODE pHead,int pos);
PNODE mutiply(PNODE pHead1,PNODE pHead2);

int main()
{
    PNODE pHead1=NULL,pHead2=NULL,result=NULL;
	pHead1=create_list();
	pHead2=create_list(); 
	result=mutiply(pHead1,pHead2);
	traverse_list(result);
	return 0;    	
}

PNODE create_list()
{
	int i,n,index,content;
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	PNODE pTail=pHead;
	pTail->pNext = NULL;
	if(pHead==NULL)
	{
		printf("分配失败");
		exit(-1);
	}
	
	do{
		scanf("%d%d",&content,&index);
	    PNODE pNew=(PNODE)malloc(sizeof(NODE));
	    if(pNew==NULL)
	    {
	    	printf("分配失败");
			exit(-1); 
		}
		pNew->coe = content;
		pNew->expon = index;
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

void insert_list(PNODE pHead,int pos,int index,int content)
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
	pNew->coe = content;
	pNew->expon = index;
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
void attch_list(int e,int c,PNODE *mark)
{
	PNODE P=(PNODE)malloc(sizeof(NODE));
	P->coe =c;
	P->expon =e;
	P->pNext =NULL;
	(*mark)->pNext=P;
	*mark=P;
}
PNODE mutiply(PNODE pHead1,PNODE pHead2)
{
	PNODE result=(PNODE)malloc(sizeof(NODE));
	result->pNext = NULL; 
	PNODE mark=result,p=pHead1->pNext ,q=pHead2->pNext ;
	int e,c,cnt;//cnt用来记录pear指向第几个c的节点; 
	while(q!=NULL)
	{
		if(p->coe*q->coe!=0)
		attch_list(p->expon+q->expon,p->coe*q->coe,&mark);
		q=q->pNext ;
	}
	p=p->pNext ;
	while(p!=NULL)
	{
	    q=pHead2->pNext;
		
		while(q!=NULL)
		{   
		    mark=result->pNext;
			cnt=0;
			e=p->expon + q->expon ;
			c=p->coe * q->coe ;
			while(mark->pNext&&e<mark->pNext->expon)
			{
				cnt++;
				mark=mark->pNext ;
			}
			if(mark->pNext == NULL)
			{
				attch_list(e,c,&mark);
			}
			else if(mark->pNext->expon==e)
			{
				mark->pNext->coe+=c;
				if(mark->pNext->coe ==0)
				delete_list(result,cnt+1);
			}
			else if(mark->pNext->expon < e)
			{ 
			    cnt+=2;
				insert_list(result,cnt,e,c);
			}
			q=q->pNext; 
		}
		p=p->pNext ;
	}
	return result;
}

