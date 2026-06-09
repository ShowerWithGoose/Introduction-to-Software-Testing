#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<ctype.h> 
#include<stdlib.h> 
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //ȡָλ 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //ȡָλ 
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //ĳλ0 
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //ĳλ1
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-8 
#define MAXLINE 1024

struct Elemtype
{
    int num;
    int depth;
    struct Elemtype* lchild;
    struct Elemtype* rchild;
};
typedef struct Elemtype BST;

void travelTree(BST* T);
BST* initialroot();

int main()
{
    //build a BST
    int n = 0;
    scanf("%d",&n);
    BST* root=NULL,*child=NULL,*parent=NULL;
    for(int i=1;i<=n;i++)
    {
        int num = 0;
        scanf("%d",&num);
        if(root==NULL)
        {
            root = initialroot();
            child = root;
            root->num = num;
            root->depth = 1; // @@ [The root node's depth is not initialized to 1, causing leaf at root to output depth 0 instead of 1]
        }
        else
        {
            int depth = 2;
            for(child=root;;depth++)
            {
                if(num<child->num)
                {
                    if(child->lchild==NULL)
                    {
                        child->lchild = initialroot();
                        child->lchild->num = num;
                        child->lchild->depth = depth;
                        break;
                    }
                    child = child->lchild;
                }
                else
                {
                    if(child->rchild==NULL)
                    {
                        child->rchild = initialroot();
                        child->rchild->num = num;
                        child->rchild->depth = depth;
                        break;
                    }
                    child = child->rchild;
                }
            }
            depth = 2;
        }
    }
    //travle the BST
    travelTree(root);
    return 0;
}

void travelTree(BST* T)
{
    if(T!=NULL)
    {
        if(T->lchild==NULL&&T->rchild==NULL)
        {
            printf("%d %d\n",T->num,T->depth);
        }
        travelTree(T->lchild);
        travelTree(T->rchild);
    }
}

BST* initialroot()
{
    BST* root = NULL;
    root = (BST*)malloc(sizeof(BST));
    root->lchild = NULL;
    root->rchild = NULL;
    root->depth = 0; // @@ [The depth field is not initialized, leading to undefined behavior; in particular, when the tree has only root, its depth remains uninitialized (or zero), but should be 1]
    return root;
}