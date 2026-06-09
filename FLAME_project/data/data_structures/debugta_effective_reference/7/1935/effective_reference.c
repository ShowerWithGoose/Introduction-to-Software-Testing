#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode /* 结点结构 */
{
  int data;                        /* 结点数据 */
  struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
  int depth;
} BiTNode, *BiTree;

/* 递归查找二叉排序树T中是否存在key, */
/* 指针f指向T的双亲，其初始调用值为NULL */
/* 若查找成功，则指针p指向该数据元素结点，并返回TRUE */
/* 否则指针p指向查找路径上访问的最后一个结点并返回FALSE */
Status SearchBST(BiTree tree, int key, BiTree f, BiTree *p)
{
  if (!tree) /*  查找不成功 */
  {
    *p = f;
    return FALSE;
  }
  // else if (key == T->data) /*  查找成功 */
  // {
  //   *p = T;
  //   return TRUE;
  // }
  else if (key < tree->data)
    return SearchBST(tree->lchild, key, tree, p); /*  在左子树中继续查找 */
  else
    return SearchBST(tree->rchild, key, tree, p); /*  在右子树中继续查找 */
}

/*  当二叉排序树T中不存在关键字等于key的数据元素时， */
/*  插入key并返回TRUE，否则返回FALSE */
Status InsertBST(BiTree *tree, int key)
{
  BiTree p, s;
  SearchBST(*tree, key, NULL, &p); /* 查找不成功 */

  s = (BiTree)malloc(sizeof(BiTNode));
  s->data = key;
  s->lchild = s->rchild = NULL;
  if (!p)
  {
    s->depth = 1;
    *tree = s; /*  插入s为新的根结点 */
  }
  else if (key < p->data)
  {

    p->lchild = s; /*  插入s为左孩子 */
    p->lchild->depth = p->depth + 1;
  }
  else
  {

    p->rchild = s; /*  插入s为右孩子 */
    p->rchild->depth = p->depth + 1;
  }
  return TRUE;
}

/* 从二叉排序树中删除结点p，并重接它的左或右子树。 */
Status Delete(BiTree *p)
{
  BiTree q, s;
  if ((*p)->rchild == NULL) /* 右子树空则只需重接它的左子树（待删结点是叶子也走此分支) */
  {
    q = *p;
    *p = (*p)->lchild;
    free(q);
  }
  else if ((*p)->lchild == NULL) /* 只需重接它的右子树 */
  {
    q = *p;
    *p = (*p)->rchild;
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
      q->rchild = s->lchild; /*  重接q的右子树 */
    else
      q->lchild = s->lchild; /*  重接q的左子树 */
    free(s);
  }
  return TRUE;
}

/* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点, */
/* 并返回TRUE；否则返回FALSE。 */
Status DeleteBST(BiTree *tree, int key)
{
  if (!*tree) /* 不存在关键字等于key的数据元素 */
    return FALSE;
  else
  {
    if (key == (*tree)->data) /* 找到关键字等于key的数据元素 */
      return Delete(tree);
    else if (key < (*tree)->data)
      return DeleteBST(&(*tree)->lchild, key);
    else
      return DeleteBST(&(*tree)->rchild, key);
  }
}

void InOrderTraverse(BiTree tree)
{
  if (tree == NULL)
    return;
  InOrderTraverse(tree->lchild); /* 中序遍历左子树 */
  if (!tree->lchild && !tree->rchild)
    printf("%d %d\n", tree->data, tree->depth); /* 显示结点数据，可以更改为其它对结点操作 */
  InOrderTraverse(tree->rchild);             /* 最后中序遍历右子树 */
}

int main(void)
{
  int i;
  int n;
  scanf("%d", &n);
  int a;
  BiTree tree = NULL;

  for (i = 0; i < n; i++)
  {
    scanf("%d", &a);
    InsertBST(&tree, a);
  }

  // DeleteBST(&T, 93);
  // DeleteBST(&T, 47);
  InOrderTraverse(tree);
  // printf("本样例建议断点跟踪查看二叉排序树结构");
  return 0;
}

