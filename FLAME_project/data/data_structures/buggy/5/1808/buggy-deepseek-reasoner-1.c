#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLINE 1024
struct link
{
    long long int xi;
    long long int zhi;
    struct link *next;
};
int main()
{
    int  i, j, len1 = 0, len2 = 0;
    struct link *first_1 = NULL, *first_2 = NULL, *first_3 = NULL, *p1, *p2, *q;
    q = ( struct link * )malloc(sizeof(struct link));
    scanf("%lld %lld", &( q->xi ), &( q->zhi ));
    len1++;
    q->next = NULL;
    char c = getchar();
    while ( c != '\n' )//第一列没到头
    {
        if ( first_1 == NULL )
            first_1 = q;
        else
            p1->next = q;
        p1 = q;

        q = ( struct link * )malloc(sizeof(struct link));
        scanf("%lld %lld", &q->xi, &q->zhi);
        len1++;
        q->next = NULL;
        c = getchar();
    }
    //c=='\n'
    if ( first_1 == NULL )
        first_1 = q;
    else
        p1->next = q;
    p1 = q;//p为第一列最后一个节点

    //该读第二列

    q = ( struct link * )malloc(sizeof(struct link));
    scanf("%lld %lld", &( q->xi ), &( q->zhi ));
    len2++;
    q->next = NULL;
    c = getchar();
    while ( c != '\n' )//第一列没到头
    {
        if ( first_2 == NULL )
            first_2 = q;
        else
            p2->next = q;
        p2 = q;

        q = ( struct link * )malloc(sizeof(struct link));
        scanf("%lld %lld", &q->xi, &q->zhi);
        len2++;
        q->next = NULL;
        c = getchar();
    }
    //c=='\n'
    if ( first_2 == NULL )
        first_2 = q;
    else
        p2->next = q;
    p2 = q;//p为第二列最后一个节点

    //生成first――3
    struct link *r1 = first_1, *r2 = first_2, *p3, *s, *r;//r1,r2在1/2滑动，p3为末节点
    for ( i = 0;i <= len1 - 1;i++ )
    {
        r2 = first_2;
        for ( j = 0;j <= len2 - 1;j++ )
        {
            q = ( struct link * )malloc(sizeof(struct link));
            q->xi = ( r1->xi ) * ( r2->xi );
            q->zhi = r1->zhi + r2->zhi;
            q->next = NULL;
            if ( first_3 == NULL )
                first_3 = q;
            else
                p3->next = q;
            p3 = q;
            if ( j < len2 - 1 )
                r2 = r2->next;
        }

        if ( i < len1 - 1 )
            r1 = r1->next;
    }

    int len3 = len1 * len2;

    //排序

    long long int temp;
    r = first_3;
    for ( i = 0;i < len3 - 1;i++ )
    {
        s = r;
        int flag = 1;
        for ( j = 0;j < len3 - 1 - i;j++ )
        {
            if ( ( s->zhi ) < ( s->next->zhi ) )
            {
                temp = s->zhi;
                s->zhi = s->next->zhi;
                s->next->zhi = temp;
                temp = s->xi;
                s->xi = s->next->xi;
                s->next->xi = temp;
                flag = 0;
            }
            if ( j < len3 - 2 - i )
                s = s->next;
        }
        if ( flag == 1 )
            break;//flag 为 1 表示上一次循环中没有发现(a[j] > a[j + 1])的情况，即已经排序完毕
        if ( i < len3 - 2 )
            r = r->next; // @@ Sort error: `r` should be reset to `first_3` at the start of each outer loop, not advanced. This causes the bubble sort to skip the first element in subsequent passes, resulting in incorrect ordering.
    }
    
    //求和

    s = first_3;struct link *t;//s在fisrt_3上滑动
    while ( s->next != NULL )//s不是末节点
    {
        r = s;
        while ( r->zhi == r->next->zhi )//r==r->next
        {
            r->xi += r->next->xi;
            len3--;
            if ( r->next->next == NULL )//r的下一个是最后一个
            {
                t = r->next;
                r->next = NULL;
                free(t);
                break;
            }
            else//r的下一个不是最后一个
            {
                t = r->next;
                r->next = r->next->next;
                free(t);
            }
        }
        s = s->next;
    }

    //排序

    
    r = first_3;
    for ( i = 0;i < len3 - 1;i++ )
    {
        s = r;
        int flag = 1;
        for ( j = 0;j < len3 - 1 - i;j++ )
        {
            if ( ( s->zhi ) < ( s->next->zhi ) )
            {
                temp = s->zhi;
                s->zhi = s->next->zhi;
                s->next->zhi = temp;
                temp = s->xi;
                s->xi = s->next->xi;
                s->next->xi = temp;
                flag = 0;
            }
            if ( j < len3 - 2 - i )
                s = s->next;
        }
        if ( flag == 1 )
            break;//flag 为 1 表示上一次循环中没有发现(a[j] > a[j + 1])的情况，即已经排序完毕
        if ( i < len3 - 2 )
            r = r->next; // @@ Sort error: same as above; `r` should be reset to `first_3` each outer iteration, not advanced. Prevents proper sorting.
    }

   
    
    //输出除了0以外的
    r = first_3;
    while ( r->next != NULL )
    {
        if ( r->xi == 0 )
        {
            r = r->next;
        }   
        else
        {
            printf("%lld %lld ", r->xi, r->zhi);
            r = r->next;
        }
    }
    if ( r->xi != 0 )
    {
        printf("%lld %lld ", r->xi, r->zhi);
    }
    system("pause");
    return 0;
}