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
        // Missing return statement; function continues to comparison and recursive insert, causing logical error.
    } // @@ Missing return after creating node; should return root immediately.
    if(a<root->num){
        dqshendu++; // @@ Post‑increment passes current depth, not incremented depth; should be dqshendu + 1 or ++dqshendu.
        root->left=insert(root->left,a,dqshendu);
    }else if(a>=root->num){
        dqshendu++; // @@ Same issue: post‑increment passes wrong depth.
        root->right=insert(root->right,a,dqshendu);
    }
    return root;
}

ecs zhongxubianli(ecs* root){ // @@ Function declared to return ecs but has no return statement; should be void.
    if(root!=NULL){
        zhongxubianli(root->left);
        if(root->left==NULL&&root->right==NULL)
        printf("%d %d\n",root->num,root->gaodu);
        zhongxubianli(root->right);
    }
}
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