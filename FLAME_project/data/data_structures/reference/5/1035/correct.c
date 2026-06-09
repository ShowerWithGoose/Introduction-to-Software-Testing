#include<stdio.h>
#include<stdlib.h>
#define N 100000
typedef struct node{
	int coe;
	int exp;
	struct node *link;
}Node,*Nodeptr;
Nodeptr list=NULL,p,q,r,p0=NULL;
int main()
{
	int i=0,j=0,la,lb,coe2,exp2,flag;
	int a[N],ae[N],b[N],be[N];
	char c;
	do{
		scanf("%d%d%c",&a[i],&ae[i],&c);  //两个数都后置++后i会被加两次 
		i++;	
	}while(c!='\n');
	la=i;
	do{
		scanf("%d%d%c",&b[j],&be[j],&c);
		j++;	
	}while(c!='\n');

	lb=j;
	for(i=0;i<la;i++)
	{
		for(j=0;j<lb;j++)
		{
			coe2=a[i]*b[j];
			exp2=ae[i]+be[j];
			if(list!=NULL)
			{
				flag=0;
				for(r=list;r!=NULL;r=r->link)
				{
					if(r->exp==exp2)
					{
						r->coe+=coe2;
						flag=1;
						break;
					}
				}
			}//看这一项在链表中是否已经存在 
			if(flag==1) continue;
			q=(Nodeptr)malloc(sizeof(Node));
			q->link=NULL; q->coe=coe2; q->exp=exp2;
			if(list==NULL) list=p=q;
			else
			{
				for(p=list;p!=NULL &&q->exp<p->exp;p0=p,p=p->link)  //判断p!=NULL  !!! 
				;
				//在p之前插入结点
				if(p==list)
				{
					q->link=p;
					list=q;
				 } 
				else
				{
					q->link=p;
					p0->link=q;
				}
			}
		}
	}
	for(p=list;p!=NULL;)
	{
		printf("%d %d ",p->coe,p->exp);
		q=p;
		p=p->link;
		free(q);
	}
	return 0;
}

