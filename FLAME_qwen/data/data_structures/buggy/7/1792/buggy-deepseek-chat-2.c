#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<ctype.h> 
#include<stdlib.h> 
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //��ȡָ��λ 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //ȡ��ָ��λ 
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //��ĳλ��0 
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //��ĳλ��1
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
            depth = 2; // @@ [This line is unnecessary and does not cause an error, but the variable depth is redeclared inside the else block, which shadows the outer declaration and may cause confusion. However, the main issue is that the root node's depth is never set to 1, so all depths are off by one. The root node's depth should be initialized to 1 in initialroot() or set after creation.]
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
    return root; // @@ [The depth field is not initialized in initialroot(). This means the root node's depth is undefined (garbage value), and all subsequent nodes' depths will be based on this garbage value, leading to incorrect height output. The depth should be set to 1 for the root node.]
}