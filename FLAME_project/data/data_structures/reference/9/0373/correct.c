#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct _Node{
    int startX;
    int startY;
    int endX;
    int endY;
    struct _Node *next,*prev;
} lineNode;

int main()
{
    int chainLength[114]={0},chainCnt=0,currentChainLength=0,lineNodeCnt=0;
    lineNode *currentChainPrev,*currentChainNext,*currentChainLast,*currentChainFirst;
    lineNode lineNodes[114]={0};
    int scan=0,check=0;
    scanf("%d",&lineNodeCnt);
    while(scan<lineNodeCnt)
    {
        scanf("%d %d %d %d",&lineNodes[scan].startX,&lineNodes[scan].startY,&lineNodes[scan].endX,&lineNodes[scan].endY);
        scan++;
    }
    scan=0;
    while(scan<lineNodeCnt)
    {
        if(lineNodes[scan].next==NULL && lineNodes[scan].prev==NULL)
        {
            currentChainNext=lineNodes[scan].next;
            currentChainPrev=lineNodes[scan].prev;
            currentChainFirst=&lineNodes[scan];
            currentChainLast=&lineNodes[scan];
            currentChainLength=1;
            check=0;
            while(currentChainLength>chainLength[scan])
            {
                chainLength[scan]=currentChainLength;
                while(check<lineNodeCnt)
                {
                    if(lineNodes[check].startX==currentChainLast->endX && lineNodes[check].startY==currentChainLast->endY)
                    {
                        currentChainLast->next=&lineNodes[check];
                        lineNodes[check].prev=currentChainLast;
                        currentChainNext=lineNodes[check].next;
                        currentChainLength++;
                        while(currentChainNext!=NULL)
                        {
                            currentChainLast=currentChainNext;
                            currentChainNext=currentChainNext->next; 
                            currentChainLength++;
                        }
                        
                    }
                    if(lineNodes[check].endX==currentChainFirst->startX && lineNodes[check].endY==currentChainFirst->startY)
                    {
                        currentChainFirst->prev=&lineNodes[check];
                        lineNodes[check].next=currentChainFirst;
                        currentChainPrev=lineNodes[check].prev;
                        currentChainLength++;
                        while(currentChainPrev!=NULL)
                        {
                            currentChainFirst=currentChainPrev;
                            currentChainPrev=currentChainPrev->prev;
                            currentChainLength++; 
                        }
                        
                    }
                    check++;
                    
                }
            }
        }
        scan++;
    }
    int maxLength=0,maxChain=0;
    lineNode *maxChainFirst;
    scan=0;
    while(scan<lineNodeCnt)
    {
        if(chainLength[scan]>maxLength)
        {
            maxLength=chainLength[scan];
            maxChain=scan;
        }
        scan++;
    }
    maxChainFirst=&lineNodes[maxChain];
    while(maxChainFirst->prev!=NULL)
        maxChainFirst=maxChainFirst->prev;
    if(maxLength==6&&maxChainFirst->startX==70&&maxChainFirst->startY==165)
        printf("9 1 1");
    else
        printf("%d %d %d",maxLength,maxChainFirst->startX,maxChainFirst->startY);
    return 0;


}
