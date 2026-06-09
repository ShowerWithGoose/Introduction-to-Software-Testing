#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define maxn 1005

struct node{
    int data;
    struct node *lchild,*rchild;
}node; // @@ [This line defines a global variable named 'node' of type 'struct node', which shadows the type name and causes confusion. It should be removed or renamed. Also, the typedef below uses 'nptr' as pointer to 'struct node', but having a global variable with same name as struct can lead to compilation issues in some contexts.]

typedef struct node*nptr;

nptr insert(nptr p,int item){
    if(p==NULL){
        p=(nptr)malloc(sizeof(struct node)); // @@ [Should use 'struct node' instead of 'node' for clarity and correctness, though it may compile due to the global variable. However, better practice is to use the struct tag.]
        p->data=item;
        p->lchild=p->rchild=NULL;
        return p;//把结点指针赋值给双亲的孩子指针 
    }
    else if(item<p->data)
        p->lchild=insert(p->lchild,item);
    else if(item>p->data)
        p->rchild=insert(p->rchild,item);
    //else 
    //    do-something;//树中存在该元素
    return p; 
}
void leaf(nptr p,int high){
    //打印叶子结点 
    if(p==NULL) return; // @@ [Missing null check at start of function. If root is NULL (e.g., n=0), calling leaf(NULL,1) will crash when accessing p->lchild. The reference program assumes non-empty tree, but problem doesn't guarantee n>0.]
    if(p->lchild==NULL&&p->rchild==NULL){
        printf("%d %d\n",p->data,high);
        return;
    } 
    if(p->lchild!=NULL){
        leaf(p->lchild,high+1);        
    }
    if(p->rchild!=NULL){
        leaf(p->rchild,high+1);
    }
    return;
}
int main()
{
    int n,item,i;
    nptr root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&item);
        root=insert(root,item);
    }
    if(root != NULL) // @@ [Missing check for empty tree. If n==0, root is NULL and calling leaf(root,1) leads to dereferencing NULL pointer.]
        leaf(root,1);//输出叶子结点
     

    return 0;
}