#include<stdio.h>
#include<string.h>
#include<math.h>
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
};
int x[100],y[100];
int i, n, j, k, t, p;
int main()
{
    struct line a[100];
    scanf("%d",&n);
    getchar();
    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        getchar();
        a[i].num = 1;
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i].x2 == a[j].x1 && a[i].y2 == a[j].y1)
            {
                a[i].x2 = a[j].x2;
                a[i].y2 = a[j].y2;
                a[i].num = a[i].num + a[j].num;
                x[i] = a[i].x1;
                y[i]= a[i].y1;
                i--;
                j = n;
            }
        }
    }

    int ans = 0,cnt = 0;
    for(i = 0; i < n; i++)
    {
        if(ans < a[i].num)
        {
            ans = a[i].num;
            cnt = i;
        }
    }
    printf("%d %d %d",ans,x[cnt],y[cnt]);
    return 0;
}



