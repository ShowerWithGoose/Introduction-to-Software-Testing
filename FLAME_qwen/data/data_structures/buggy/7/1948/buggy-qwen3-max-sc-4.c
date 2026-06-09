#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int num;
    int flap; // @@ [The field 'flap' is intended to store the height of the node, but it is never initialized with the correct height for the root node. The root should have height 1, but in creat_new_leaf(), 'flap' is left uninitialized.]
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
    p->num = ans; // @@ [The 'num' field is not assigned the input value 'ans', leading to undefined behavior when comparing or printing node values.]
    // @@ [The 'flap' (height) field is not initialized here. For the root node, it should be set to 1, but this function doesn't handle that.]
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
            p->flap = f1; // @@ [This correctly assigns height when inserting as left child, but only if 'f1' is correctly computed. However, the initial call uses f1=2 for the second node, which assumes root height is 1 — but root's 'flap' was never set to 1.]
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
            p->flap = f1; // @@ [Same issue as above: relies on correct 'f1', but root height is undefined.]
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
        printf("%d %d\n", q->num, q->flap); // @@ [If 'flap' was never initialized (e.g., for a single-node tree), this prints garbage for height.]
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
            st->flap = 1; // @@ [Missing: the root node's height ('flap') must be set to 1, but this assignment is absent.]
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