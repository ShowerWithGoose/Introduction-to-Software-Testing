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
    if(T->left==NULL||T->right==NULL) return 1; // @@ isempty逻辑错误：应判断节点本身是否为空，这里用||导致叶子返回1，但非叶子也返回1，递归方向出错
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
        else if(a[i]<T->data&&T->right==NULL) // @@ 条件错误：应判断左子树是否非空，写成了T->right==NULL，导致左子非空且右空时错误递归
        build_sorttree(T->left,i);
        else
        build_sorttree(T->right,i); // @@ 当isempty==1且未匹配时默认递归右子树，可能访问空节点导致段错误
        
        
    }
    
    else if(a[i]<T->data)
    build_sorttree(T->left,i);
    
    else if(a[i]>=T->data)
    build_sorttree(T->right,i);    
}
int get_layer(struct tree* T,int level,char key)//获取某一结点的高度 level开始以1输入 // @@ 参数key类型应为int，否则传入int值可能被截断，比较时出错
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
    for(int i=1;i<count;i++) // @@ C89不支持在for循环中声明变量，可能导致编译错误；且逻辑上应在构建树时使用i作为索引
    scanf("%d",&a[i]);
    
    build_root();
    build_sorttree(T0,1);
    find_leave(T0);
    
    
}