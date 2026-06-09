#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;

NODE *Root;
NODE *zhan[20];
int num;

void sortTree(int n);
void insertBST(int item);
void bian_li();
int height_node(NODE *,NODE *);
void destoryTree(NODE *p);

int main()
{
    int n;

    scanf("%d",&n);

    sortTree(n);
    bian_li();

    destoryTree(Root);
    return 0;
}

void sortTree(int n)//借助二叉查找树的插入实现树的建立（调用非递归）
{
    int k;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&k);
        insertBST(k);
    }
}

void insertBST(int item)//非递归进行二叉查找树的插入
{
    NODE *p,*q;
    p=(NODE *)malloc(sizeof(NODE));
    p->num=item;
    p->left=NULL;
    p->right=NULL;
    if(Root==NULL)
        Root=p;
    else
    {
        q=Root;
        while(1)
        {
            /* 比较值的大小 */
            /* 小于向左，大于向右 */
            if(item<q->num)
            {
                if(q->left==NULL)
                {
                    q->left=p;
                    break;
                }
                else
                    q=q->left;
            }
            else if (item>=q->num)
            {
                if(q->right==NULL)
                {
                    q->right=p;
                    break;
                }
                else
                    q=q->right;
            }
        }
    }
}

void bian_li()//遍历二叉树
{
    NODE *p = Root;

    num = -1;
    if(p!=NULL)
    {
        do
        {
            while(p!=NULL)
            {
                zhan[++num]=p;
                p=p->left;
            }
            p=zhan[num--];

            if(p->right == NULL && p->left == NULL) // @@ The condition for a leaf node is that both left and right children are NULL. The original code only checked if the right child was NULL, which incorrectly identified nodes with only a left child as leaves (or failed to identify true leaves correctly depending on traversal logic). Specifically, node 180 has no right child but has a left child, so it is not a leaf. The check must ensure both are NULL.
            {
                printf("%d %d\n",p->num,height_node(Root,p));
            }

            p=p->right;
        }
        while(!(p==NULL && num==-1));
    }
}

int height_node(NODE *q,NODE *p)//二叉树的高度
{
    if(q->num == p->num)
    {
        if(q == p)
        {
            return 1;
        }
        else
        {
            return 1 + height_node(q->right,p); // @@ If values are equal but pointers are different, it means we found a duplicate value node. According to BST rules (right >= root), duplicates go to the right. However, simply going right might miss the specific node instance if there are multiple duplicates or if the structure is complex. But more critically, this recursive search assumes unique paths based on value. If values are identical, we cannot distinguish left/right purely by value comparison in the recursion step below easily without pointer equality. However, the main logical error here is that if `q->num == p->num` but `q != p`, we assume it's on the right. This is generally true for insertion order, but `height_node` is searching for a specific pointer `p`. If there are duplicate values, this logic might traverse the wrong subtree if the target `p` is not the first one encountered or if the tree structure doesn't guarantee `p` is strictly reachable by just going right on value match. A safer approach for finding height of a specific node pointer is to traverse recursively checking pointers. However, looking at the specific failure: Node 180 is being printed. Node 180 is the root. It has a left child (170). It does NOT have a right child. The `bian_li` function visits nodes in In-Order. 
            // Let's re-evaluate `bian_li`. It's an iterative in-order traversal.
            // Stack pushes left nodes. Pops. Checks if right is NULL.
            // If right is NULL, it prints.
            // Node 180 (Root): Left exists. Push 180. Go Left to 170.
            // Node 170: Left exists (160? No, 172 is right of 170? No. 170 < 180 -> Left. 172 > 170 -> Right. 160 < 170 -> Left.)
            // Tree Structure:
            // 180
            // /   \
            // 170   (null)
            // / \
            // 160 172
            // / \
            // ... ...
            // Wait, 172 > 170, so 172 is right child of 170.
            // 160 < 170, so 160 is left child of 170.
            // 165 > 160, right of 160.
            // 150 < 160, left of 160.
            // 157 > 150, right of 150.
            // 120 < 150, left of 150.
            // 136 > 120, right of 120.
            // 0 < 120, left of 120.
            
            // Leaves: 0, 136, 157, 165, 172.
            // Node 180 has left child 170, right child NULL.
            // In `bian_li`:
            // When 180 is popped from stack, `p` becomes 180.
            // Check `if (p->right == NULL)`. 180->right IS NULL.
            // So it prints 180. This is WRONG because 180 has a left child, so it is NOT a leaf.
            // The fix in line 93 addresses this.
            
            // Regarding `height_node`: The logic `if(q->num == p->num)` handles duplicates. If values match but pointers don't, it goes right. This is consistent with insertion. The error causing WA is primarily the leaf identification in `bian_li`.
        }
    }
    else if(p->num > q->num)
    {
        return 1 + height_node(q->right,p);
    }
    else
    {
        return 1 + height_node(q->left,p);
    }
}

void destoryTree(NODE *p)//二叉树的删除
{
    if(p != NULL)
    {
        destoryTree(p->left);
        destoryTree(p->right);
        free(p);
        p = NULL;
    }
}