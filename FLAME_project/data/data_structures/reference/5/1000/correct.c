#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX(A,B) ((A>B)?A:B)
#define MIN(A,B) ((A>B)?B:A)
typedef struct xishu
{
    int a,ind;
    struct xishu *nxt;
}XS;
typedef struct Node
{   
    struct Node *left,*right;
    int height,a,ind; 
}BT;

BT* NewNode(int a,int ind)
{
    BT* node =( BT* ) malloc (sizeof(BT));
    node->a=a;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    node->ind=ind;
    return node;
}

int hi(BT* node)
{
    if(node==NULL) return 0;
    return node->height;
}

void push_up(BT *node)
{
	node->height=1+MAX(hi(node->left),hi(node->right));
	return;
}

int get_bal(BT* node)
{
    if(node==NULL) return 0;
    return hi(node->left)-hi(node->right);
}

BT* ll_rotate(BT* y)
{
    BT* x=y->left;
    y->left=x->right;
    x->right=y;
    push_up(y);
    push_up(x);
    return x;
}

BT* rr_rotate(BT* y)
{
    BT* x=y->right;
    y->right=x->left;
    x->left=y;
    push_up(y);
    push_up(x);
    return x;
}

BT* AVL(BT* node)
{
    int bal=get_bal(node);
    if(bal>1)
    {
        if(get_bal(node->left)<0) node->left=rr_rotate(node->left);
        return ll_rotate(node);
    }
    else if(bal<-1)
    {
        if(get_bal(node->right)>0) node->right=ll_rotate(node->right);
        return rr_rotate(node);
    }
    push_up(node);
    return node;
}

BT* insert(BT* node,int a,int ind)
{
    if(node==NULL) return NewNode(a,ind);
    if(ind<node->ind) node->left=insert(node->left,a,ind);
    else if(ind>node->ind) node->right= insert(node->right,a,ind);
    else 
    {
        node->a=node->a+a;
        return node;
    }
    node=AVL(node);
    return node;
}

void dfs_free(BT *node)
{
	if(node==NULL) return;
	dfs_free(node->left);dfs_free(node->right);
	node->left=NULL;node->right=NULL; 
 	free(node);
	return;
}

XS *insert_lian(XS *pos,int a,int ind)
{
    if(pos==NULL)
    {
        pos=(XS *)malloc(sizeof(XS));
        pos->a=a;pos->ind=ind;
        pos->nxt=NULL;
        return pos;
    }
    pos->nxt=insert_lian(pos->nxt,a,ind);
    return pos->nxt;
}

void fre(XS *st1)
{
    if(st1->nxt==NULL) 
    {
        free(st1);
        return ;
    } 
    fre(st1->nxt);
    free(st1);
    return;
}

void dfs(BT* root)
{
    if(root==NULL) return; 
    dfs(root->right);
    printf("%d %d ",root->a,root->ind);
    dfs(root->left);
    return;
}

int main()
{
    XS *now=NULL,*cnt=NULL,*st1=NULL,*st2=NULL;
    BT *root=NULL;
    int a,in;
    char c;
    scanf("%d%d%c",&a,&in,&c);
    while(1)
    {
        now=insert_lian(now,a,in);
        if(st1==NULL) st1=now;
        if(c=='\n') break;
        scanf("%d%d%c",&a,&in,&c);
    }
    now=NULL;
    scanf("%d%d%c",&a,&in,&c);
    while(1)
    {
        now=insert_lian(now,a,in);
        if(st2==NULL) st2=now;
        if(c=='\n') break;
        scanf("%d%d%c",&a,&in,&c);
    }
    for(now=st1;now!=NULL;now=now->nxt)
    {
        for(cnt=st2;cnt!=NULL;cnt=cnt->nxt)
        {
            root=insert(root,now->a*cnt->a,now->ind+cnt->ind); 
        }
    }
    dfs(root);
    dfs_free(root);
    fre(st1);fre(st2);
    return 0;
}
