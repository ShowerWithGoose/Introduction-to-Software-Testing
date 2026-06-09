#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node1{
    int data1;
    int count;
};
struct node1 leaf[100];
int count,num,num1,count1;
typedef struct node BTNode;
typedef struct node* BTNodeptr;
BTNodeptr insertbst(BTNodeptr p,int a);
void visit(BTNodeptr t);
void preorder(BTNodeptr m);
void searchbst(BTNodeptr p,int key);
BTNodeptr root=NULL;
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        root=insertbst(root,a);
    }
    preorder(root);
    for (int i=0;i<num;i++)
    {
        searchbst(root,leaf[i].data1);
        printf("%d %d\n",leaf[i].data1,leaf[i].count);
    }
    return 0;
}
BTNodeptr insertbst(BTNodeptr p,int a)
{
    if(p==NULL)
    {
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->data=a;
        p->left=p->right=NULL;
    }
    else if(a<p->data)
    {
        p->left=insertbst(p->left,a);
    }
    else if(a>=p->data)
    {
        p->right=insertbst(p->right,a);
    }
    return p;
}
void preorder(BTNodeptr m)
{
    if(m!=NULL)
    {
        visit(m);
        preorder(m->left);
        preorder(m->right);
    }
}
void visit(BTNodeptr t)
{
    if((t->left==NULL)&&(t->right==NULL))
    {
        leaf[num].data1=t->data;
        num++;
    }
}
void searchbst(BTNodeptr p,int key) // @@ The function uses global variables count1 and num1 which are not reset for each search, and the logic for handling duplicate keys (going right) is flawed because it doesn't distinguish between the target leaf and intermediate nodes with the same value. Specifically, when key == p->data, it records the height immediately. If there are duplicates in the path (e.g., searching for a leaf 100 when root is 100), it will stop at the root instead of continuing to the right child where the actual leaf might be. The condition `if((key==p->data))` should check if it is the specific leaf node being searched for, but since multiple nodes can have the same value, simple equality is insufficient without ensuring we've reached the correct instance. However, the primary issue causing the wrong height for the duplicate 100 is that the search stops at the first node with value 100 (the root, height 1) instead of traversing down to the leaf node with value 100. The search logic needs to continue right if key >= data, but only stop if it's a leaf.
{
    if(p!=NULL)
    {
        count1++;
        if((key==p->data)) // @@ This condition terminates the search too early for duplicate values. It matches the root (100) which is not a leaf, but the code assumes it found the target. It should only stop if it's a leaf node or ensure it traverses correctly for duplicates. Given the BST property (right >= root), searching for a value equal to current node should go right if not a leaf, or stop if it is the intended leaf. But since we don't know which duplicate is the leaf just by value, we must traverse. The standard search for a specific node instance isn't possible by value alone if duplicates exist and aren't uniquely identified. However, the problem asks for leaf nodes. The `searchbst` is called with the value of a known leaf. If there are multiple nodes with that value, we need to find the one that is a leaf. The current code stops at the first match.
        {
            leaf[num1].count=count1;
            num1++;
            count1=0;
        }
        else if(key<p->data)
        {
            searchbst(p->left,key);
        }
        else if(key>=p->data)
        {
            searchbst(p->right,key);
        }
    }
}