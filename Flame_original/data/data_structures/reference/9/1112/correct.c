#include <stdio.h>
struct line
{
    int x;
    int y;
    int num_line;
    int ox;
    int oy;
} a[100];
struct duan
{
    int m1;
    int n1;
    int m2;
    int n2;
}b[100];


int main()
{
    int n,i,num=0,j,k1=0,k2=0,k3=0,u;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&b[i].m1,&b[i].n1,&b[i].m2,&b[i].n2);
    }
    for (u  = 0; u < n; u++)
    {
       for ( i = 0; i <n; i++)
    {
        for(j=0;j<=num;j++)
        {
            if (j==num)
            {
                 num++;
            a[j].ox=b[i].m1;
            a[j].oy=b[i].n1;
            a[j].x=b[i].m2;
            a[j].y=b[i].n2;
            a[j].num_line=1;
            break;
            }
            if (a[j].x==b[i].m1&&a[j].y==b[i].n1)
            {
                a[j].num_line++;
                a[j].x=b[i].m2;
                a[j].y=b[i].n2;
                break;
            }
            if (a[j].ox==b[i].m2&&a[j].oy==b[i].n2)
            {
                a[j].num_line++;
                a[j].ox=b[i].m1;
                a[j].oy=b[i].n1;
                break;
            }
        }
    } /* code */
    }
    
    
    
    
    for(i=0;i<num;i++)
    {
        if (a[i].num_line>k1)
        {
            k1=a[i].num_line;
            k2=a[i].ox;
            k3=a[i].oy;
        }
    }
    printf("%d %d %d",k1,k2,k3);
    return 0;
}
