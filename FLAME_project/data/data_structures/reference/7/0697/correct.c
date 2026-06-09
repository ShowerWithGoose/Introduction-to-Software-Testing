#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int x,dep;
    struct NODE *lc,*rc;
}BST;
BST *Tr;
BST* newnode(){BST *re=(BST*)malloc(sizeof(BST));re->lc=NULL;re->rc=NULL;re->x=0;re->dep=0;return re;}
void insert(BST *p,int x,int dep)
{
    if(p->dep==0){p->x=x;p->dep=dep;return;}
    if(x< p->x){if(p->lc==NULL)p->lc=newnode();insert(p->lc,x,dep+1);}
    if(x>=p->x){if(p->rc==NULL)p->rc=newnode();insert(p->rc,x,dep+1);}
}
void dfs(BST *p)
{
    if(p->lc==NULL&&p->rc==NULL){printf("%d %d\n",p->x,p->dep);return;}
    if(p->lc!=NULL)dfs(p->lc);
    if(p->rc!=NULL)dfs(p->rc);
}
int n;

signed main()
{
    // freopen("data.in","r",stdin);
    
    scanf("%d",&n);
    int x;Tr=newnode();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        insert(Tr,x,1);
    }
    dfs(Tr);
}
