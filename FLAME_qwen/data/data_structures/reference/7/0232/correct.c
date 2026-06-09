#include<stdio.h>
#include<stdlib.h>
struct Bst_{
    int item;
    struct Bst_* leftchild;
    struct Bst_* rightchild;
};
typedef struct Bst_ bst;
typedef struct Bst_* pbst;

pbst createBst(pbst root,int data){//要传就传结构体的指针！
    if(root==NULL){//malloc一个空间！
        root=(pbst)malloc(sizeof(bst));//看！给结构体赋值也是赋的指针！
        root->leftchild=NULL;
        root->rightchild=NULL;
        root->item=data;
        return root;
    }else if(data<root->item){
        root->leftchild=createBst(root->leftchild,data);
    }else{
        root->rightchild=createBst(root->rightchild,data);
    }
    return root;
}
void printBst(int height,pbst root){
    if(root==NULL)
        return;
    if(root->leftchild!=NULL) printBst(height+1,root->leftchild);
    if(root->leftchild==NULL&&root->rightchild==NULL){
        printf("%d %d\n",root->item,height);
        return;
    }
    if(root->rightchild!=NULL) printBst(height+1,root->rightchild);
}
int main()
{
    pbst root=NULL;//只有指针初值可以赋为NULL，否则还不对！
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++){//好！不必编入数组！直接一边输入一边建树即可，建树的时候再申请空间！
        scanf("%d",&data);
        root= createBst(root,data);
    }
    printBst(1,root);
    return 0;
}

