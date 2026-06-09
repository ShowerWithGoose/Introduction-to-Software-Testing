#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include <ctype.h>
typedef struct BST_tree
{
    int data;
    struct BST_tree *left,*right;
}BST,*Blink;

Blink insertBST(Blink p,int num)
{
    if(p==NULL)
    {
        p=(Blink)malloc(sizeof(BST));
        p->data=num;
        p->left=p->right=NULL;
    }
    else
    {
        if(num<p->data)
            p->left=insertBST(p->left,num);
        if(num>=p->data)
            p->right=insertBST(p->right,num);
    }
    return p;
}
void BFS(Blink p,int level)
{
    if(p!=NULL)
    {
        if(p->left==NULL&&p->right==NULL)
            printf("%d %d\n",p->data,level);
        BFS(p->left,level+1);
        BFS(p->right,level+1);

    }

}
int main()
{
    int n,i,num;
    Blink root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        root=insertBST(root,num);
    }

    BFS(root,1);

    return 0;
}

