#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<ctype.h> 
#include<stdlib.h> 
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //ȡָλ 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //ȡָλ @@ [Macro definition uses undefined macro 'BIT'; should be a typo and likely meant to define CPL directly without BIT]
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //ĳλ0 @@ [Same issue: 'BIT' is not defined; this causes compilation error]
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //ĳλ1 @@ [Same issue: 'BIT' is not defined; this causes compilation error]
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
            root->depth = 1; // @@ [Missing initialization of root->depth to 1; in reference program, root depth is set to 1]
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
    // @@ [Missing initialization of root->depth; should initialize depth to 1 or leave uninitialized? But in usage, depth is always assigned before use except for root]
    return root;
}