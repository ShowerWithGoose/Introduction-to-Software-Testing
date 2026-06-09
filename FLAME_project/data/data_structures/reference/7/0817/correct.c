#include<stdio.h>
int h;
int i,n;
int x;
typedef struct node{
	struct node *l;
	struct node *r;
	int y,d;
}tr,*tr2;
tr2 root;
void visit(tr2 x)
{
    if(x->l){
        visit(x->l);
    }
    if(x->l==NULL&&x->r==NULL)
        printf("%d %d\n",x->y,x->d);
    if(x->r){
        visit(x->r);
    }
}
tr2 order(int yy ,int dd)
{
    tr2 x=(tr2)malloc(sizeof(tr));
    x->l=x->r=NULL;
    x->y=yy;
    x->d=dd;
    return x;
}
tr2 add(tr2 w,int x)
{
    h++;
    if(w==NULL)
	{
        w=order(x,h);
    }
    else if(x>=w->y)
        w->r=add(w->r,x);
    else if(x<w->y)
        w->l=add(w->l,x);
    return w;
}
int main()
{
    scanf("%d",&n);
    scanf("%d",&x);
    root=order(x,1);
    for(i=1;i<n;i++)
	{
		h=0;
        scanf("%d",&x);
        add(root,x);
    }
    visit(root);
    return 0;
}





