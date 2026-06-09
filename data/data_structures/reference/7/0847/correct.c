#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef int Datatype;
struct node{
    Datatype data;
    struct node *left,*right;
    Datatype high;
};
typedef struct node BTNode, *BTNodeptr;
int high=1;

BTNodeptr insertBST(BTNodeptr p,Datatype item,Datatype high)
{
    if(p==NULL){
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->data=item;
        p->left=p->right=NULL;
        p->high=high;
    }
    else if(item<p->data)
        p->left=insertBST(p->left,item,high+1);
    else if(item>=p->data)
       p->right=insertBST(p->right,item,high+1);

    return p;
} 

void print(BTNodeptr t)
{
    if(t!=NULL){
        print(t->left);
        if(t->left==NULL&&t->right==NULL) printf("%d %d\n",t->data,t->high);
        print(t->right);
    }
}

int main()
{
    int i,n,item;
    BTNodeptr root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&item);
        root=insertBST(root,item,high);
    }
    print(root);
    return 0;
}



