#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;
    int high;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;
BTNodeptr root=NULL;
int a[100];
int saveh=0,mark=0;
void insertBST(int item){
    BTNodeptr p,q;
    p=(BTNodeptr)malloc(sizeof(BTNode));
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL){
        root=p;
        root->high=1;
    }
    else{
        root->high=1;
        q=root;
        while(1){//比较值的大小。小于向左，大于向右。
            if(item < q->data){
                if(q->left==NULL){
                    saveh=q->high;
                    q->left=p;//插入
                    p->high=saveh+1;
                    break;
                }
                else{
                    saveh=q->high;
                    q=q->left;//还没到底
                    q->high=saveh+1;
                }
            }
            else if(item >= q->data){
                if(q->right==NULL){
                    saveh=q->high;
                    q->right=p;
                    p->high=saveh+1;
                    break;
                }
                else{
                    saveh=q->high;
                    q=q->right;
                    q->high=saveh+1;
                }
            }
        }
    }
}
void sorttree(int k[],int n){//用n个数据建立树
    int i;
    for(i=0;i<n;i++)
        insertBST(k[i]);
}
void inorder(BTNodeptr t){//中序遍历
    if(t!=NULL){
        inorder(t->left);
        if(t->left==NULL && t->right==NULL)
            printf("%d %d\n",t->data,t->high);
        inorder(t->right);
    }
}
int main(){
    int m,i;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    //root->high=1;
    sorttree(a,m);
    inorder(root);
    return 0;
}
