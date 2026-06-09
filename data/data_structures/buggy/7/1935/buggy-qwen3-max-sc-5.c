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
        InsertBST(p->rchild, key); // @@ [This recursive call is incorrect. When the key already exists in the tree, the problem requires inserting duplicates into the right subtree, but this code attempts to insert again into p->rchild without checking or handling properly. However, more critically, this causes infinite recursion because it doesn't use the address-of operator (&) and passes by value, leading to undefined behavior or stack overflow. Also, per problem statement, duplicates should be inserted in the right subtree during initial insertion, so this else block should not exist at all.]
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
    if (t = NULL) // @@ [This is a classic assignment instead of comparison error. It should be 'if (t == NULL)' or better 'if (*t == NULL)'. As written, it assigns NULL to t, making the condition always false (since NULL is 0), and then proceeds with invalid memory access. This causes undefined behavior.]
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
            DeleteBST(&((*t)->lchild), key); // @@ [The condition checks if current node's data is less than key, which means key should be in the right subtree, but here it recurses on left child. This is backwards logic. Should be: if ((*t)->data > key) recurse left, else recurse right.]
        }
        else
        {
            DeleteBST(&((*t)->rchild), key); // @@ [Due to the inverted condition above, this branch handles the case when (*t)->data >= key, but it should only handle when key is greater. This leads to incorrect deletion path traversal.]
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
        i++; // @@ [The height tracking using global variable 'i' is flawed. Height should be passed as a parameter because global increment/decrement does not correctly represent the depth in a DFS traversal. For example, after traversing left subtree, 'i' is decremented, but then right subtree uses the same level. However, the order of increment is also wrong: it increments before recursing, so root gets height 1 (correct), but then immediately increments to 2 before processing children. But the real issue is that multiple branches interfere with each other due to shared global state.]
        PreOrder(t->lchild);//递归先序遍历左子树
        PreOrder(t->rchild);//递归先序遍历右子树
        i--; // @@ [Same as above: global height counter cannot correctly track depth across different paths in the tree. This approach fails for trees with both left and right subtrees.]
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