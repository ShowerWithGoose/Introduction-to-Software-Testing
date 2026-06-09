#include<stdio.h>
#include<malloc.h>
#define MAX 100
typedef struct node{
    int data,layer;
    struct node* lchild;
    struct node* rchild;
}TREE,*TREELINK;
TREELINK BST_Insert(TREELINK *T,int item,int *l){
    if(*T==NULL){
        *T=(TREELINK)malloc(sizeof(TREE));
        (*T)->data=item;
        (*T)->layer=*l+1;
        (*T)->lchild=NULL;
        (*T)->rchild=NULL;
    }
    else if(item<(*T)->data){
        (*l)++;
        BST_Insert(&((*T)->lchild),item,l);
    }
    else{
        (*l)++;
        BST_Insert(&((*T)->rchild),item,l); 
    }
}
TREELINK Build_Sorttree(int A[],int a){
    int i;
    int l;
    TREELINK T=NULL;
    for(i=0;i<a;i++){
        l=0;
        BST_Insert(&T,A[i],&l);
    }
    return T;
}
void Visit(TREELINK T){
    if(T->lchild==NULL&&T->rchild==NULL)
        printf("%d %d\n",T->data,T->layer);
}
void In_Order1(TREELINK T){
    if(T!=NULL){
        In_Order1(T->lchild);
        Visit(T);
        In_Order1(T->rchild);
    }
}
//can get leaf`s layer too
/*int BT_Layer(TREELINK T){
    TREELINK Stack1[MAX]={},p=T;
    int Stack2[MAX]={},top=-1,t;
    if(T!=NULL){
        do{
            while(p!=NULL){
                Stack1[++top]=p;
                Stack2[top]=0;
                p=p->lchild;
            }
            p=Stack1[top];
            t=Stack2[top--];
            if(t==0){
                Stack1[++top]=p;
                Stack2[top]=1;
                p=p->rchild;
            }
            else{
                if(p->rchild==NULL&&p->lchild==NULL)
                    printf("%d %d\n",p->data,top+2);
                p=NULL;
            }
        }while(p!=NULL||top!=-1);
    }
}*/
void BT_Destory(TREELINK *T){
    if((*T)!=NULL){
        BT_Destory(&((*T)->lchild));
        BT_Destory(&((*T)->rchild));
        free(*T);
        (*T)=NULL;
    }
}
int main(){
    TREELINK ST;
    int A[MAX]={},a;
    int i;
    scanf("%d",&a);
    for(i=0;i<a;i++)
        scanf("%d",&A[i]);
    ST=Build_Sorttree(A,a);
    In_Order1(ST);
    BT_Destory(&ST);
}
