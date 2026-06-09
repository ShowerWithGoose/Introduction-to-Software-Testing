#include<stdio.h>
#include<stdlib.h>
#define MAX( x, y ) (((x) > (y)) ? (x) : (y))

typedef struct TNode *Tree;
struct TNode{
    int data;
    int height;
    Tree left,right;
};
Tree S=NULL;
Tree pre=NULL;
Tree InsertTree(Tree p,int num){
    if(p==NULL){
        p=(Tree)malloc(sizeof(struct TNode));
        p->data=num;
        if(pre!=NULL) p->height=pre->height+1;
        else p->height=1;
        p->left=p->right=NULL;
    }
    else if(num<p->data){
        pre=p;
        p->left=InsertTree(p->left,num);
    }
    else if(num>=p->data){
        pre=p;
        p->right=InsertTree(p->right,num);
    }
    return p;
}
// int HeightTree(Tree p){
//     if(p==NULL) return 0;
//     else return 1+MAX(HeightTree(p->left),HeightTree(p->right));
// }
void Inorder(Tree p){  //中序遍历
    int height;
    if(p!=NULL){
        Inorder(p->left);
        if(p->left==NULL&&p->right==NULL){
            //height=get_height(p);
            printf("%d %d\n",p->data,p->height);
        }
        Inorder(p->right);
    }
}

int main(){
    int N,i,num;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&num);
        S=InsertTree(S,num);
    }
    Inorder(S);
    system("pause");
    return 0;
}

