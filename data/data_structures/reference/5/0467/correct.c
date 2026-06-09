#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int len1 = 0, len2 = 0, len_ans = 0;

struct fx
{
    int mi, xi;
    struct fx *link_l, *link_r;
} a1[10005], a2[10005], ans[10005];

int main()
{
    a1[0].link_l = a1[0].link_r = NULL;
    a2[0].link_l = a2[0].link_r = NULL;
    int max_pos = 1;
    struct fx *p;
    while (1)
    {
        char c;
        len1 ++;
        scanf("%d%d", &a1[len1].xi, &a1[len1].mi);
        c = getchar();
        if (c == '\n') break;
    }
    while (1)
    {
        char c;
        len2 ++;
        scanf("%d%d", &a2[len2].xi, &a2[len2].mi);
        c = getchar();
        if (c == '\n') break;
    }
    for (int i = 1; i <= len1; i ++ )
    {
        for (int j = 1; j <= len2; j ++ )
        {
            p = ans + max_pos;
            if (len_ans == 0)
            {
                len_ans ++;
                ans[len_ans].mi = a1[i].mi + a2[j].mi;
                ans[len_ans].xi = a1[i].xi * a2[j].xi;
                ans[len_ans].link_l = ans[len_ans].link_r = NULL;
            }
            else
            {
                int mm = a1[i].mi + a2[j].mi, xx = a1[i].xi * a2[j].xi;
                while (1)
                {
                    if (mm < p->mi && p->link_r == NULL)
                    {
                        len_ans ++;
                        ans[len_ans].mi = mm;
                        ans[len_ans].xi = xx;
                        p->link_r = ans + len_ans;
                        ans[len_ans].link_l = p;
                        break;
                    }
                    if (mm > p->mi)
                    {
                        if (p->link_l == NULL)
                        {
                            len_ans ++;
                            ans[len_ans].mi = mm;
                            ans[len_ans].xi = xx;
                            ans[len_ans].link_r = p;
                            p->link_r = ans + len_ans;
                            max_pos = len_ans;
                            break;
                        }
                        len_ans ++;
                        ans[len_ans].mi = mm;
                        ans[len_ans].xi = xx;
                        ans[len_ans].link_r = p;
                        ans[len_ans].link_l = p->link_l;
                        p->link_l->link_r = ans + len_ans;
                        p->link_l = ans + len_ans;
                        break;
                    }
                    if (mm == p->mi) 
                    {
                        p->xi += xx;
                        break;
                    }
                    p = p->link_r;
                }
                
            }
        }
    }
    p = ans + max_pos;
    while (p != NULL)
    {
        printf("%d %d ", p->xi, p->mi);
        p = p->link_r;
    }
    return 0;
}
