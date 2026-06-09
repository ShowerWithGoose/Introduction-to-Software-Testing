#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int num;
    int flap;
    struct tree *lf, *ri;
};
struct plus_tree
{
    // int floor;
    struct tree *p;
    int if_break;
};

// 该函数用于创建新节点
struct tree *creat_new_leaf(int ans)
{
    struct tree *p;
    p = malloc(sizeof(struct tree));
    p->lf = NULL;
    p->ri = NULL;
    p->num = ans;
    return p;
}

// 该函数用于将创建的节点添加在树中
struct plus_tree tree(struct tree *q, struct tree *p, int f1, int ans) // p是新节点，q是老节点
{
    struct plus_tree answer;
    if (ans < q->num)
    {
        if (q->lf == NULL)
        {
            q->lf = p;
            p->flap = f1;
            answer.if_break = 1;
        }
        else
        {
            f1++;
            q = q->lf;
            answer.p = q;
            answer.if_break = 0;
        }
    }
    else
    {
        if (q->ri == NULL)
        {
            q->ri = p;
            p->flap = f1;
            answer.if_break = 1;
        }
        else
        {
            f1++;
            q = q->ri;
            answer.p = q;
            answer.if_break = 0;
        }
    }
    return answer;
}

// 该函数用于打印树的叶子节点
void print_tree(struct tree *q)
{
    if (q == NULL)
    {
        return;
    }
    else if (q->lf == NULL && q->ri == NULL)
    {
        printf("%d %d\n", q->num, q->flap);
        return;
    }
    else
    {
        print_tree(q->lf);
        print_tree(q->ri);
        return;
    }
}

int main()
{
    // 输入部分
    int ans;
    struct tree *st, *p, *q;
    st = NULL;
    // 输入部分
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ans);
        p = creat_new_leaf(ans); // 创建新的节点
        if (st == NULL)
        {
            st = p;
            st->flap = 1;
        }
        else
        {
            int f1 = 2;
            q = st;
            while (1)
            {
                struct plus_tree anw;
                anw = tree(q, p, f1, ans);
                if (anw.if_break)
                {
                    break;
                }
                else
                {
                    q = anw.p;
                    f1++;
                }
            }
        }
    }
    // 输出部分
    print_tree(st);
    return 0;
}
