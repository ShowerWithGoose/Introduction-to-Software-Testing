#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	int dep;
	struct node* l;
	struct node* r;
};
int s,l=0;
struct node* t=NULL;
struct node* creattree(struct node *,int,int);
void cz(struct node *);
int main()
{
	scanf("%d",&s);
	struct node *p=NULL;
	int n,i;
	for(n=0;n<s;n++)
	{
		scanf("%d",&i);
		p=creattree(p,i,l);
	}
	t=p;
//	printf("%d",p->num);
	cz(t);
	return 0;
}
struct node* creattree(struct node *p,int m,int n)
{

    if(p == NULL){
    	n++;
        p = (struct node*)malloc(sizeof(struct node));
        p->num = m;
        p->dep = n;
        p->r= NULL;
        p->l=NULL;
    } 
    else if(m<p->num)
    p->l=creattree(p->l,m,p->dep);
    else if(m>=p->num)
    p->r=creattree(p->r,m,p->dep);
    return p;
}
void cz(struct node *p)
{	
	if(p!=NULL)
	{//printf("%d\n",p->num);
		if(p->l==NULL&&p->r==NULL)
		printf("%d %d\n",p->num,p->dep);
		cz(p->l);
		cz(p->r);
	}
}


