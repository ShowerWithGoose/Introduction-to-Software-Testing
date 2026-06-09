#include<stdio.h>
#include<string.h>
#include<math.h>

int a[1000][3],b[1000][3];

struct node{
    int xishu;
    int mi;

}c[1000];

int cmp(struct node*a,struct node*b)
{
        return 0 - (a->mi)+(b->mi);
}

int main()
{
    int i,j,k,long1,long2,long3 = 0,temp1,temp2;
    char ch = '0';
    i = 1;
    while(ch != '\n')
    {

        scanf("%d%d%c",&a[i][1],&a[i][2],&ch);
        i++;
    }
    //printf("success%d\n",i);
    long1 = i - 1;
    ch = '0';
    i = 1;
    while(ch != '\n')
    {

        scanf("%d%d%c",&b[i][1],&b[i][2],&ch);
        i++;
    }
    //printf("success%d\n",i);
    long2 = i -1;
    //printf("%d %d\n",long1,long2);
    long3 = 1;
    for(i = 1;i <= long1;i++)
    {
        for(j = 1;j <= long2;j++)
        {
            temp1 = a[i][1]*b[j][1];
            temp2 = a[i][2]+b[j][2];
            for(k = 1;k <= long3;k++)
            {
                //printf("long3:%d",long3);
                if(temp2 == c[k].mi)
                {
                    c[k].xishu +=temp1;
                    break;
                }
                else if(k == long3)
                {
                    long3++;
                    c[k].mi = temp2;
                    c[k].xishu = temp1;
                    break;
                }
            }
        }
    }
    if(a[long1][2] == 0&&b[long2][2] == 0)
    {
        c[long3].mi = 0;
        c[long3].xishu = a[long1][1]*b[long2][1];
        long3++;
    }
    qsort(c+1,long3-1,sizeof(c[1]),cmp);
    for(i = 1;i <= long3 -1;i++)
    {
        printf("%d %d",c[i].xishu,c[i].mi);
        if(i != long3-1)
        {
            printf(" ");
        }
    }
    return 0;
}

