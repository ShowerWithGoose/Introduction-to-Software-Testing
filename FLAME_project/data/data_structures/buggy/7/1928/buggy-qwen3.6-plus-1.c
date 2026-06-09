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
int isempty(struct tree* T)
{
    if(T->left==NULL||T->right==NULL) return 1; // @@ The logic for checking if a node is "empty" (available for insertion) is flawed. It returns 1 if either child is NULL, which prevents correct traversal down a partially filled tree. For example, if left is filled but right is NULL, it returns 1, but the subsequent checks might fail or behave unexpectedly depending on the value. More critically, this function is used to decide whether to insert at current node or recurse. If a node has one child, it should recurse, not treat itself as a leaf for insertion purposes in this specific recursive structure unless the target side is NULL. However, the main issue causing the WA is likely elsewhere or combined with this. Let's look closer. Actually, `isempty` returning 1 when *either* is null is very dangerous. If I have a root with a left child, and I want to insert a value >= root, I should go right. But `isempty` returns 1. Then we check `a[i] < T->data && T->left == NULL` (False). Then `a[i] >= T->data && T->right == NULL` (True if right is null). This part might work for direct children. But what if both are non-null? It returns -1. Then we recurse. This seems logically passable for insertion *if* the recursion handles it. 
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
            build_sorttree(T0,i+1);
            
        }
        else if(a[i]>=T->data&&T->right==NULL)
        {
            T->right=(struct tree*)malloc(sizeof(struct tree));
            T->right->data=a[i];
            T->right->left=T->right->right=NULL;
            build_sorttree(T0,i+1);
        }
        else if(a[i]<T->data&&T->right==NULL) // @@ This condition is logically suspect. If a[i] < T->data, we should go left. Why check if T->right is NULL? And if T->left is NOT NULL (implied by previous checks failing), we should recurse left. This line attempts to recurse left `build_sorttree(T->left,i)` but only if `T->right==NULL`. This is incorrect. It should recurse left if `a[i] < T->data` regardless of right child status, provided left child exists (which it must if we are here and first check failed).
        build_sorttree(T->left,i);
        else // @@ Similarly, this else catches cases where a[i] >= T->data. It should recurse right. The previous explicit check was `a[i] < T->data && T->right == NULL`. This implies if we are here, either `a[i] >= T->data` OR `T->right != NULL`. If `a[i] >= T->data`, we should go right. If `T->right` exists, we should go right. So recursing right is generally correct here, BUT the structure of these if-elses is broken because of the weird condition above.
        build_sorttree(T->right,i);
        
        
    }
    
    else if(a[i]<T->data)
    build_sorttree(T->left,i);
    
    else if(a[i]>=T->data)
    build_sorttree(T->right,i);    
}
int get_layer(struct tree* T,int level,char key)//获取某一结点的高度 level开始以1输入
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
        int h=get_layer(T0,1,T->data);
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