#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

//typedef int Datatype;
struct Tree {
    int data;
    struct Tree *left, *right;
};
typedef struct Tree BTNode, *BTNodeptr;
int num=1;
BTNodeptr root = NULL;
BTNodeptr  insertBST(BTNodeptr p, int item)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
    } 
    else if( item < p->data)
        p->left = insertBST(p->left, item);
    else if( item > p->data|| item==p->data)
        p->right = insertBST(p->right,item);
    
    return p;
} 
void  inorder(BTNodeptr t)
{
    if(t!=NULL){
        if(t->left==NULL&&t->right==NULL)
            printf("%d %d\n", t->data, num);
        num++;
        inorder(t->left);
        
        inorder(t->right);
        num--;
       }
}

int main(){
    int n,i,e;
    
    scanf("%d", &n);
    //建立树
    for (i = 0; i < n; i++){
        scanf("%d", &e);
        root=insertBST(root,e);
    }
    //遍历
    inorder(root);
    
    return 0;
}
