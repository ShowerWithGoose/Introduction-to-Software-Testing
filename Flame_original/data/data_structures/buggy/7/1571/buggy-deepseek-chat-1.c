#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define maxn 1005

struct node{
    int data;
    struct node *lchild,*rchild;
}node; // @@ [Error: 'node' is declared as a variable of type struct node, but then used as a type name in malloc(sizeof(node)). This causes a compilation error because 'node' is not a type. It should be 'struct node' or a typedef should be used properly.]
typedef struct node*nptr;

nptr insert(nptr p,int item){
    if(p==NULL){
        p=(nptr)malloc(sizeof(node)); // @@ [Error: 'node' is a variable, not a type. sizeof(node) is invalid because node is not a type. It should be sizeof(struct node).]
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
    leaf(root,1);//输出叶子结点
     

    return 0;
}