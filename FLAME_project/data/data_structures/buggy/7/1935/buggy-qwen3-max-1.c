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
        InsertBST(p->rchild, key); // @@ [When a duplicate key is found (SearchBST returns 1), the code incorrectly tries to insert the duplicate into the right subtree recursively. However, according to the problem, duplicates should be inserted in the right subtree during initial insertion, but this recursive call bypasses the proper depth tracking and may cause infinite recursion or incorrect tree structure. Also, the original reference program does not re-insert duplicates—it simply ignores them. This logic is flawed.]
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
    if (t = NULL) // @@ [This is an assignment (t = NULL) instead of a comparison (t == NULL). This causes t to be set to NULL, leading to undefined behavior or crash when dereferencing *t later. It should be 'if (*t == NULL)' or 'if (t == NULL || *t == NULL)'.]
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
            DeleteBST(&((*t)->lchild), key); // @@ [The condition checks if current node's data is less than key, which means key should be in the right subtree, but here it recurses on the left child. This is backwards. Should be: if ((*t)->data > key) recurse left, else recurse right.]
        }
        else
        {
            DeleteBST(&((*t)->rchild), key); // @@ [Due to the inverted condition above, this branch is taken when (*t)->data >= key, but it should only be for > key. Also, combined with the previous error, deletion logic is completely broken. However, since the main() doesn't call DeleteBST, this may not directly cause the current failure, but it's still an error.]
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
            printf("%d %d\n", t->data, i); // @@ [The height (depth) of a node is being tracked by a global variable 'i' that increments on entry and decrements on exit. However, this assumes a DFS stack-like behavior, but the value of 'i' does not represent the actual depth from the root. For example, after traversing left subtree, 'i' is decremented, but then when going right, it uses the same 'i' which is now incorrect. The depth should be passed as a parameter or stored in the node during insertion. The reference program stores depth in the node during insertion, but this program does not store depth at all. Hence, leaf heights are wrong.]
        }
        i++; // @@ [Incrementing global 'i' before recursing assumes pre-order depth, but this fails because multiple branches interfere with the same global counter. Depth must be per-path, not global.]
        PreOrder(t->lchild);//递归先序遍历左子树
        PreOrder(t->rchild);//递归先序遍历右子树
        i--; // @@ [Decrementing global 'i' after both subtrees assumes symmetric traversal, but if left subtree is deep and right is shallow, the depth for right leaves will be incorrect. This method cannot correctly compute node depths.]
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