#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int level;
typedef int Datatype;
typedef struct node{
    Datatype data;
    Datatype h;
    struct node *left,*right;
}BSTNode,*PBSTNode;
void visit(int data,int level){
    printf("%d %d\n",data,level);
}
void PreOrderTraverse(PBSTNode T,int level){
if(T){
    if(T->left==NULL&&T->right==NULL){
        visit(T->data,level);
    }
    PreOrderTraverse(T->left,level+1);
    PreOrderTraverse(T->right,level+1);
}
}
PBSTNode Get(PBSTNode root,int temp)
{
    if(!root)
        return NULL;
    if(temp < root->data)
        return Get(root->left,temp);
    else
        return Get(root->right,temp);
}
void putin(PBSTNode *root,int temp){
    if(!(*root)){
        (*root) = (PBSTNode)malloc(sizeof(BSTNode));
        (*root)->h = 0;
        (*root)->data = temp;
        (*root)->left = (*root)->right = NULL;
        return;
    }
    PBSTNode Temp = (PBSTNode)malloc(sizeof(BSTNode));
    PBSTNode des = Get((*root),temp);
    if(des!=NULL){
        des->data = temp;
        return;
    }
    PBSTNode Go = (*root);
    while(Go){
        if(Go->data>temp){
            if(!Go->left){
                Temp->data = temp;
                Temp->left = Temp->right = NULL;
                Go->left = Temp;
                return;
            }
            else{
                Go = Go->left;
            }
        }
        else{
            if(!Go->right){
                Temp->data = temp;
                Temp->left = Temp->right = NULL;
                Go->right = Temp;
                return;
            }
            else{
                Go = Go->right;
            }
        }
    }
}
PBSTNode CBST(int data[],int n){
    PBSTNode Root = NULL;
    if(n==0){
        Root = NULL;
    }
    else{
        for(int i = 0;i < n;i++){
            putin(&Root,data[i]);
        }
        return Root;
    }
}
int main(){
    int n;
    level= 1;
    scanf("%d",&n);
    int dta[1000];
    for(int i = 0;i < n;i++){
        scanf("%d",&dta[i]);
    }
    PBSTNode T;
    T = CBST(dta,n);
    PreOrderTraverse(T,level);
    return 0;
}


