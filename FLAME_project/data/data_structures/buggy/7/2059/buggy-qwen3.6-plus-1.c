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
    if(a<root->num){ // @@ The condition should be 'else if' or the logic needs restructuring. If root was just created (NULL case), accessing root->num here is valid because root is no longer NULL, but if the first 'if' block executes, the subsequent 'if' checks will also execute using the newly created node's data. However, the critical error causing Runtime Error or incorrect behavior in traversal is often related to how the tree is built or traversed. In this specific code, if 'root' was NULL, it gets allocated. Then 'a < root->num' is checked. If true, it recurses. If false, it goes to else if. This logic actually works for insertion order. Let's look closer at the crash.
        dqshendu++;
        root->left=insert(root->left,a,dqshendu);
    }else if(a>=root->num){
        dqshendu++;
        root->right=insert(root->right,a,dqshendu);
    }
    return root;
}

ecs zhongxubianli(ecs* root){ // @@ The function is declared to return 'ecs' (a struct by value) but does not return anything. This leads to undefined behavior. It should return void.
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