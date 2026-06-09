#include <stdlib.h>
#include <stdio.h>
struct node {
    int  data;
    struct node *l, *r;
};
typedef struct node BTNode;
BTNode*p=NULL;
BTNode*insertBST(BTNode**T,int item);
void preBitree(BTNode* T);
int depth=1;//深度
int main()
{
	BTNode*p=NULL;
    int n,item;
    scanf("%d",&n);
    scanf("%d", &item);
    insertBST(&p, item);
    int i;
    for(i=1; i<n; i++)
	{ 
        scanf("%d", &item);
        insertBST(&p, item);
    }
    preBitree(p);
    return 0;
}
BTNode*insertBST(BTNode**T,int item)//二叉排序树的建立
{
    if(*T== NULL)
	{
        *T=(BTNode*)malloc(sizeof(BTNode));
        (*T)->data=item;
        (*T)->l=(*T)->r=NULL;
    }
    else if(item<(*T)->data)
        {
        	insertBST(&(*T)->l,item);
		}
    else if( item >= (*T)->data)
        insertBST(&(*T)->r,item);
}
void preBitree(BTNode*T)//前序遍历
{
    if(T==NULL)
    {
        return;
    }
    else;
    {
        if(T->l==NULL&&T->r==NULL)
        printf("%d %d\n", T->data,depth);
        depth++;
        preBitree(T->l);
        preBitree(T->r);
        depth--;
    }
}

