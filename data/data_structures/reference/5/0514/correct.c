#include <stdio.h>
#include <stdlib.h>


typedef struct elem {
        int a;
        int b;
        struct elem* link;
    }elem, *LinkList;

void swaps(int a[][2], int i, int j)
{
    int temp1, temp2;
    temp1 = a[i][0];
    temp2 = a[i][1];
    a[i][0] = a[j][0];
    a[i][1] = a[j][1];
    a[j][0] = temp1;
    a[j][1] = temp2;
}


int min(int a[][2], int n)//n个字符串中找最小
{
    int i, j=0;
    for (i=1; i<n; i++)
    {
        if(a[i][1]<a[j][1])
        {
            j=i;
        }
    }
    return j;
}

void selectsort(int a[][2], int len)//从大到小排序
{
    int i, j;
    for (i=len; i>1; i--)
    {
        j = min(a, i);
        swaps(a, i-1, j);
    }
}

int main()
{
    fflush(stdin);
    LinkList r1, r2, p1, p2, list1=NULL, list2=NULL;
    int x, y;
    int n1=0, n2=0;
    while (scanf("%d%d", &x, &y))
    {
        n1++;
        p1 = (LinkList)malloc(sizeof(elem));
        p1->a = x;
        p1->b = y;
        p1->link = NULL;

        if (list1==NULL)
        {
            list1 = p1;
        }
        else
        {
            r1->link = p1;
        }
        r1 = p1;

        if(getchar()=='\n')
            break;
    }

    while (scanf("%d%d", &x, &y))
    {
        n2++;
        p2 = (LinkList)malloc(sizeof(elem));
        p2->a = x;
        p2->b = y;
        p2->link = NULL;

        if (list2==NULL)
        {
            list2 = p2;
        }
        else
        {
            r2->link = p2;
        }
        r2 = p2;

        if(getchar()=='\n')
            break;
    }
    int n = n1*n2;
    int ans[n][2], j, k;

    p1=list1, p2=list2;

    //printf("%d %d %d\n", n1, n2, n);

    for (j=0; j<n1; j++)
    {
        for (k=0; k<n2; k++)
        {
            ans[j*n2+k][0]=(p1->a)*(p2->a);
            ans[j*n2+k][1]=(p1->b)+(p2->b);
            p2 = p2->link;
        }
        p2 = list2;
        p1 = p1->link;
    }

    selectsort(ans, n);

    LinkList p3, r3, list3=NULL;

    for (int m=0; m<n; m++)
    {
        p3 = (LinkList)malloc(sizeof(elem));
        p3->a = ans[m][0];
        p3->b = ans[m][1];
        p3->link = NULL;

        if (list3==NULL)
        {
            list3 = p3;
        }
        else
        {
            r3->link = p3;
        }
        r3 = p3;
    }

    p3 = list3;
    LinkList q3;
    while(p3!=NULL)
    {
        r3 = p3->link;
        q3 = p3;
        while(r3!=NULL)
        {
            if ((p3->b)==(r3->b))
            {
                (p3->a)+=(r3->a);
                if((r3->link)!=NULL)
                {
                    q3->link = q3->link->link;
                }
                else
                {
                    q3->link->link = NULL;
                }
                r3 = q3;
            }
            q3 = r3;
            r3 = r3->link;
        }
        p3 = p3->link;
    }

    p3 = list3;

    while(p3!=NULL)
    {
        printf("%d %d ", p3->a, p3->b);
        p3 = p3->link;
    }

    /*for (int m=0; m<n; m++)
    {
        printf("%d %d ", ans[m][0], ans[m][1]);
    }*/
    return 0;
}

