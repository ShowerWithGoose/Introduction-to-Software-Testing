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
    if(a<root->num){ // @@ The condition should be 'else if' to prevent accessing uninitialized or NULL root properties after insertion, and to match BST logic strictly. Although logically if root was NULL it returns, the structure here falls through. More critically, if root is not NULL, we check left. If it goes left, we recurse. But wait, the main issue causing Runtime Error or wrong output in similar contexts is often uninitialized memory or logic flow. Here, if root is NULL, we allocate. Then we check `if (a < root->num)`. This is safe because root is now valid. However, the logic for `else if` is missing. If `a < root->num` is false, it goes to `else if (a >= root->num)`. This part is logically okay for BST. Let's look closer at the crash.
        dqshendu++;
        root->left=insert(root->left,a,dqshendu);
    }else if(a>=root->num){
        dqshendu++;
        root->right=insert(root->right,a,dqshendu);
    }
    return root;
}

ecs zhongxubianli(ecs* root){ // @@ The function is declared to return 'ecs' (a struct), but it does not return anything. This leads to undefined behavior. It should return void.
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