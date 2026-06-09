#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define N 1005
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
typedef long long ll;
int read();
typedef struct Treenode
{
    int val;
    struct Treenode *left;
    struct Treenode *right;
    int dep;
} Tree,*tree;
void insert(tree *p,int m,int d)
{
    if(*p==NULL)
    {
    *p=(tree)malloc(sizeof(Tree));
    (*p)->left=(*p)->right=NULL;
    (*p)->val=m;
    (*p)->dep=d;
    }
    else if(m<(*p)->val)
    insert(&((*p)->left),m,d+1);
    else
    insert(&((*p)->right),m,d+1);
}
void order(tree p)
{
    if(p!=NULL)
    {
        order(p->left);
        if(p->left==NULL&&p->right==NULL)
        printf("%d %d\n",p->val,p->dep);
        order(p->right);
    }
    
}
int main()
{
int n;
int i;
int m;
tree r=NULL;
scanf("%d",&n);
for(i=0;i<n;i++)
{
 scanf("%d",&m);
 insert(&r,m,1);
}   
order(r);
return 0;
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}


