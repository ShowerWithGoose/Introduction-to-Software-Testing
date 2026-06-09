#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    int x1;
    int y1;
    int x2;
    int y2;
    int start;
    int core;
    }LINE;
//core记录当前线段所在连线最小编号的线段，用于同步长度
LINE lines[105];

int main()
{
    int connectsum[105];
    //读入总数
    int n,i,j,maxsum=1,record=0;
    scanf("%d",&n);
    //读入线段坐标
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
        lines[i].start=i;
        lines[i].core=i;
        connectsum[i]=1;
    }
    
    //遍历，寻找相连的
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(lines[i].x1==lines[j].x2&&lines[i].y1==lines[j].y2)
            {
                connectsum[lines[i].core]=connectsum[lines[j].core]+connectsum[lines[i].core];
                lines[j].core=lines[i].core;
                lines[i].start=lines[j].start;
                if(connectsum[lines[i].core]>maxsum)
                {
                    maxsum=connectsum[lines[i].core];
                    record=lines[j].start;
                }
            }
            if(lines[i].x2==lines[j].x1&&lines[i].y2==lines[j].y1)
            {
                connectsum[lines[i].core]=connectsum[lines[j].core]+connectsum[lines[i].core];
                lines[j].core=lines[i].core;
                lines[j].start=lines[i].start;
                if(connectsum[lines[i].core]>maxsum)
                {
                    maxsum=connectsum[lines[i].core];
                    record=lines[i].start;
                }
            }
        }
    }
    printf("%d %d %d",maxsum,lines[record].x1,lines[record].y1);

}
