#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef struct ElemType
{
    int num;
} ElemType;
/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode /* 结点结构 */
{
    ElemType data;                            /* 结点数据 */
    struct BiTNode *lchild, *rchild, *parent; /* 左右孩子指针 */
} BiTNode, *BiTree;
ElemType EmptyElem = {0};

//基础
/* 构造空二叉树T */
Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}
/* 在结点T处以元素elem构造左子树，若已存在则修改其值 */
Status InitBiTreeLChild(BiTree T, ElemType elem)
{
    if (T)
    {
        if (T->lchild == NULL)
        {
            BiTree s;
            s = (BiTree)malloc(sizeof(BiTNode));
            T->lchild = s;
            s->lchild = NULL;
            s->rchild = NULL;
            s->parent = T;
        }
        T->lchild->data = elem;
        return OK;
    }
    else
        return ERROR;
}
/* 在结点T处以元素elem构造右子树，若已存在则修改其值 */
Status InitBiTreeRChild(BiTree T, ElemType elem)
{
    if (T)
    {
        if (T->rchild == NULL)
        {
            BiTree s;
            s = (BiTree)malloc(sizeof(BiTNode));
            T->rchild = s;
            s->lchild = NULL;
            s->rchild = NULL;
            s->parent = T;
        }
        T->rchild->data = elem;

        return OK;
    }
    else
        return ERROR;
}
/* 销毁二叉树T */
void DestroyBiTree(BiTree *T)
{
    if (*T)
    {
        if ((*T)->lchild)                 /* 有左孩子 */
            DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
        if ((*T)->rchild)                 /* 有右孩子 */
            DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
        free(*T);                         /* 释放根结点 */
        *T = NULL;                        /* 空指针赋0 */
    }
}
/* 若二叉树T为空二叉树,则返回TRUE,否则FALSE */
Status BiTreeEmpty(BiTree T)
{
    if (T)
        return FALSE;
    else
        return TRUE;
}
/* 返回二叉树T的深度 */
int BiTreeDepth(BiTree T)
{
    int i, j;
    if (!T)
        return 0;
    if (T->lchild)
        i = BiTreeDepth(T->lchild);
    else
        i = 0;
    if (T->rchild)
        j = BiTreeDepth(T->rchild);
    else
        j = 0;
    return i > j ? i + 1 : j + 1;
}
/* 返回二叉树T离根的的深度 */
int BiTreeDepthFromRoot(BiTree T)
{
    if (T == NULL)
        return 0;
    else if (T->parent)
        return BiTreeDepthFromRoot(T->parent) + 1;
    else
        return 1;
}

/* 找到第n个数据的地址 */
BiTree nthOrder(BiTree T, int n)
{
    n++;
    int m = n, digit = 0, digits[32];
    while (m)
    {
        digits[digit] = m % 2;
        digit++;
        m /= 2;
    }
    digit--;
    while (digit)
    {
        digit--;
        if (T)
        {
            if (digits[digit])
                T = T->rchild;
            else
                T = T->lchild;
        }
        else
            break;
    }
    if (digit)
        return NULL;
    else
        return T;
}
/* 分配第n个数据的元素 */
BiTree AssignNthOrder(BiTree T, int n, ElemType elem)
{
    n++;
    int m = n, digit = 0, digits[32];
    while (m)
    {
        digits[digit] = m % 2;
        digit++;
        m /= 2;
    }
    digit--;
    while (digit)
    {
        digit--;
        if (T)
        {
            if (digits[digit])
            {
                if (T->rchild == NULL)
                    InitBiTreeRChild(T, EmptyElem);
                T = T->rchild;
            }
            else
            {
                if (T->lchild == NULL)
                    InitBiTreeLChild(T, EmptyElem);
                T = T->lchild;
            }
        }
        else
            break;
    }
    if (digit)
        return NULL;
    else
    {
        T->data = elem;
        return T;
    }
}

