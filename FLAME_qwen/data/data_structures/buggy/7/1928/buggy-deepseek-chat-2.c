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
    if(T->left==NULL||T->right==NULL) return 1; // @@ Logical error: should be && instead of ||, because a node is empty only if both children are NULL
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
        else if(a[i]<T->data&&T->right==NULL) // @@ Logical error: condition should check T->left != NULL, not T->right==NULL; also missing case for a[i]>=T->data with T->right!=NULL
        build_sorttree(T->left,i);
        else
        build_sorttree(T->right,i);
        
        
    }
    
    else if(a[i]<T->data)
    build_sorttree(T->left,i);
    
    else if(a[i]>=T->data)
    build_sorttree(T->right,i);    
}
int get_layer(struct tree* T,int level,char key) // @@ Type mismatch: key should be int, not char, because tree data is int
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