//
//  main.c
//  树基础题
//
//  Created by  on 2022/5/2.
//思路：在读入的时候加个判断即可，在每个节点里加一个代表层数的layer即可

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    int layer;
    struct node *lchild;
    struct node *rchild;
}Node,*BTNodeptr;
BTNodeptr tree,p,q;
int n;
int layer;
void output(BTNodeptr root);
BTNodeptr insert_node(BTNodeptr root, int item, int layer);
int main(int argc, const char * argv[])
{
    BTNodeptr root = NULL;
    int n;
    int item;
    scanf("%d",&n);
    int i = 0;
    for (i=0; i<n; i++)
    {
        scanf("%d",&item);
        root = insert_node(root,item,layer);
    }
    output(root);
    //output(tree);
    return 0;
}
BTNodeptr insert_node(BTNodeptr root, int item, int layer)
{
    layer++;
    if (root==NULL)
    {
        root = (BTNodeptr)malloc(sizeof(Node));
        root->data = item;
        root->lchild = NULL;
        root->rchild = NULL;
        tree = root;
        root->layer = layer;
    }
    else if (item<root->data)
            root->lchild = insert_node(root->lchild, item, layer);
    else if (item>=root->data)
            root->rchild = insert_node(root->rchild, item, layer);
    return root;
}
void output(BTNodeptr root)
{
    if (root)
    {
        if (!(root->lchild)&&!(root->rchild))
        {
            printf("%d %d\n",root->data,root->layer);
        }
        output(root->lchild);
        output(root->rchild);
    }
    
}

