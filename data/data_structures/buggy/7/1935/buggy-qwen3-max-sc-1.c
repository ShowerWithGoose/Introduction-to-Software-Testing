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
        InsertBST(p->rchild, key); // @@ [This recursive call is incorrect: when the key already exists, it should not insert again. The problem allows duplicates to go to the right, but this code tries to insert into p->rchild without checking if that subtree already contains the key, leading to infinite recursion or incorrect structure. Also, the original logic in the reference program inserts duplicates on the right during initial insertion, so duplicate handling should be done in the first place, not via recursive InsertBST here.]
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
    if (t = NULL) // @@ [This is an assignment, not a comparison. It should be 'if (*t == NULL)' or 'if (t == NULL || *t == NULL)'. Using '=' instead of '==' causes the condition to always assign NULL to t and then evaluate to false (since NULL is 0), leading to undefined behavior when dereferencing *t later. This will likely cause a segmentation fault or incorrect deletion logic.]
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
            DeleteBST(&((*t)->lchild), key); // @@ [The condition above checks if current node's data is less than key, which means key should be in the right subtree, but here it recurses on the left child. This is backwards. Should be: else if ((*t)->data > key) { recurse left } else { recurse right }.]
        }
        else
        {
            DeleteBST(&((*t)->rchild), key); // @@ [Similarly, this branch handles the case where (*t)->data >= key, but due to the incorrect condition above, the logic for choosing left/right is inverted. This will cause the deletion to search in the wrong subtree.]
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
        i++; // @@ [The height tracking variable 'i' is incremented before traversing children, but it is shared globally. This approach fails because the height depends on the path from root, not a global counter. When backtracking (after recursive calls), i-- happens, but the order of increment/decrement does not correctly reflect the actual depth of each node. For example, after visiting a leaf, i is decremented, but the next sibling may be at a different depth. The height should be passed as a parameter, not tracked globally.]
        PreOrder(t->lchild);//递归先序遍历左子树
        PreOrder(t->rchild);//递归先序遍历右子树
        i--; // @@ [Same issue: global 'i' cannot correctly represent node height in a recursive traversal with multiple branches.]
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
    PreOrder(tree);
}