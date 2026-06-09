#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Datatype;
struct p {
    Datatype data;
    struct p *lchild, *rchild;
};
typedef struct p BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, Datatype item);
BTNodeptr  searchBST(BTNodeptr t,Datatype  key);

int h=1;
void inorder(BTNodeptr p){
    if (p != NULL)
    {
        h++;
        inorder(p->lchild);
        h--;
        if(p->lchild == NULL&&p->rchild==NULL) printf("%d %d\n",p->data,h);
        h++;
        inorder(p->rchild);
        h--;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int i, item;
    BTNodeptr  root=NULL;
    for(i=0; i<n; i++){ //构造一个有10个元素的BST树
        scanf("%d", &item);
        root = insertBST(root, item);
    }
    inorder(root);
    return 0;
}


//插入   递归！
BTNodeptr  insertBST(BTNodeptr p, Datatype item)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->lchild = p->rchild = NULL;
    } 
    else if( item < p->data)
        p->lchild = insertBST(p->lchild, item);
    else if( item >= p->data)
       p->rchild = insertBST(p->rchild,item);
    return p;
} 

//查找  非递归
BTNodeptr  searchBST(BTNodeptr t,Datatype  key)
{
      BTNodeptr  p=t;
      while(p!=NULL){
             if(key == p->data)  
                  return p;               /* 查找成功 */
             if(key > p->data)
                  p=p->rchild;        /* 将p移到右子树的根结点 */
             else
                  p=p->lchild;         /* 将p移到左子树的根结点 */
       }
       return NULL;                 /* 查找失败 */
}


// //查找 递归
// BTNodeptr  searchBST( BTNodeptr t, Datatype key )
// {
//       if(t!=NULL){
//             if(key == t->data) 
//                   return t;                         /* 查找成功  */ 
//             if(key > t->data)                   /* 查找T的右子树  */
//                   return searchBST(t->rchild, key);               
//             else
//                   return searchBST(t->lchild, key); 
//        }                                                  /* 查找T的左子树 */
//        else
//               return NULL;                    /* 查找失败  */
// }


