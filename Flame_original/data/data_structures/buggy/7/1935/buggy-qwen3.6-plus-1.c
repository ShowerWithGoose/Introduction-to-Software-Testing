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
        SearchBST(t->rchild, key, t, p); // @@ Missing return statement, causes undefined return value and breaks insertion logic
    }
    else
    {
        SearchBST(t->lchild, key, t, p); // @@ Missing return statement, causes undefined return value and breaks insertion logic
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
        InsertBST(p->rchild, key); // @@ Type mismatch: function expects BiTree* (pointer to pointer) but BiTree is passed. Should be &(p->rchild)
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
    if (t = NULL) // @@ Assignment operator '=' used instead of comparison '=='. Should be *t == NULL to correctly check if the tree is empty
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
            DeleteBST(&((*t)->lchild), key);
        }
        else
        {
            DeleteBST(&((*t)->rchild), key);
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