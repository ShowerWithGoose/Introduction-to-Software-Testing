#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    int content;
    int index;
    struct node* pNext; 
}NODE,*PNODE;
PNODE creat_list();
void print_result(PNODE,PNODE,PNODE);
void sort_list(PNODE,int);
void combine_list(PNODE,int);
    NODE result[1000005];
int main()
{

    PNODE pHead1,pHead2;
    pHead1=creat_list();
    pHead2=creat_list();
    print_result(pHead1,pHead2,result);
    
    return 0;
}
PNODE creat_list()
{
    int content,index;
    char c;
    PNODE pHead=(PNODE)malloc(sizeof(NODE));
    if(pHead==NULL)
    {
        printf("NO!!!!");
        exit(-1);
    }
    PNODE pTail=pHead;
    pTail->pNext=NULL;
    do
    {
        scanf("%d%d%c",&content,&index,&c);
        PNODE pNew=(PNODE)malloc(sizeof(NODE));
        if(pNew==NULL)
        {
            printf("NO!!!!");
            exit(-1);
        }
        pNew->content=content;
        pNew->index=index;
        pNew->pNext=NULL;
        pTail->pNext=pNew;
        pTail=pNew;        
    }
    while(c!='\n');
    return pHead;
}

void print_result(PNODE pHead1,PNODE pHead2,PNODE result)
{
    PNODE p,q;
    int i,j;
    int mark=0;
    for(i=0,p=pHead1->pNext;p!=NULL;p=p->pNext)
    {
        for(j=0,q=pHead2->pNext;q!=NULL;q=q->pNext)
        {
            result[mark].content=p->content*q->content;
            result[mark].index=p->index+q->index;
            mark++;
        }
    }
    sort_list(result,mark);
    combine_list(result,mark);
    for(int i=0;i<mark;i++) // @@ The loop iterates up to the original 'mark' (total terms before combination), but 'combine_list' invalidates some entries by setting index to -1. While the check inside handles this, the logic in combine_list is flawed leading to incorrect aggregation.
    {
        if(result[i].index>=0&&result[i].content!=0)
        printf("%d %d ",result[i].content,result[i].index);
    }
    return ;
}

void sort_list(PNODE result,int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            
            if(result[i].index<result[j].index)
            {
                NODE temp;
                temp=result[i];
                result[i]=result[j];
                result[j]=temp;                
            }
        }
    }
}

void combine_list(PNODE result,int len)
{
    for(int i=0;i<len-1;i++)
    {
        int time=0;
        for(int j=i+1;j<len;j++)
        {
            if(result[i].index==result[j].index)
            {
                result[i].content+=result[j].content;
                result[j].index=-1;
                time++;
            }
            else
            {
                i+=time; // @@ This line incorrectly modifies the outer loop variable 'i' inside the inner loop based on a local counter 'time'. This causes the outer loop to skip indices improperly and fails to correctly aggregate all terms with the same exponent, especially when there are more than 2 terms with the same exponent or when gaps exist. The standard approach is to simply continue the inner loop and let the outer loop increment naturally, or use a different strategy to merge adjacent sorted elements.
            }
                
        }
    }
    
    return ;
}