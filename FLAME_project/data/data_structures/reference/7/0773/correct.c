#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long
#define For(a, b, c) for (int a = b; a < c;a++)
#define FOR(a, b, c) for (int a = c - 1; a >= b;a--)
#define ull unsigned long long
#define MAXN 1000000
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
struct node{
    int  data;
    struct  node *left,*right;
    int depth;    
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
BTNodeptr root=NULL;
void visit(BTNodeptr t){
    printf("%d %d\n",t->data,t->depth);
}
BTNodeptr insert(BTNodeptr t,int data,int depth){
    if(t==NULL){
        t=(BTNodeptr)malloc(sizeof(BTNode));
        t->left=t->right=NULL;
        t->data=data;
        t->depth=depth;
    }
    else if(t->data<=data) t->right=insert(t->right,data,depth+1);
    else t->left=insert(t->left,data,depth+1);
    return t;
}
void inorder(BTNodeptr t){
    if(t!=NULL){
        inorder(t->left);
        if(t->left==NULL&&t->right==NULL) visit(t);
        inorder(t->right);
    }
}
int main()
{
    int n,item;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&item);
        root=insert(root,item,1);
    }
    inorder(root);
    return 0;
}
