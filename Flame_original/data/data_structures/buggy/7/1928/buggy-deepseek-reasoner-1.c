#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int count,a[500];
struct tree
{
    int data;
    struct tree *left,*right;    
};
struct tree* T0;

void build_root()
{
    T0=(struct tree*)malloc(sizeof(struct tree));
    T0->data=a[0];
    T0->left=T0->right=NULL;
}
int isempty(struct tree* T) // @@ This function is misnamed and the logic is incorrect: it returns 1 if at least one child is NULL, but the name suggests checking emptiness. This causes flawed branching in build_sorttree.
{
    if(T->left==NULL||T->right==NULL) return 1;
    else return -1;
    
}
void build_sorttree(struct tree* T,int i)
{
    if(i==count) return;
    if(isempty(T)==1)
    {
        if(a[i]<T->data&&T->left==NULL)
        {
            T->left=(struct tree*)malloc(sizeof(struct tree));
            T->left->data=a[i];
            T->left->left=T->left->right=NULL;
            build_sorttree(T0,i+1); // @@ After inserting a node, the function recursively calls itself on the root with the next index. This is unnecessary and disrupts the intended recursive insertion flow. It should simply return after insertion so the previous call continues.
            
        }
        else if(a[i]>=T->data&&T->right==NULL)
        {
            T->right=(struct tree*)malloc(sizeof(struct tree));
            T->right->data=a[i];
            T->right->left=T->right->right=NULL;
            build_sorttree(T0,i+1);
        }
        else if(a[i]<T->data&&T->right==NULL) // @@ Logical error: if a[i] < T->data, the algorithm should check the left child, not the right child. This condition will never be true in a correct BST insertion.
        build_sorttree(T->left,i);
        else
        build_sorttree(T->right,i); // @@ This call does not increment 'i', leading to infinite recursion because the same index is processed repeatedly.
        
        
    }
    
    else if(a[i]<T->data)
    build_sorttree(T->left,i);
    
    else if(a[i]>=T->data)
    build_sorttree(T->right,i);    
}
int get_layer(struct tree* T,int level,char key) // @@ The third parameter should be 'int' to match the tree node data type. Using 'char' causes type mismatch and incorrect comparisons, so the function never finds the correct node.
{
    int l;
    if(T!=NULL)
    {
        if(T->data==key) return level;
        l=get_layer(T->left,level+1,key);//level++就不对了注意
        if(l!=0)
        {
            return l;//如果能找到该节点就返回值
        }
        else 
        return get_layer(T->right,level+1,key);        
    }
    else return 0;    
}
void find_leave(struct tree* T)//遍历叶子结点
{
    if(T->left!=NULL)
    {
        find_leave(T->left);
        
    }
    if(T->right!=NULL)//else if不对吧？
    {
        find_leave(T->right);
        
    }
    if(T->left==NULL&&T->right==NULL)
    {
        int h=get_layer(T0,1,T->data); // @@ Passing an 'int' to a parameter expecting 'char' results in implicit conversion, causing incorrect depth values.
        printf("%d %d\n",T->data,h);
        return;
    }    
}
void tranverse_tree(struct tree* T)
{
    
    if(T!=NULL)
    {
        printf("%d ",T->data);
        tranverse_tree(T->left);
        tranverse_tree(T->right);
    }
    else return;
    
}
int main()
{
    scanf("%d",&count);
    scanf("%d",&a[0]);
    for(int i=1;i<count;i++)
    scanf("%d",&a[i]);
    
    build_root();
    build_sorttree(T0,1);
    find_leave(T0);
    
    
}