#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct tree{
    int value;
    int depth;
    struct tree *left,*right;
}T,*Tp;
int D=1;
Tp root=NULL;
void Insert(Tp *p,int a)
{
    if(*p==NULL)
    {
        *p=(Tp)malloc(sizeof(Tp));
        (*p)->left=NULL;
        (*p)->right=NULL;
        (*p)->value=a;
        (*p)->depth=D;
    }
    else if(a<(*p)->value)
    {
        D++;
        Insert(&((*p)->left),a);
    }
    else{
        D++;
        Insert(&((*p)->right),a);
    }
}
void output(Tp p)
{
    if(p!=NULL){
        output(p->left);
        if(p->left==NULL&&p->right==NULL) printf("%d %d\n",p->value,p->depth);
        output(p->right);
    }
}
int main()
{
    int n,x,i=0,d;
    scanf("%d",&n);
    while(i<n)
    {
        scanf("%d",&x);
        Insert(&root,x);
        D=1;
        i++;
    }
    output(root);
return 0;
}
