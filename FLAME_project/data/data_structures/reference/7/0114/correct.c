//二叉查找树的基本构造方法与遍历
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    struct node* left;
    struct node* right;
    int data;
    int high;
};

struct node *root=NULL;

void insert(int num){
    struct node *p,*q;
    p=(struct node *)malloc(sizeof(struct node));
    p->left=NULL;
    p->right=NULL;
    p->data=num;
    p->high=1;
    if(root==NULL)  root=p;
    else{
        q=root;
        while(1){
            if(num<q->data){
                p->high++;
                if(q->left==NULL) {q->left=p; break;}
                else q=q->left;
            }
            else{
                p->high++;
                if(q->right==NULL) {q->right=p; break;}
                else q=q->right;
            }
        }
    }
}

void check(struct node *t){
    if(t!=NULL){
        if(t->left==NULL&&t->right==NULL){
            printf("%d %d\n",t->data,t->high);
            return;
        }
        check(t->left);
        check(t->right);
    }
}

int main(){
    int n,i;
    int num;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        insert(num);
    }
    check(root);
    return 0;
}
