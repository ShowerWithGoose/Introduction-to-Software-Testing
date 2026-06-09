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
        root->left=root->right=NULL; // @@ 创建节点后缺少return，导致继续执行后续if语句造成无限递归
    }
    if(a<root->num){
        dqshendu++;
        root->left=insert(root->left,a,dqshendu);
    }else if(a>=root->num){
        dqshendu++;
        root->right=insert(root->right,a,dqshendu);
    }
    return root;
}

ecs zhongxubianli(ecs* root){ // @@ 函数返回类型应为void，当前返回类型导致未定义行为
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