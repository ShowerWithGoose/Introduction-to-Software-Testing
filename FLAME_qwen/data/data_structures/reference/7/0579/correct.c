#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data,height;
   struct node *left,*right;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;
BTNodeptr root=NULL;
void insertBST(int);  //BST的插入算法
void perorder(BTNodeptr);  //前序遍历

int main(){
    int n,item;
    scanf("%d",&n);
    while(n--){  //建立一棵BST
        scanf("%d",&item);
        insertBST(item);
    }
    perorder(root);
    return 0;
}

void insertBST(int item)
{
    int h=2;
    BTNodeptr p,q;
    p=(BTNodeptr)malloc(sizeof(BTNode));
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL){
        root=p;
        root->height=1;
    }
    else{
        q=root;  //从root开始比较
        while(1){
            if(item<q->data){
                if(q->left==NULL){  
                    p->height=h;
                    q->left=p;
                    break;
                }
                else{
                    q=q->left;
                }
            }
            else{
                if(q->right==NULL){
                    p->height=h;
                    q->right=p;
                    break;
                }
                else{
                    q=q->right;
                }
            }
            h++;
        }
    }
}

void perorder(BTNodeptr t)
{
    if(t!=NULL){  
        if(t->left==NULL&&t->right==NULL)//叶结点
        {
            printf("%d %d\n",t->data,t->height);
        }
        perorder(t->left);
        perorder(t->right);
    }
}


