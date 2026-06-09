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
    if(a<root->num){ // @@ [Error: After allocating a new node, root is not NULL, so this condition will be checked even for the new node, causing undefined behavior. Should use 'else if' to avoid checking after NULL case.]
        dqshendu++;
        root->left=insert(root->left,a,dqshendu);
    }else if(a>=root->num){
        dqshendu++;
        root->right=insert(root->right,a,dqshendu);
    }
    return root;
}

ecs zhongxubianli(ecs* root){ // @@ [Error: Function return type is 'ecs' (a struct) but no value is returned. Should be 'void'.]
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