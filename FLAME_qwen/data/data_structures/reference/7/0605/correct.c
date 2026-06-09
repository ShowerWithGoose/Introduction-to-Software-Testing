#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode* Tree;

struct TreeNode{
    int num;
    int depth;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct stack{
    int top;
    Tree* tree;
} Stack;

Stack* MakeTree()
{
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->tree = (Tree*)malloc(100*sizeof(Tree));
    S->top = -1;
    return S;
}

void Push(Stack* S,Tree x)
{
    if(S->top<100){
    S->top++;
    S->tree[S->top] = x;}
}

Tree Pop(Stack* S){
    if(S->top!=-1){
        return S->tree[S->top--];
    }
}

Tree Getop(Stack* S){
    if(S->top!=-1){
        return S->tree[S->top];
    }
}

void middleprint(Tree T)
{
    Stack* S = MakeTree();
    Tree temp = T;
    while(temp!=NULL||S->top!=-1){
        while(temp){
            Push(S,temp);
            temp = temp->left;
        }
        temp = Pop(S);
        printf("<%d %d>",temp->num,temp->depth);
        temp = temp->right;
    }
}//中序遍历

void frontprint(Tree T)
{
     Stack* S = MakeTree();
    Tree temp = T;
    while(temp!=NULL||S->top!=-1){
        while(temp){
            printf("<%d %d>",temp->num,temp->depth);
            Push(S,temp);
            temp = temp->left;
        }
        temp = Pop(S);
        temp = temp->right;
    }
}//先序遍历

void rearprint(Tree T)
{
    Stack* S = MakeTree();
    Tree temp = T;
    Tree exam = (Tree)malloc(sizeof(Tree));
    exam = NULL;
    while(temp!=NULL||S->top!=-1){
        while(temp!=NULL){
            Push(S,temp);
            temp = temp->left;
        }
        temp = Getop(S);
        if(temp->right==NULL||temp->right==exam){
            printf("<%d %d>",temp->num,temp->depth);
            exam = Pop(S);
            temp = NULL;
        }
        else {
            temp = temp->right;
        }
    }
}//后序遍历


struct TreeNode* MakeEmpty(struct TreeNode* T)
{
    if(T!=NULL){
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    else return NULL;
}
struct TreeNode* Insert(int x,struct TreeNode* T)
{
    int d = 1;
    struct TreeNode* temp = T;
     while(temp!=NULL){
       if(temp->left==NULL&&temp->right==NULL){
           if(x < temp->num){
               struct TreeNode* new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
               new->depth = temp->depth+1;
               new->num = x;
               new->left = NULL;
               new->right = NULL;
               temp->left =new;
               return T;
           }
           else if(x >= temp->num){
                struct TreeNode* new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
               new->depth = temp->depth+1;
               new->num = x;
               new->left = NULL;
               new->right = NULL;
               temp->right =new;
               return T;
           }
        
       }
       else if(temp->left!=NULL&&temp->right!=NULL){
           if(x < temp->num){
               temp = temp->left;
               continue;
           } 
           else if(x >= temp->num){
               temp = temp->right;
               continue;
           }
        

       }
       else {
           if(temp->left!=NULL){
               if(x >= temp->num){
                   struct TreeNode* new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
               new->depth = temp->depth+1;
               new->num = x;
               new->left = NULL;
               new->right = NULL;
               temp->right =new;
               return T;
               }
              else {temp = temp->left;
               continue;}
           }
           else if(temp->right!=NULL){
               if(x < temp->num){
                    struct TreeNode* new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
               new->depth = temp->depth+1;
               new->num = x;
               new->left = NULL;
               new->right = NULL;
               temp->left =new;
               return T;
               }
               else{temp = temp->right;
               continue;}
           }
       }
    }
}

void Print(struct TreeNode* T)
{ if(T!=NULL){
   if(T->left==NULL&&T->right==NULL){
    printf("%d %d\n",T->num,T->depth);}
   if(T->left) Print(T->left);
   if(T->right) Print(T->right);
}

}  //输出叶结点



int main()
{
    int n,i;
    scanf("%d",&n);
    int *treenum = (int*)malloc(n*sizeof(int));
    for(i = 0;i < n;i++){
        scanf("%d",&treenum[i]);
    }
    struct TreeNode* T = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    T->depth = 1;
    T->num = treenum[0];
    T->left = NULL;
    T->right = NULL;
    for(i = 1;i < n;i++){
        Insert(treenum[i],T);
    }
   /* void (*print[])(Tree) = {middleprint,frontprint,rearprint,Print};
   for(i = 0;i < 4;i++){
     (*print[i])(T);
     printf("\n");  
   }*/
   Print(T);
    return 0;
}
