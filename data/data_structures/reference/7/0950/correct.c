#include<stdio.h>
#include<stdlib.h>

struct t_node{
    int num, height;
    struct t_node *lchild, *rchild;
}*root, *p, *q;

void s_p(struct t_node *t)
{
    if(t->lchild != NULL)
        s_p(t->lchild);
    if(t->rchild != NULL)
        s_p(t->rchild);
    if(t->rchild == NULL && t->lchild == NULL)
        printf("%d %d\n", t->num, t->height);
}

int main()
{
    int n, d, h;
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++)  //create search btree with height
    {
        scanf("%d", &d);
        if(root == NULL)
        {
            q = (struct t_node *)malloc(sizeof(struct t_node));
            root = p = q;
            p->height = 1;
            p->lchild = p->rchild = NULL;
            p->num = d;
        }
        else
        {
            p = root;
            h = 1;
            q = (struct t_node *)malloc(sizeof(struct t_node));
            q->num = d;
            q->lchild = q->rchild = NULL;
            while(1)
            {
                if(d < p->num)
                {
                    if(p->lchild == NULL)
                    {
                        p->lchild = q;
                        q->height = h + 1;
                        break;
                    }
                    else
                        p = p->lchild;
                }
                else
                {
                    if(p->rchild == NULL)
                    {
                        p->rchild = q;
                        q->height = h + 1;
                        break;
                    }
                    else
                        p = p->rchild;
                }
                h++;
            }
        }
    }
    s_p(root);
    return 0;
}
