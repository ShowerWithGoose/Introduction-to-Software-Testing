#include<stdio.h>
struct node {
    int num;
    struct node * llink, * rlink;
};
struct node * p, *list=NULL;
void build(int temp);
void compare(struct node * find, int temp);
void libian(int floor,struct node * link);
int main()
{
    int n; scanf("%d",&n);
    int i,temp;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        build(temp);
    }
    libian(0,list);
    //中序，输出数据； 
}
void libian(int floor,struct node * link)
{
    floor++;
    if((link->llink)!=NULL)
    {
        libian(floor,(link->llink));
    }
    //printf("%d ",(link->num));
    //    printf("%d\n",floor);
    else if((link->llink)==NULL&&(link->rlink)==NULL) @@ The use of 'else if' prevents checking the right subtree if the left subtree exists but is not a leaf, or incorrectly structures the traversal logic. More critically, the problem requires outputting leaves in left-to-right order (in-order traversal of leaves). The current logic prints a node only if it has no left child AND is a leaf (due to the else if chain combined with the first if). If a node has a left child, it recurses left. If it doesn't have a left child, it checks if it's a leaf. If it is, it prints. Then it checks right. However, if a node has a left child, the 'else if' block is skipped entirely. This means if a node has a left child but no right child, and the node itself is not a leaf (which is true if it has a left child), it just recurses left. This part is actually okay for traversal, but the condition for printing is flawed because it's tied to the absence of a left child via the else-if structure relative to the first if. Actually, the bigger issue is that `else if` implies that if `link->llink != NULL`, we go into the first block and skip the print check. This is correct for non-leaves with left children. But if `link->llink == NULL`, we enter the `else if`. If it's a leaf, we print. If it's not a leaf (i.e., has right child but no left), we don't print (correct) and then fall through to check right. Wait, if `link->llink == NULL` and `link->rlink != NULL`, the `else if` condition `(link->llink)==NULL&&(link->rlink)==NULL` is false. So we skip the print block. Then we check `if((link->rlink)!=NULL)` and recurse right. This seems logically okay for traversal. The real error is likely in the BST construction.
    {
        printf("%d ",(link->num));
        printf("%d\n",floor);
        
    }
     if((link->rlink)!=NULL)
    {
        libian(floor,(link->rlink));
    }
    
}
void build(int temp)
{
    if(list==NULL)
    {
        list=(struct node *)malloc(sizeof(struct node));
        list->num=temp;
        p=list;
        list->llink=NULL;
        list->rlink=NULL;
    }
    else
    {
        p=list;
        compare(p,temp);
        
    }
}
void compare(struct node * find, int temp)
{
    if((find->num)>temp)
    {
        if(find->llink!=NULL)
        {
            compare((find->llink),temp);
        }
        else
        {
            p=(struct node *)malloc(sizeof(struct node));
            p->num=temp;
            find->llink=p;
            p->llink=NULL;
            p->rlink=NULL;
        }
    }
    else if((find->num)<temp) @@ The problem states that values greater than or equal to the root go to the right. This condition only sends strictly greater values to the right. Values equal to the current node are ignored/dropped because they don't satisfy `> temp` or `< temp`. This causes duplicate values (like 100) to be missing from the tree.
    {
        if(find->rlink!=NULL)
        {
            compare((find->rlink),temp);
        }
        else
        {
            p=(struct node *)malloc(sizeof(struct node));
            p->num=temp;
            find->rlink=p;
            p->llink=NULL;
            p->rlink=NULL;
        }
    }
}