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
    int num;
    struct Treenode *left;
    struct Treenode *right;
    int dep;
} Tree,*tree;
void insert(tree *b,int m,int height)
{
    if(*b==NULL)
    {
    *b=(tree)malloc(sizeof(Tree));
    (*b)->left=(*b)->right=NULL;
    (*b)->num=m;
    (*b)->dep=height;
    }
    else if(m<(*b)->num)
    insert(&((*b)->left),m,height+1);
    else
    insert(&((*b)->right),m,height+1);
}
void order(tree b)
{
    if(b!=NULL)
    {
        order(b->left);
        if(b->left==NULL&&b->right==NULL)
        printf("%d %d\n",b->num,b->dep);
        order(b->right);
    }
    
}
int main()
{
int n;
int i;
int m;
tree gen=NULL;
scanf("%d",&n);
for(i=0;i<n;i++)
{
 scanf("%d",&m);
 insert(&gen,m,1);
}   
order(gen);
return 0;
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}


