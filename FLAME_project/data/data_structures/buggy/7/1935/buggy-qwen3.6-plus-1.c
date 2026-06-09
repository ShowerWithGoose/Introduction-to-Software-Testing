#define _CRT_SECURE_NO_WARNINGS
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define NumberOf(a) (sizeof(a)/sizeof(a[0]))
#define eps 1e-7
#define ll long long
#define maxsize 1005
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
typedef int TElemtype;//这里是树节点的结构类型
typedef struct BiTNode
{
    TElemtype data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
int SearchBST(BiTree t, TElemtype key, BiTNode* f, BiTree* p)//查找
{
    //f指示双亲
    if (t == NULL)
    {
        *p = f;
        return 0;
    }
    if (key == t->data)
    {
        *p = t;
        return 1;
    }
    else if (key > t->data)
    {
        SearchBST(t->rchild, key, t, p);
    }
    else
    {
        SearchBST(t->lchild, key, t, p);
    }
}
void InsertBST(BiTree* t, TElemtype key)//插入
{
    BiTree p = NULL, s;
    if (SearchBST(*t, key, NULL, &p) == 0)//没有找到
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = NULL;
        s->rchild = NULL;
        if (p == NULL)//根节点
        {
            *t = s;
        }
        else if (key < p->data)
        {
            p->lchild = s;
        }
        else
        {
            p->rchild = s;
        }
    }
    else
    {
        InsertBST(p->rchild, key); // @@ The problem states that values >= root go to the right. If a duplicate key is found (SearchBST returns 1), 'p' points to the node with that key. The code correctly attempts to insert into the right subtree. However, the logic for handling duplicates in SearchBST combined with InsertBST is slightly fragile but functionally okay for this specific problem constraint if we assume standard BST behavior where duplicates go right. The main issue causing Runtime Error or Wrong Answer is usually elsewhere. Let's look closer. Actually, looking at the expected output, 100 appears twice in input. The first 100 is root. The second 100 should go to the right. SearchBST finds the first 100. InsertBST calls InsertBST(p->rchild, 100). This is correct recursion.
    }
    return;
}
void DeleteBSTNode(BiTree* p)
{
    BiTree q, s;
    if ((*p)->lchild == NULL)//只有右子树
    {
        q = *p;
        (*p) = (*p)->rchild;
        free(q);
    }
    else if ((*p)->rchild == NULL)//只有左子树
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else//左右子树都有
    {
        //给出右子树最小点顶替的code
        q = *p;
        s = (*p)->rchild;
        while (s->lchild)//找到最左边的节点，q是双亲
        {
            q = s;
            s = s->lchild;
        }
        (*p)->data = s->data;
        if (q != *p)//嫁接替代点的右子树
        {
            q->lchild = s->rchild;
        }
        else//没有进入循环即没有左子树
        {
            q->rchild = s->rchild;
        }
        free(s);
    }
    return;
}
void DeleteBST(BiTree* t, TElemtype key)
{
    if (t = NULL) // @@ Assignment instead of comparison. This sets t to NULL and evaluates to false (0), so the else block always executes. If tree is empty, it crashes. Even if not empty, it proceeds incorrectly. Should be 'if (*t == NULL)' or 'if (!*t)'. Also, the parameter is BiTree* t, so checking if the tree pointed to is empty requires dereferencing.
    {
        printf("TREE EMPTY!");
        return;
    }
    else
    {
        if ((*t)->data == key)
        {
            DeleteBSTNode(t);
        }
        else if ((*t)->data < key) // @@ Logic error in BST deletion traversal. If key is greater than current node's data, we should go to the RIGHT child. Here it goes to the LEFT child (&((*t)->lchild)).
        {
            DeleteBST(&((*t)->lchild), key);
        }
        else
        {
            DeleteBST(&((*t)->rchild), key); // @@ Logic error. If key is smaller (else case here implies key < data because previous was <), we should go LEFT. Here it goes RIGHT. The conditions for left/right traversal are swapped.
        }
    }
}
struct SqQueue
{
    BiTNode data[maxsize];
    int front;
    int rear;
};//循环队列防止假溢出
typedef struct SqQueue SqQueue;
void enter(SqQueue* q, BiTNode* x)//进队
{
    if ((q->rear + 1) % maxsize == q->front)//判断是否队满
    {
        printf("Full!");
        return;
    }
    q->data[q->rear] = *x;
    q->rear = (q->rear + 1) % maxsize;
}
void escape(SqQueue* q, BiTNode* x)//出队
{
    if (q->front == q->rear)//判断是否队空
    {
        printf("Empty!");
        return;
    }
    *x = q->data[q->front];
    q->front = (q->front + 1) % maxsize;
}
int i = 1; // @@ Global variable used for depth tracking. This is problematic because PreOrder is recursive and modifies a shared global state. While the increment/decrement pattern tries to manage this, using a global variable for depth in a recursive traversal is error-prone and often incorrect if the traversal order doesn't perfectly match depth changes or if multiple traversals occur. More importantly, the problem asks for Left-to-Right output of leaves. Pre-order is Root-Left-Right. In-order is Left-Root-Right. For a BST, In-order gives sorted values. The problem asks for leaves from "left to right". In a visual representation of a tree, "left to right" usually corresponds to the In-order traversal sequence of the nodes. Let's check the expected output: 12, 47, 62, 87, 100, 138, 162, 189. These are sorted. This confirms an In-order traversal is required for the output order. The code uses PreOrder.
void PreOrder(BiTree t)//递归先序遍历
{
    if (t != NULL)
    {
        if (t->lchild == NULL && t->rchild == NULL)
        {
            printf("%d %d\n", t->data, i);
        }
        i++;
        PreOrder(t->lchild);//递归先序遍历左子树
        PreOrder(t->rchild);//递归先序遍历右子树
        i--;
    }
}
int a[1000] = { 0 };
int main()
{//1.重复点无法插入 2.行计算不对，可能直接出右子树
    int n;
    scanf("%d", &n);
    BiTree tree = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        InsertBST(&tree, a[i]);
    }
    PreOrder(tree); // @@ The problem requires outputting leaves in "left to right" order. For a BST, the left-to-right spatial order of leaves corresponds to their order in an In-order traversal. The current code uses Pre-order traversal. Additionally, the height calculation relies on the global 'i' which tracks the depth during traversal. While the logic i++/i-- works for depth in a simple recursive descent, switching to In-order is necessary for correct output order.
}