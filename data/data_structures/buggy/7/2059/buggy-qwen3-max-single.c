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
} // @@ [The function does not handle the case where root is not NULL but both conditions (a < root->num and a >= root->num) lead to recursive calls without returning immediately after insertion; however, more critically, after creating a new node, the code continues to evaluate the 'if' conditions below, which may cause incorrect behavior. Also, the global variable 'shendu' is reset in main but not used correctly since depth is passed as parameter.]

ecs zhongxubianli(ecs* root){
    if(root!=NULL){
        zhongxubianli(root->left);
        if(root->left==NULL&&root->right==NULL)
        printf("%d %d\n",root->num,root->gaodu);
        zhongxubianli(root->right);
    }
} // @@ [Function return type is 'ecs' but it should be 'void' because it doesn't return any value. This causes a compilation error.]

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