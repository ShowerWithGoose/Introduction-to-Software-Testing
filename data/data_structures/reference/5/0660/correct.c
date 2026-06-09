//
//  main.c
//  multi
//
//  Created by  on 2022/3/26.
//

/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 100005
#define num_of(x) (sizeof(x)/sizeof(x[0]))

typedef struct x{
    long long ce, exp;
    struct x *next;
} x, *x_ptr;

x_ptr create(x_ptr);
x_ptr product(x_ptr, x_ptr, int *);
int rank(const void *, const void *);
x_ptr combine(x_ptr);
void combine_x(x[], int *);
int main()
{
    x_ptr list1=NULL, list2=NULL, ans, tmp;
    x ans_x[MAXN];
    int cnt=0;
    list1=create(list1);
    list2=create(list2);
    ans=product(list1, list2, &cnt);//算乘积ans
    for (int i=0; i<cnt; i++)
    {
        tmp=ans;
        ans_x[i].ce=ans->ce;
        ans_x[i].exp=ans->exp;
        ans_x[i].next=ans->next;//ans_x[i+1]与*(ans_x[i].next)是一个东西吗？
        ans=ans->next;
        free(tmp);
    }
    qsort(ans_x, cnt, sizeof(x), rank);//把乘积按指数由高到低排序
    /*
    for (int i=0; i<cnt; i++)
    {
        printf("%d %d\n", ans_x[i].ce, ans_x[i].exp);
    }
    putchar('\n');
    putchar('\n');
    */
    combine_x(ans_x, &cnt);//删除系数ce为0的项 且 合并指数exp相同的项
    
    /*
    ans=ans_x;
    combine(ans);//合并指数exp相同的项
    while (ans!=NULL)
    {
        printf("%d %d\n", ans->ce, ans->exp);
        ans=ans->next;
    }
    */
    for (int i=0; i<cnt; i++)
    {
        printf("%lld %lld ", ans_x[i].ce, ans_x[i].exp);
    }
    return 0;
}

x_ptr create(x_ptr start)
{
    x_ptr p, end=NULL;
    int a, b;
    char buf[MAXN], *q;
    fgets(buf, MAXN, stdin);
    q=buf;
    while (~sscanf(q, "%d %d ", &a, &b))
    {
        p=(x_ptr)malloc(sizeof(x));
        p->ce=(long long)a;
        p->exp=(long long)b;
        p->next=NULL;
        if (start==NULL)
            start=p;
        else
            end->next=p;
        end=p;
        q=strchr(q, ' ');
        if ((q=strchr(q+1, ' '))!=NULL)
            q++;
        else
            break;
    }
    return start;
}

x_ptr product(x_ptr list1, x_ptr list2, int *n)//算出乘积
{
    x_ptr start=NULL, end=NULL, p, p1, p2;
    for (p1=list1; p1!=NULL; p1=p1->next)
    {
        for (p2=list2; p2!=NULL; p2=p2->next)
        {
            p=(x_ptr)malloc(sizeof(x));
            p->ce=p1->ce*p2->ce;
            p->exp=p1->exp+p2->exp;
            p->next=NULL;
            if (start==NULL)
                start=p;
            else
                end->next=p;
            (*n)++;//n表示乘积共有多少项（qsort里面需要有这个数）
            end=p;
        }
    }
    return start;
}

int rank(const void *p1, const void *p2)
{
    x_ptr pp1, pp2;
    pp1=(x_ptr)p1;
    pp2=(x_ptr)p2;
    if (pp1->exp>pp2->exp)
        return -1;
    else if (pp1->exp<pp2->exp)
        return 1;
    else
        return 0;
}

x_ptr combine(x_ptr p)
{
    x_ptr q=p;
    while (p->next!=NULL)
    {
        if (p->exp==p->next->exp)
        {
            p->ce+=(p->next->ce);//把指数相同的项的系数合并到其中前面的一项
            p->next=p->next->next;//删除后面的一项
        }
        p=p->next;
    }
    return q;
}

void combine_x(x a[], int *n)
{
    int i, flag;
    for (i=0; a[i].next!=NULL; i++)
    {
        flag=0;
        if (a[i].exp==a[i+1].exp)//a[i]与a[i+1]的项数相同
        {
            a[i].ce+=a[i+1].ce;//系数加起来
            a[i].next=a[i+1].next;
            (*n)--;
            flag=1;
            for (int j=i+1; ;j++)//把a[i+1]删除
            {
                a[j]=a[j+1];
                if (a[j].next==NULL)
                    break;
            }
        }
        if (a[i].ce==0)//a[i]的系数为0
        {
            a[i-1].next=a[i].next;
            for (int j=i; ;j++)//把a[i]删除
            {
                a[j]=a[j+1];
                if (a[j].next==NULL)
                    break;
            }
            (*n)--;
            flag=1;
        }
        if (flag==1) i--;
    }
    if (a[i].ce==0)//a[i]的系数为0
    {
        (*n)--;
    }
}



