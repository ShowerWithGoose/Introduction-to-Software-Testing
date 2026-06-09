#include<stdio.h>
struct node{
    int data;
    struct node *left,*right;
};
typedef struct node BSTNode;
typedef struct node* BSTNodeptr;
BSTNodeptr insertBST(BSTNodeptr p,int item);
void inorder(BSTNodeptr p,BSTNodeptr root);
void operate(BSTNodeptr p,BSTNodeptr root);
int hight(BSTNodeptr root,BSTNodeptr p);
int main(){
    BSTNodeptr root = NULL;
    int n = 0,i = 0,item = 0;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&item);//get data;
        root = insertBST(root,item);//creat BSTtree;
    }

    inorder(root,root);

    return 0;
}

BSTNodeptr insertBST(BSTNodeptr p,int item){
    if(p==NULL){
        p = (BSTNodeptr)malloc(sizeof(BSTNode));
        p->data = item;
        p->left = p->right = NULL;
    }else if(item < p->data)
        p->left = insertBST(p->left,item);
    else if(item >= p->data)
        p->right = insertBST(p->right,item);

    return p;
}

void inorder(BSTNodeptr p,BSTNodeptr root){
    if(p!=NULL){
        if( p->left == NULL && p->right == NULL ){
            operate(p,root);
        }else{

            inorder(p->left,root);
            inorder(p->right,root);
        }
    }

}

void operate(BSTNodeptr p,BSTNodeptr root){
    int high = 0;
    high = hight(root,p);
    printf("%d %d\n",p->data,high);
}

int hight(BSTNodeptr root,BSTNodeptr p){
    BSTNodeptr t=root;
    int high = 0;
    while(t!=NULL){
        high++;
        if(t->data == p->data && t->left ==NULL &&t->right==NULL)
            break;
        else if(t->data > p->data)
            t = t->left;
        else if(t->data <= p->data)
            t = t->right;
    }
    return high;
}

