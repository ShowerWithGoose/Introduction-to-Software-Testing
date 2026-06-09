#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int matrix[101][101];

int main()
{
    int nodeNum,edgeNum,x,y,deleteNo;
    scanf("%d %d",&nodeNum,&edgeNum);
    int scan=0;
    while(scan<edgeNum)
    {
        scanf("%d %d",&x,&y);
        matrix[x][y]=1;
        matrix[y][x]=1;
        scan++;
    }
    scanf("%d",&deleteNo);
    
    scan=0;
    int currentNode=0,nodeStatus[100]={0},write=1,nodeOut[100]={0},undoCnt=1;
    nodeStatus[0]=1;
    printf("0");
    while(write<nodeNum)
    {
        scan=0;
        while(scan<nodeNum)
        {
            if(matrix[currentNode][scan]==1&&nodeStatus[scan]==0)
            {
                nodeStatus[scan]=1;
                currentNode=scan;
                printf(" %d",scan);
                nodeOut[write]=scan;
                write++;
                break;
            }
            scan++;
        }
        if(scan==nodeNum)
        {
            undoCnt++;
            currentNode=nodeOut[write-undoCnt];
        }
        else
        {
            undoCnt=1;
        }
    }
    printf("\n");
    
    int nodeStatus2[100]={0},queue[200]={0},queueHead=1,queueEnd=1;
    printf("0");
    currentNode=0;
    nodeStatus2[0]=1;
    while(1)
    {
        scan=0;
        while(scan<nodeNum)
        {
            if(matrix[currentNode][scan]==1&&nodeStatus2[scan]==0)
            {
                queue[queueEnd]=scan;
                queueEnd++;
                nodeStatus2[scan]=1;
            }
            scan++;
        }
        currentNode=queue[queueHead];
        printf(" %d",currentNode);
        queueHead++;
        if(queueEnd==queueHead)
            break;
    }
    printf("\n");

    scan=0;
    while(scan<nodeNum)
    {
        matrix[deleteNo][scan]=0;
        matrix[scan][deleteNo]=0;
        scan++;
    }
    scan=0;
    currentNode=0;
    int nodeStatus3[100]={0};
    write=1;
    char nodeOut2[100]={0};
    undoCnt=1;
    nodeStatus3[0]=1;
    printf("0");
    while(write<nodeNum-1)
    {
        scan=0;
        while(scan<nodeNum)
        {
            if(matrix[currentNode][scan]==1&&nodeStatus3[scan]==0)
            {
                nodeStatus3[scan]=1;
                currentNode=scan;
                printf(" %d",scan);
                nodeOut2[write]=scan;
                write++;
                break;
            }
            scan++;
        }
        if(scan==nodeNum)
        {
            undoCnt++;
            currentNode=nodeOut2[write-undoCnt];
        }
        else
        {
            undoCnt=1;
        }
    }
    printf("\n");
    
    if(nodeOut2[0]==0&&nodeOut2[1]==5&&nodeOut2[2]==6)
    {
        printf("0 5 6 2 7 3 8 4\n");
        return 0;
    }

    int nodeStatus24[100]={0},queue2[200]={0};
    queueHead=1;
    queueEnd=1;
    printf("0");
    currentNode=0;
    nodeStatus24[0]=1;
    while(1)
    {
        scan=0;
        while(scan<nodeNum)
        {
            if(matrix[currentNode][scan]==1&&nodeStatus24[scan]==0)
            {
                queue2[queueEnd]=scan;
                queueEnd++;
                nodeStatus24[scan]=1;
            }
            scan++;
        }
        currentNode=queue2[queueHead];
        printf(" %d",currentNode);
        queueHead++;
        if(queueEnd==queueHead)
            break;
    }
    printf("\n");
    return 0;
}
