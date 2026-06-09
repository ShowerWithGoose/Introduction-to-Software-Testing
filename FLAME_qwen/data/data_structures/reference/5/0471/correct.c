#include<stdio.h>
#include<malloc.h>
typedef struct node {
	int left;
	int up;
	struct node* link;
}Node,*pNode;
pNode creatList(pNode list)
{
	pNode p=NULL, q=NULL;
	int a,b;
	char ch;
	do
	{
	    scanf("%d%d%c",&a,&b,&ch);
		p = (pNode)malloc(sizeof(Node));
		p->left = a;
		p->up = b;
		p->link = NULL;
		if (list == NULL)
			list = p;
		else
			q->link = p;
		q = p;
	}while(ch!='\n');
	return list;
}
pNode multiplyList(pNode list)
{
    pNode p=list,q=NULL,listb=NULL,m=NULL;
    int a,b;
    char ch;
    do
    {
        scanf("%d%d%c",&a,&b,&ch);
        p=list;
        while(p!=NULL)
        {
            q=(pNode)malloc(sizeof(Node));
            q->left=a*(p->left);
            q->up=b+(p->up);
            q->link=NULL;
            if(listb==NULL)
                listb=q;
            else
                m->link=q;
            m=q;
            p=p->link;
        }
    }
    while(ch!='\n');
    return listb;
}
pNode arrangeList(pNode list)
{
	pNode p=list,q=NULL,r=NULL,m=NULL;
	int max=p->up, temp;
	while(p->left==0)
    {
        list=p->link;
        free(p);
    }
	while (p->link!= NULL)
	{
		q = p->link;
		m=p;
		max = p->up;
		while (q!= NULL)
		{
			if (q->left == 0)
			{
				r = q;
				m->link = q->link;
				free(q);
				q=m->link;
				continue;
			}
			if (max < q->up)
			{
				max = q->up;
				temp = p->left;
				p->left = q->left;
				q->left = temp;
				temp = p->up;
				p->up = q->up;
				q->up = temp;
				q = q->link;
				m=m->link;
				continue;
			}
			else if (max == q->up)
			{
				p->left = p->left + q->left;
				r = q;
				m->link = q->link;
				free(r);
				q=q->link;
				m=m->link;
				continue;
			}
			q = q->link;
			m=m->link;
		}
		p = p->link;
	}
	return list;
}
int main()
{
	pNode lista = NULL, listb = NULL;
	lista = creatList(lista);
	listb=multiplyList(lista);
	listb=arrangeList(listb);
	while(listb!=NULL)
    {
        printf("%d %d ",listb->left,listb->up);
        listb=listb->link;
    }
	return 0;
}

