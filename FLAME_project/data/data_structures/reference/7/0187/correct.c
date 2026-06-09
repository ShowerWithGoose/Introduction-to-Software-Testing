#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct BiTNode BiTNode;
typedef struct BiTNode* BiTree;
typedef int ElemType;
struct BiTNode  //结点结构
{
    ElemType data,hang;
    BiTree lchild,rchild; //左右孩子指针
};
void CreatBiTree(BiTree *T,int k,int hang)
{
    if(*T==NULL){
        (*T)=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=k;
        (*T)->lchild=NULL;
        (*T)->rchild=NULL;
        (*T)->hang=hang;
    }
    else{
        if(k<(*T)->data)
           CreatBiTree(&(*T)->lchild,k,++hang);
        else  
           CreatBiTree(&(*T)->rchild,k,++hang);
    }
}
int BiTreeDepth(BiTree T) //二叉树的深度
{
    int i=0,j=0;
    if(!T) return 0;
    i=BiTreeDepth(T->lchild);
    j=BiTreeDepth(T->rchild);
    if(i>=j) return i+1;
    else return j+1;
}
void PreOrderTraverse(BiTree T)// 二叉树的先序遍历
{
    if(T==NULL) 
        return ;
    if(BiTreeDepth(T)==1)
    printf("%d %d\n",T->data,T->hang);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
int a[10000];
BiTree T=NULL;
int main()
{
    int n,hang=1;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        CreatBiTree(&T,a[i],hang);
    }
    PreOrderTraverse(T);
}


