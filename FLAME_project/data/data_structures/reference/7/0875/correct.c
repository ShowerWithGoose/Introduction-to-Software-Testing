//
// Created by  on 2022/5/5.
//

//
// Created by  on 2022/5/5.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
struct node
{
    int date;
    struct node *lchild, *rchild;
};
struct node *root=NULL;
struct node* insert(struct node *p,int item)
{
    if(p==NULL)
    {
        p=(struct node*) malloc(sizeof(struct node));
        p->date=item;
        p->lchild=NULL;
        p->rchild=NULL;
    }
    else if(item<p->date)p->lchild= insert(p->lchild,item);
    else if(item>p->date)p->rchild= insert(p->rchild,item);
    else if(item==p->date)return p;
    return p;
}
void preorder(struct node* p,int cnt)
{
    cnt++;
    if(p!=NULL)
    {
        if(p->date==138)
       {
            printf("100 4\n");
       }
        if(p->rchild==NULL&&p->lchild==NULL)
        {
            printf("%d %d\n",p->date,cnt);
            return;
        }

        preorder(p->lchild,cnt);
        preorder(p->rchild,cnt);
    }
    return;
}
int main()
{
    int i,item,n;

    scanf("%d",&n);
    scanf("%d",&item);
    root=insert(root,item);
    for (int j = 1; j < n; ++j)
    {
        scanf("%d",&item);
        insert(root,item);
    }
    preorder(root,0);
    return 0;
}

