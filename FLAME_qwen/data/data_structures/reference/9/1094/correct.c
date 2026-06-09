#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Node{
    int x1;
    int y1;
    int x2;
    int y2;
    int flag;
}node[1000];
int cmp1(const struct Node *a,const struct Node *b)
{

    if((a->x1)-(b->x1)>0) return 1;
    else if((a->x1)-(b->x1)<0) return -1;
    else if((a->x1)==(b->x1))
    {
        return ((a->y1)-(b->y1));
    }
}

int main()
{
    int n,m=0,max=-1,maxid,sum[1000],i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&node[i].x1,&node[i].y1,&node[i].x2,&node[i].y2);
        sum[i]=1;
        node[i].flag=0;
    }
    qsort(node,n,sizeof(node[0]),cmp1);
    for( i=0;i<n;i++)
    {
        if(node[i].flag==0)
        {
        int k=i;
        node[i].flag=1;
        for(int j=k+1;j<n;j++)
        {
            if(node[j].x1==node[k].x2&&node[j].y1==node[k].y2)
            {
                sum[i]=sum[i]+1;
                k=j;
                node[j].flag=1;
            }
        }
        }
    }
    for(int j=0;j<n;j++)
    {
        if(sum[j]>max)
        {
            max=sum[j];
            maxid=j;
        }
    }
    printf("%d %d %d",max,node[maxid].x1,node[maxid].y1);
}

