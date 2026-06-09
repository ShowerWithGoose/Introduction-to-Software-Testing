#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct tree
{
    int num;
    int height;
    struct tree *left,*right;
};

struct tree* insert(struct tree *p,int item,int height)
{
    if(p==NULL){
        p=(struct tree *)malloc(sizeof(struct tree));
        p->num=item;
        p->height=height;
        p->left=p->right=NULL;
    }
    else if(item<p->num){
        height++;
        p->left=insert(p->left,item,height);
    }
    else{
        height++;
        p->right=insert(p->right,item,height);
    }

    return p;
};

void read(struct tree *p)
{
    int level=1;
    if(p->left==NULL&&p->right==NULL){
        printf("%d %d\n",p->num,p->height);
    }
    else{
        if(p->left!=NULL)read(p->left);
        if(p->right!=NULL)read(p->right);
    }

    return;
};

void freetree(struct tree *p)
{
    if(p!=NULL){
        freetree(p->left);
        freetree(p->right);
        free(p);
    }
    return;
}

int main()
{
    struct tree *root=NULL;

    int n;
    scanf("%d",&n);

    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        root=insert(root,x,1);
    }//have planted a tree

    read(root);

    freetree(root);

    return 0;
}

