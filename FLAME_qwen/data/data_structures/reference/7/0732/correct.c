#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct Node{
    int data;
    struct Node *left,*right;
} *BTNodeptr;
BTNodeptr root=NULL;
void insertBST(int item)
{
    BTNodeptr p,q;
    p=(BTNodeptr) malloc(sizeof (struct Node));
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL)
        root=p;
    else
    {
        q=root;
        while(1)
        {
            if(q->data > item){
                if(q->left==NULL){
                    q->left=p;
                    break;
                }
                else
                    q=q->left;
            }else if(q->data <= item){
                if(q->right==NULL){
                    q->right=p;
                    break;
                }
                else
                    q=q->right;
            }
        }
    }
}
void SearchLeafNode(BTNodeptr ptr,int deep)
{
    if(ptr!=NULL)
    {
        SearchLeafNode(ptr->left,deep+1);
        if(ptr->left==NULL && ptr->right==NULL)
            printf("%d %d\n",ptr->data,deep);
        SearchLeafNode(ptr->right,deep+1);
    }
}
int main()
{
    int item,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&item);
        insertBST(item);
    }
    SearchLeafNode(root,1);
    return 0;
}

