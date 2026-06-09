#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int x1,x2,y1,y2;
}Dot;
Dot d[2000];
int N,pre[2000],len[2000];
int cmp(const void *a,const void *b)
{
    Dot A=*(Dot*)a,B=*(Dot*)b;
    if(A.x1>B.x1) return 1;
    if(A.x1<B.x1) return -1;
    if(A.x1==B.x1)
    {
        if(A.y1>B.y1) return 1;
        if(A.y1<B.y1) return -1; 
    }
    return 0;
}


int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d%d%d%d",&d[i].x1,&d[i].y1,&d[i].x2,&d[i].y2);
    qsort(d+1,N,sizeof(Dot),cmp);
    /*for(int i=1;i<=N;i++)
    {
    	printf("%d %d\n",d[i].x1,d[i].y1);
	}*/
    for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j++)
        {
            if(d[j].x1==d[i].x2&&d[j].y1==d[i].y2)
            {
                if(len[j]<len[i]+1)
                {
                    len[j]=len[i]+1;
                    pre[j]=i;
                }
            }
        }
    }
    int pos_max=0,mmax=0,ppre;
    for(int i=1;i<=N;i++)
    {
        if(mmax<len[i]) 
        {
            mmax=len[i];
            pos_max=i;
        }
    }
    ppre=pre[pos_max];
    while(pre[ppre])
    {
        ppre=pre[ppre];
    }
    printf("%d %d %d",len[pos_max]+1,d[ppre].x1,d[ppre].y1);
    return 0;
}