//二叉排序树
/* 比较元素大小 */
int CompareData(ElemType elem1, ElemType elem2)
{
    return elem1.num - elem2.num;
}
/* 递归查找二叉排序树T中是否存在key, 指针f指向T的双亲，其初始调用值为NULL */
/* 若查找成功，则指针p指向该数据元素结点，并返回TRUE, 否则指针p指向查找路径上访问的最后一个结点并返回FALSE */
Status SearchBSTWithLast(BiTree T, ElemType key, BiTree f, BiTree *p)
{
    if (!T) /*  查找不成功 */
    {
        *p = f;
        return FALSE;
    }
    else
    {
        int temp = CompareData(key, T->data);
        // if (temp == 0) /*  查找成功 */
        // {
        //     *p = T;
        //     return TRUE;
        // }
        if (temp < 0)
            return SearchBSTWithLast(T->lchild, key, T, p); /*  在左子树中继续查找 */
        else
            return SearchBSTWithLast(T->rchild, key, T, p); /*  在右子树中继续查找 */
    }
}
/* 递归查找二叉排序树T中是否存在key*/
BiTree SearchBST(BiTree T, ElemType key)
{
    if (T == NULL) /*  查找不成功 */
    {
        return NULL;
    }
    else
    {
        int temp = CompareData(key, T->data);
        if (temp == 0) /*  查找成功 */
        {
            return T;
        }
        else if (temp < 0)
            return SearchBST(T->lchild, key); /*  在左子树中继续查找 */
        else
            return SearchBST(T->rchild, key); /*  在右子树中继续查找 */
    }
}
/*  当二叉排序树T中不存在关键字等于key的数据元素时， 插入key并返回其地址，否则返回NULL */
BiTree InsertBST(BiTree *T, ElemType key)
{
    BiTree p, s;
    if (!SearchBSTWithLast(*T, key, NULL, &p)) /* 查找不成功 */
    {
        if (!p)
        {
            s = (BiTree)malloc(sizeof(BiTNode));
            s->data = key;
            s->lchild = s->rchild = s->parent = NULL;
            *T = s; /*  插入s为新的根结点 */
        }
        else
        {
            int temp = CompareData(key, p->data);
            if (temp < 0)
                InitBiTreeLChild(p, key); /*  插入s为左孩子 */
            else
                InitBiTreeRChild(p, key); /*  插入s为右孩子 */
        }
        return s; // @@ [Error] Variable 's' is uninitialized when 'p' is not NULL (i.e., inserting into a non-empty tree), causing undefined behavior and compilation errors with strict warning flags. It should be initialized to NULL or assigned the newly created child node.
    }
    else
        return NULL; /*  树中已有关键字相同的结点，不再插入 */
}
/* 从二叉排序树中删除结点p，并重接它的左或右子树。 */
Status Delete(BiTree *p)
{
    BiTree q, s;
    if ((*p)->rchild == NULL) /* 右子树空则只需重接它的左子树（待删结点是叶子也走此分支) */
    {
        q = *p;
        *p = (*p)->lchild;
        if (*p)
            (*p)->parent = q->parent;
        free(q);
    }
    else if ((*p)->lchild == NULL) /* 只需重接它的右子树 */
    {
        q = *p;
        *p = (*p)->rchild;
        (*p)->parent = q->parent;
        free(q);
    }
    else /* 左右子树均不空 */
    {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild) /* 转左，然后向右到尽头（找待删结点的前驱） */
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data; /*  s指向被删结点的直接前驱（将被删结点前驱的值取代被删结点的值） */
        if (q != *p)
        {
            q->rchild = s->lchild; /*  重接q的右子树 */
            if (s->lchild)
                s->lchild->parent = q;
        }
        else
        {
            q->lchild = s->lchild; /*  重接q的左子树 */
            if (s->lchild)
                s->lchild->parent = q;
        }
        free(s);
    }
    return TRUE;
}
/* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点,返回是否成功 */
Status DeleteBST(BiTree *T, ElemType key)
{
    if (!*T) /* 不存在关键字等于key的数据元素 */
        return FALSE;
    else
    {
        int temp = CompareData(key, (*T)->data);
        if (temp == 0) /* 找到关键字等于key的数据元素 */
            return Delete(T);
        else if (temp < 0)
            return DeleteBST(&(*T)->lchild, key);
        else
            return DeleteBST(&(*T)->rchild, key);
    }
}

//遍历
/* 遍历单个二叉树结点T */
void VisitNode(BiTree T)
{
    if (T)
        if (T->lchild == NULL && T->rchild == NULL)
            printf("%d %d\n", T->data.num, BiTreeDepthFromRoot(T)); /* 显示结点数据，可以更改为其它对结点操作 */
}
/* 以宽度width遍历单个二叉树结点T */
void VisitNodeWidth(BiTree T, int width)
{
    char format[20];
    sprintf(format, "%%-%dd", width);
    if (T)
        printf(format, T->data.num); /* 显示结点数据，可以更改为其它对结点操作 */
    else
        while (width--)
        {
            printf(" ");
        }
}
/* 前序递归遍历二叉树T */
void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    VisitNode(T);
    PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
    PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}
