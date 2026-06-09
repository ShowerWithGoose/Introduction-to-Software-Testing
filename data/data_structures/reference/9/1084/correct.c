#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define ull unsigned long long

struct line
{
    int x1,y1,x2,y2;
} l[102],re[102];

int main()
{
    int n,i,j,k=0,hl[102]={0},rl[102]={0},r=0;
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
    }
    for ( i = 0; i < n ; i++)
    {
        if (hl[i])continue;
        else 
        {
            hl[i]++;
            re[k].x1=l[i].x1;
            re[k].y1=l[i].y1;
            re[k].x2=l[i].x2;
            re[k].y2=l[i].y2;
            for ( j = 0; j < n ; j++)
            {
                if (j==i||hl[j])continue;
                else
                {
                    if (re[k].x1==l[j].x2&&re[k].y1==l[j].y2)
                    {
                        re[k].x1=l[j].x1;
                        re[k].y1=l[j].y1;
                        rl[k]++;
                        hl[j]++;
                        j=0;
                    }
                    else if (re[k].x2==l[j].x1&&re[k].y2==l[j].y1)
                    {
                        re[k].x2=l[j].x2;
                        re[k].y2=l[j].y2;
                        rl[k]++;
                        hl[j]++;
                        j=0;
                    }
                }
            }
            k++;
        }
    }
    for ( i = 1; i < k; i++)
    {
        if (rl[r]<rl[i]) r=i;
    }
    printf("%d %d %d",rl[r]+1,re[r].x1,re[r].y1);
    return 0;
}
