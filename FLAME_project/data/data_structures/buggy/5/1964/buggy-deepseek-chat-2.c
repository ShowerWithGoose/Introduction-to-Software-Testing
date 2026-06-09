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
    for(int i=0;i<mark;i++)
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
                i+=time; // @@ [Error: This modifies the loop variable i incorrectly, causing some terms to be skipped or not combined properly. The logic for skipping combined terms is flawed; it should not add time to i inside the inner loop, as it disrupts the outer loop iteration.]
            }
                
        }
    }
    
    return ;
}