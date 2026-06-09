#include <stdio.h>
#include <stdlib.h>

struct point{
    int a[2];
    int b[2];
}point[200],tmp;


int main()
{
    int i,j,k, n, a, b, l;
    int max = 0,flag = 0;
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d%d%d%d",&point[i].a[0],&point[i].a[1],&point[i].b[0],&point[i].b[1]);
    }
    for(i = 0;i<n;i++)
    {
        flag = 0;
        for(j = i + 1;j<n;j++)
        {
            if(point[j].a[0] < point[i].a[0])
            {
                tmp = point[j];
                point[j] = point[i];
                point[i] = tmp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }//arrange the first point
    
    for(i = 0;i<n;i++)
    {
        l = 1;
        k = i;
        for(j = i + 1;j<n;j++)
        {
            if(point[j].a[0] == point[k].b[0] && point[j].a[1] == point[k].b[1])
            {
                l++;
                k = j;
            }
        }//if same point, length + 1
        if(l > max)
        {
            max = l;
            a = point[i].a[0];
            b = point[i].a[1];
        }//if longer, renew
    }
    
    printf("%d %d %d",max,a,b);
    return 0;
}

