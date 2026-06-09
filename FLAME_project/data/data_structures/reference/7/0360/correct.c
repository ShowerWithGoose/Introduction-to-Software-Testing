#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define false 0
#define true 1
typedef int bool;

typedef struct node{
    int num;
    int height;
    struct node *left,*right;
}node,*bitree;

bitree searchtree=NULL;
int nums,numsSize;

bitree insert(int x,bitree p,int h){
    if(p==NULL){
        p=(bitree)malloc(sizeof(node));
//        printf("%d %d\n",x,h);
        p->num=x;
        p->height=h;
        p->left=p->right=NULL;
    }
    else if(x<p->num)
        p->left=insert(x,p->left,h+1);
    else if(x>=p->num)
        p->right=insert(x,p->right,h+1);
    return p;
}

void inorderTraversal(bitree root){
    bitree stack[100];
    int top=-1,pa=0;
    bitree p=root;
    while(top!=-1||p){
        while(p!=NULL){
            stack[++top]=p;
            p=p->left;
        }
        p=stack[top--];
        if(p->right==NULL&&p->left==NULL)
            printf("%d %d\n",p->num,p->height);
        p=p->right;
    }
   
}

int main(){
    int i;
    scanf("%d\n",&numsSize);
    scanf("%d",&nums);
    searchtree=(bitree)malloc(sizeof(node));
    searchtree->height=1;
    searchtree->num=nums;
    searchtree->left=searchtree->right=NULL;
    for(i=1;i<numsSize;i++){
        scanf("%d",&nums);
        insert(nums,searchtree,1);
    }
    inorderTraversal(searchtree);
    return 0;
}
