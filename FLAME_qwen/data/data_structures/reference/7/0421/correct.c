#include<stdio.h>
#include <malloc.h>
struct node
{
    int num;
    struct node *lc,*rc;
};
typedef struct node NODE,*NO;

NO in(NO p,int a);
int height(NO p,int num);
void inorder(NO p);

NO root=NULL;

int main()
{
    int a,i,n;
    NO p;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a);
        root=in(root,a);
    }
    p=root;
    inorder(p);

    return 0;
}

int height(NO k,int num)
{
    if(!k)
        return -1;
    if(k->num==num&&k->rc==NULL&&k->lc==NULL)
        return 0;
    int l=height(k->lc,num);
    if(l==-1)
    l=height(k->rc,num);
    if(l!=-1)
   return l+1;
}

NO in(NO p,int a)
{
    if(p==NULL)
    {
        p=(NO)malloc(sizeof(NODE));
        p->num=a;
        p->lc=p->rc=NULL;

    }
    else if(a>=p->num)
        p->rc=in(p->rc,a);
    else if(a<p->num)
        p->lc=in(p->lc,a);
    return p;
}


void inorder(NO p)
{
    if(p!=NULL)
    {
        inorder(p->lc);
        if(p->lc==NULL&&p->rc==NULL)
        printf("%d %d\n",p->num,height(root,p->num)+1);
        inorder(p->rc);
    }

}

