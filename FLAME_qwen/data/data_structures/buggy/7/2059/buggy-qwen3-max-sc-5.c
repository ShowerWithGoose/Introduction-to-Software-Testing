#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct ecs{
    int num;
    int gaodu;
    struct ecs *left;
    struct ecs *right;    
}ecs;
int shendu=1;
ecs *insert(struct ecs *root,int a,int dqshendu){
    if(root==NULL){
        root=(ecs*)malloc(sizeof(ecs));
        root->num=a;
        root->gaodu=dqshendu;
        root->left=root->right=NULL;
    }
    if(a<root->num){
        dqshendu++;
        root->left=insert(root->left,a,dqshendu);
    }else if(a>=root->num){
        dqshendu++;
        root->right=insert(root->right,a,dqshendu);
    }
    return root;
} // @@ [The function does not handle the case when root is not NULL and both recursive calls are skipped (e.g., when a == root->num and right subtree already exists), leading to potential infinite recursion or incorrect tree structure. Also, the logic for updating depth is flawed because dqshendu is passed by value, so increments in deeper calls don't affect parent calls.]

ecs zhongxubianli(ecs* root){
    if(root!=NULL){
        zhongxubianli(root->left);
        if(root->left==NULL&&root->right==NULL)
        printf("%d %d\n",root->num,root->gaodu);
        zhongxubianli(root->right);
    }
} // @@ [Function return type is 'ecs' but it should be 'void' since it doesn't return anything. This causes a compilation error.]

int main(){
    int a;
    int n;
    ecs *root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        shendu=1;
        root=insert(root,a,shendu);
    }
    zhongxubianli(root);
}