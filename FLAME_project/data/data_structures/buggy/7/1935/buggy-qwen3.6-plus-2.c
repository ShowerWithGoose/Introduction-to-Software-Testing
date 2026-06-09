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
        InsertBST(p->rchild, key); // @@ The problem states that values >= root go to the right. If a duplicate key is found (SearchBST returns 1), this recursive call attempts to insert it into the right subtree of the found node. However, `p` points to the node with the matching key. Passing `p->rchild` (which is a BiTree, not BiTree*) to a function expecting BiTree* is a type mismatch if not handled carefully, but more importantly, the logic for handling duplicates in BST usually involves inserting to the right. The critical error here is that `InsertBST` expects `BiTree*`, but `p->rchild` is `BiTree`. It should be `&p->rchild`. Furthermore, simply recursing might not update the parent pointer correctly if the subtree was empty. But the main issue causing Runtime Error or logical failure is likely the traversal logic below. Let's look further. Actually, looking at `PreOrder`, the height calculation is completely wrong for a general tree, it assumes a specific traversal order that doesn't track depth correctly relative to the root. But first, let's fix the insertion. `InsertBST(p->rchild, key)` passes a `BiTree` where `BiTree*` is expected. This will cause a compilation error or runtime crash depending on compiler strictness. It should be `InsertBST(&(p->rchild), key)`.
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
    if (t = NULL) // @@ Assignment instead of comparison. Should be `if (*t == NULL)`. Also `t` is a pointer to pointer, checking `t == NULL` checks if the address of the pointer variable is null, which is wrong. It should check if the tree pointed to is empty: `if (*t == NULL)`.
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
        else if ((*t)->data < key)
        {
            DeleteBST(&((*t)->lchild), key); // @@ Logic error: if key is greater than current node, we should go to the right child, not left. Should be `DeleteBST(&((*t)->rchild), key);`
        }
        else
        {
            DeleteBST(&((*t)->rchild), key); // @@ Logic error: if key is smaller than current node, we should go to the left child, not right. Should be `DeleteBST(&((*t)->lchild), key);`
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
int i = 1;
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
} // @@ The variable `i` is global and used to track depth. However, pre-order traversal does not guarantee that `i` represents the correct depth of a node in a way that persists correctly across different branches if not managed perfectly. More importantly, the problem requires outputting leaf nodes from **left to right**. Pre-order traversal visits Root, Left, Right. This does visit leaves in a left-to-right order relative to their position in the tree structure? Yes, Pre-order visits nodes in a way that left subtrees are fully processed before right subtrees. So the order of leaves will be left-to-right. The issue is the height calculation. The global `i` increments before going down and decrements after coming back. This effectively tracks the depth if initialized to 1 at root. Let's trace: Root (i=1). Go Left (i becomes 2). Go Left (i becomes 3)... This seems correct for depth. Wait, the problem says "height of the root node is 1". Depth and Height are often confused. Here it means Depth (distance from root). The code uses `i` as depth. Is `PreOrder` correct for "Left to Right" leaf output? Yes. In-order is strictly sorted by value. Pre-order is top-down, left-to-right. For leaves, Pre-order and In-order produce the same left-to-right sequence? No. Consider a tree: Root 10, Left 5 (Leaf), Right 15 (Leaf). Pre-order: 10, 5, 15. Leaves: 5, 15. In-order: 5, 10, 15. Leaves: 5, 15. They are the same for leaves? Generally, yes, because leaves don't have children to interleave. The order of leaves in Pre-order, In-order, and Post-order is always the same: left-to-right. So the traversal order is fine. The main issue is likely the `InsertBST` recursion bug causing crash or incorrect tree structure, and the `DeleteBST` bugs. Since the test case doesn't use delete, we focus on Insert and Traverse. The `InsertBST` recursive call `InsertBST(p->rchild, key)` is definitely wrong type-wise. It needs `&`.

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
    PreOrder(tree);
}