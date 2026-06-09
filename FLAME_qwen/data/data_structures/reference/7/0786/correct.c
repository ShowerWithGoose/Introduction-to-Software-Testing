#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define FOR(a, b, c) for (a = b; a < c; a++)
#define ll long long
#define ull unsigned long long
#define MAXSIZE 1000
struct node 
{
    int data;
    int height;
    struct node *left, *right;
};


typedef struct node BTNode, *BTNodeptr;

BTNodeptr  insertBST(BTNodeptr p, int item,int length)
{
    length++;
    if(p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
        p->height=length;
    } 
    else if( item < p->data)
        p->left = insertBST(p->left, item,length);
    else if( item >= p->data)
       p->right = insertBST(p->right,item,length);
    return p;
}


void print(BTNodeptr root)
{
    if (root)
    {
        if (!(root->left)&&!(root->right))
        {
            printf("%d %d\n", root->data, root->height);
        }
        print(root->left);
        print(root->right);
    }
}
int main()
{   
    int num;
    scanf("%d",&num);
    int i, item;
    BTNodeptr  root=NULL;
    for(i=0;i<num;i++)  //构造一个有num个元素的BST树
    { 
        int len=0;
        scanf("%d",&item);
        root = insertBST(root, item,len);
    }
    print(root);
    return 0;
}


