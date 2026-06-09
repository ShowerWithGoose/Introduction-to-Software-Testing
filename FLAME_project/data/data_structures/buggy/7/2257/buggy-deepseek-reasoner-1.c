#include<stdio.h>
#include<stdlib.h>
typedef int BSTElemType;

typedef int(*CompareBSTElemType)(BSTElemType e1,BSTElemType e2);

CompareBSTElemType CmpBST;

typedef struct BSTNode
{
    BSTElemType data;
    
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

BSTree CreateBSTByInput();
BSTree InsertBST(BSTree T,BSTElemType e);
BSTree InsertBST_NoRepeat(BSTree T,BSTElemType e);
void  PrintTree(BSTree T);
BSTree SearchBST(BSTree T,BSTElemType e);
void SetupBSTCmpFunc(CompareBSTElemType cmp);
void  PrintBSTWithDepth(BSTree T,int depth);
void PreOrderTraverseBST(BSTree T,void(*Visit)(BSTNode T));
void InOrderTraverseBST(BSTree T,void(*Visit)(BSTNode T));
void PostOrderTraverseBST(BSTree T,void(*Visit)(BSTNode T));
void PreOrderTraverseBSTD(BSTree T,int Depth,void(*Visit)(BSTNode T,int depth));
void InOrderTraverseBSTD(BSTree T,int Depth,void(*Visit)(BSTNode T,int depth));
void PostOrderTraverseBSTD(BSTree T,int Depth,void(*Visit)(BSTNode T,int depth));

void print(BSTNode T,int depth){
    if(T.lchild==NULL&&T.rchild==NULL)
        printf("%d %d\n",T.data,depth);}

int main(){

    int n=0;
    scanf("%d",&n);
    BSTree T=NULL;int data;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&data);T=InsertBST(T,data);
    }
    

    PreOrderTraverseBSTD(T,0,print); // @@ initial depth should be 1 instead of 0 because root height is 1
    system("pause");
    return 0;
}

BSTree CreateBSTByInput(){

    BSTree T=NULL;
    int data;
    while(scanf("%d",&data)!=EOF){
        T=InsertBST(T,data);
    }
    return T;
}

BSTree InsertBST(BSTree T,BSTElemType e){
    if(T==NULL){
        T=(BSTree)malloc(sizeof(BSTNode));
        T->data=e;
        T->lchild=T->rchild=NULL;
    }
    else if(e<T->data)
        T->lchild=InsertBST(T->lchild,e);
    else 
        T->rchild=InsertBST(T->rchild,e);
    return T;
}

BSTree InsertBST_NoRepeat(BSTree T,BSTElemType e){
    if(T==NULL){
        T=(BSTree)malloc(sizeof(BSTNode));
        T->data=e;
        T->lchild=T->rchild=NULL;
    }
    else if(e<T->data)
        T->lchild=InsertBST(T->lchild,e);
    else if(e>T->data)
        T->rchild=InsertBST(T->rchild,e);
    return T;
}

void PrintBST(BSTree T){
    if(T){
        PrintBST(T->lchild);
        printf("%d ",T->data);
        PrintBST(T->rchild);
    }
}

void  PrintBSTWithDepth(BSTree T,int depth){
    if(T){
        PrintBSTWithDepth(T->rchild,depth+1);
        for(int i=0;i<depth;i++)
            printf("    ");
        printf("%d\n",T->data);
        PrintBSTWithDepth(T->lchild,depth+1);
    }
}

BSTree SearchBST(BSTree T,BSTElemType e){
    if(!T||!CmpBST(T->data,e))
        return T;
    if(CmpBST(e,T->data)<0)
        return SearchBST(T->lchild,e);
    else
        return SearchBST(T->rchild,e);
}

void SetupBSTCmpFunc(CompareBSTElemType cmp){
    CmpBST=cmp;
}


void PreOrderTraverseBST(BSTree T,void(*Visit)(BSTNode T)){
    if(T){
        Visit(*T);
        PreOrderTraverseBST(T->lchild,Visit);
        PreOrderTraverseBST(T->rchild,Visit);
    }
}

void InOrderTraverseBST(BSTree T,void(*Visit)(BSTNode T)){
    if(T){
        InOrderTraverseBST(T->lchild,Visit);
        Visit(*T);
        InOrderTraverseBST(T->rchild,Visit);
    }
}

void PostOrderTraverseBST(BSTree T,void(*Visit)(BSTNode T)){
    if(T){
        PostOrderTraverseBST(T->lchild,Visit);
        PostOrderTraverseBST(T->rchild,Visit);
        Visit(*T);
    }
}

void PreOrderTraverseBSTD(BSTree T,int Depth,void(*Visit)(BSTNode T,int depth)){
    if(T){
        Visit(*T,Depth);
        PreOrderTraverseBSTD(T->lchild,Depth+1,Visit);
        PreOrderTraverseBSTD(T->rchild,Depth+1,Visit);
    }
}

void InOrderTraverseBSTD(BSTree T,int Depth,void(*Visit)(BSTNode T,int depth)){
    if(T){
        InOrderTraverseBSTD(T->lchild,Depth+1,Visit);
        Visit(*T,Depth);
        InOrderTraverseBSTD(T->rchild,Depth+1,Visit);
    }
}

void PostOrderTraverseBSTD(BSTree T,int Depth,void(*Visit)(BSTNode T,int depth)){
    if(T){
        PostOrderTraverseBSTD(T->lchild,Depth+1,Visit);
        PostOrderTraverseBSTD(T->rchild,Depth+1,Visit);
        Visit(*T,Depth);
    }
}