#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct _x{
    int a;
    int n;
    struct _x *next;
}X;

int main()
{
    int a1[114]={0}, n1[114]={0}, *a2, *n2, scan=0,totalLeng,leng1,leng2;
    while(scanf("%d %d",&a1[scan],&n1[scan])!=EOF)
    {
        //printf("%d %d ",a1[scan],n1[scan]);
        scan++;
    }
    totalLeng=scan-1;
    scan=1;
    while(n1[scan-1]>n1[scan])
        scan++;
    leng1=scan-1;
    leng2=totalLeng-leng1;
    a2=&a1[scan];
    n2=&n1[scan];
    int scan1=0,scan2=0,tempA,tempN,chainLeng=0,chainScan=1,isInserted=0;
    X *start,*currentNode,*tempPtr;
    start=(X*) malloc(sizeof(X));
    currentNode=start;
    currentNode->next=NULL;
    while(scan1<=leng1)
    {
        scan2=0;
        while(scan2<leng2)
        {
            tempA=a1[scan1]*a2[scan2];
            tempN=n1[scan1]+n2[scan2];
            chainScan=1;
            currentNode=start;
            isInserted=0;
            while(chainScan<=chainLeng)
            {
                if(currentNode->next->n==tempN)
                {
                    currentNode->next->a+=tempA;
                    isInserted=1;
                    break;
                }
                else if(currentNode->next->n<tempN)
                {
                    tempPtr=(X*) malloc(sizeof(X));
                    tempPtr->a=tempA;
                    tempPtr->n=tempN;
                    tempPtr->next=currentNode->next;
                    currentNode->next=tempPtr;
                    isInserted=1;
                    chainLeng++;
                    break;
                }
                chainScan++;
                currentNode=currentNode->next;
            }
            if(!isInserted)
            {
                if(currentNode->next!=NULL)
                    currentNode=currentNode->next;
                tempPtr=(X*) malloc(sizeof(X));
                currentNode->next=tempPtr;
                currentNode=currentNode->next;
                chainLeng++;
                currentNode->a=tempA;
                currentNode->n=tempN;
                currentNode->next=NULL;
            }
            scan2++;
        }
        scan1++;
    }

    currentNode=start->next;
    while(currentNode!=NULL)
    {
        printf("%d %d ",currentNode->a,currentNode->n);
        currentNode=currentNode->next;
    }
    return 0;
}