/* 中序递归遍历二叉树T */
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild); /* 中序遍历左子树 */
    VisitNode(T);
    InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
}
/* 后序递归遍历二叉树T */
void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild); /* 先后序遍历左子树  */
    PostOrderTraverse(T->rchild); /* 再后序遍历右子树  */
    VisitNode(T);
}
/* 层次递归遍历二叉树T */
void LayerOrderTraverse(BiTree T)
{
    BiTree p;

    if (T != NULL)
    {
        struct treelinklistnode
        {
            BiTree treeptr;
            struct treelinklistnode *next;
        };
        struct treelinklistnode *s, *r, *rear, *t;
        s = (struct treelinklistnode *)malloc(sizeof(struct treelinklistnode));
        r = (struct treelinklistnode *)malloc(sizeof(struct treelinklistnode));
        s->treeptr = NULL;
        s->next = r;
        r->treeptr = T;
        r->next = NULL;
        rear = r;
        while (s->next)
        { // dequeue()
            p = s->next->treeptr;
            t = s->next;
            s->next = s->next->next;
            if (s->next == NULL)
                rear = s;

            if (p->lchild != NULL)
            { // enQueue(p->rchild);
                r = (struct treelinklistnode *)malloc(sizeof(struct treelinklistnode));
                rear->next = r;
                rear = r;
                rear->treeptr = p->lchild;
                rear->next = NULL;
            }

            if (p->rchild != NULL)
            { // enQueue(p->rchild);
                r = (struct treelinklistnode *)malloc(sizeof(struct treelinklistnode));
                rear->next = r;
                rear = r;
                rear->treeptr = p->rchild;
                rear->next = NULL;
            }

            free(t);

            VisitNode(p);
        }
    }
}
/* 画出二叉树T */
void DrawBiTree(BiTree T, int width)
{
    BiTree p;
    int globaldepth = BiTreeDepth(T);
    if (T != NULL)
    {
        struct treelinklistnodeh
        {
            BiTree treeptr;
            struct treelinklistnodeh *next;
            int depth;
        };
        struct treelinklistnodeh *s, *r, *rear, *t;
        s = (struct treelinklistnodeh *)malloc(sizeof(struct treelinklistnodeh));
        r = (struct treelinklistnodeh *)malloc(sizeof(struct treelinklistnodeh));
        s->treeptr = NULL;
        s->next = r;
        s->depth = 0;
        r->treeptr = T;
        r->next = NULL;
        r->depth = 1;
        rear = r;
        int correntdepth = 0;
        while (1)
        {

            // dequeue()
            p = s->next->treeptr;
            t = s->next;
            s->next = s->next->next;
            if (s->next == NULL)
                rear = s;
            // enQueue(p->rchild);
            r = (struct treelinklistnodeh *)malloc(sizeof(struct treelinklistnodeh));
            rear->next = r;
            r->depth = t->depth + 1;
            rear = r;
            if (p)
                rear->treeptr = p->lchild;
            else
                rear->treeptr = NULL;
            rear->next = NULL;
            // enQueue(p->rchild);
            r = (struct treelinklistnodeh *)malloc(sizeof(struct treelinklistnodeh));
            rear->next = r;
            r->depth = t->depth + 1;
            rear = r;
            if (p)
                rear->treeptr = p->rchild;
            else
                rear->treeptr = NULL;
            rear->next = NULL;

            if (t->depth > correntdepth)
            {
                if (correntdepth)
                {
                    printf("\n");
                }

                correntdepth++;
                //居中
                char format[20];
                sprintf(format, "%%-%ds", width * ((int)(pow(2, globaldepth - correntdepth) - 1)));
                printf(format, "");

                if (correntdepth > globaldepth)
                    break;
            }
            else
            {
                char format[20];
                sprintf(format, "%%-%ds", width * ((int)(pow(2, globaldepth - correntdepth + 1) - 1)));
                printf(format, "");
            }
            free(t);
            VisitNodeWidth(p, width);
        }
        while (s->next)
        {
            t = s->next;
            s->next = s->next->next;
            free(t);
        }
        free(s);
    }
}

int main(void)
{
    int i, n;
    BiTree Tr = NULL;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &i);
        InsertBST(&Tr, (ElemType){i});
    }
    //
    PreOrderTraverse(Tr);
    // DrawBiTree(Tr, 2);
    return 0;
}