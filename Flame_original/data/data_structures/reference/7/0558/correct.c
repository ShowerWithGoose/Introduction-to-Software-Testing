#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct tree{
int num;
int height;
struct tree *lchild,*rchild;
}tree;
tree* first;
void print(tree *node);
tree *build(tree *node, int temp, int len);
int main ()
{
int i,j,k,l,m,n,temp,len=0;
scanf("%d",&n);
tree *node=NULL;
for(i=0;i<n;i++)
{
scanf("%d",&temp);
len=0;
node=build(node,temp,len);
}
print(node);
return 0;
}
void print(tree *node)
{
    if (node!=NULL)
    {
        if ((node->lchild)==NULL&&(node->rchild)==NULL)
        {
            printf("%d %d\n", node->num,node->height);
        }
        print(node->lchild);
        print(node->rchild);
    }
}
tree *build(tree *node, int temp, int len)
{
    len++;
    if (node == NULL)
    {
        node = (tree *)malloc(sizeof(tree));
        node->num = temp;
        node->lchild = node->rchild = NULL;
        first = node;
        node->height = len;
    }
    else if (temp < node->num)
        node->lchild = build(node->lchild, temp, len);
    else if (temp >= node->num)
        node->rchild = build(node->rchild, temp, len);
    return node;
}

