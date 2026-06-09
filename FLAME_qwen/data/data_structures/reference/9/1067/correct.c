#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#define maxn 1000
typedef struct
{
    int x;
    int y;
}Point;
Point point[maxn];

int fa[maxn];
int chi[maxn];

void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        chi[i] = i;
    }
}

void merge(int i, int j)
{
    fa[i] = j;
    chi[j] = i;
}

int Comp(const void *a, const void *b)
{
    int *A = (int *)(a);
    int *B = (int *)(b);
    return(*B - *A);
}
int main()
{
    int n;
    int x1, y1, x2, y2;
    scanf("%d", &n);
    int j = 0;
    init(maxn);
    for (int i = 1; i <= n; ++ i)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int flag1 = 0;
        int p1;
        int k;
        for(k = 1; k <= j; k ++)
        {
            if(x1 == point[k].x && y1 == point[k].y)
            {
                flag1 = 1;
                break;
            }  
        }
        if(flag1 == 0)
        {
            point[j + 1].x = x1;
            point[j + 1].y = y1;
            j ++;
        }
        p1 = k;
        int flag2 = 0;
        int p2;
        for(k = 1; k <= j; k ++)
        {
            if(x2 == point[k].x && y2 == point[k].y)
            {
                flag2 = 1;
                break;
            }  
        }
        if(flag2 == 0)
        {
            point[j + 1].x = x2;
            point[j + 1].y = y2;
            j ++;
        }    
        p2 = k; 
        merge(p1, p2);
    }
    int cnt = j;
    int sum = 0, max = 0;
    int mp;
    for(int i = 1; i <= cnt; i ++)
    {
        if(fa[i] == i)
        {
            j = i; sum = 0;
            while(chi[j] != j)
            {
                sum ++;
                j = chi[j]; 
            }
        }
        if(sum > max)
        {
            max = sum;
            mp = i; 
        }
    }
    int mx = point[mp].x, my = point[mp].y;
    int i = mp;
    while(chi[i] != i)
    {
        if(point[chi[i]].x < point[i].x)
        {
            mx = point[chi[i]].x;
            my = point[chi[i]].y;
        }
        i = chi[i];
    }
    printf("%d %d %d", max, mx, my);
    return 0;
}
//another que
