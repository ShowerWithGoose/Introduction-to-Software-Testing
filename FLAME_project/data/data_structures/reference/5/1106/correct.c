#include<stdio.h>
#include<stdlib.h>
typedef struct polynomial
{
    long long expo;
    long long fact;
    struct polynomial *link;
}*nodePtr,node;
void insert(nodePtr prevNode,long long expo,long long fact);
int main()
{
    long long tmpExpo,tmpFact;
    char space;
    nodePtr y1=(nodePtr)malloc(sizeof(node));
    nodePtr y2=(nodePtr)malloc(sizeof(node));
    nodePtr res=(nodePtr)malloc(sizeof(node));
    nodePtr ptr,mul1,mul2;
    y1->link=NULL;
    y2->link=NULL;
    res->link=NULL;
    ptr=y1;
    do
    {
        scanf("%lld%lld%c",&tmpFact,&tmpExpo,&space);
        insert(ptr,tmpExpo,tmpFact);
    } while (space!='\n');
    ptr=y2;
    do
    {
        scanf("%lld%lld%c",&tmpFact,&tmpExpo,&space);
        insert(ptr,tmpExpo,tmpFact);
    } while (space!='\n');
    mul1=y1->link;
    mul2=y2->link;
    ptr=res;
    while(mul1!=NULL)
    {
        mul2=y2->link;
        while(mul2!=NULL)
        {
            ptr=res;
            tmpExpo=mul1->expo+mul2->expo;
            tmpFact=mul1->fact*mul2->fact;
            while(1)
            {
                if(ptr->link==NULL)
                {
                    insert(ptr,tmpExpo,tmpFact);
                    break;
                }
                if(ptr->link->expo<tmpExpo)
                {
                    insert(ptr,tmpExpo,tmpFact);
                    break;
                }
                if(ptr->link->expo==tmpExpo)
                {
                    ptr->link->fact+=tmpFact;
                    break;
                }
                ptr=ptr->link;
            }
            mul2=mul2->link;
        }
        mul1=mul1->link;
    }
    ptr=res->link;
    while(ptr!=NULL)
    {
        printf("%lld %lld ",ptr->fact,ptr->expo);
        ptr=ptr->link;
    }
    while(y1!=NULL)
    {
        ptr=y1;
        y1=y1->link;
        free(ptr);
    }
    while(y2!=NULL)
    {
        ptr=y2;
        y2=y2->link;
        free(ptr);
    }
    while(res!=NULL)
    {
        ptr=res;
        res=res->link;
        free(ptr);
    }
    return 0;
}
void insert(nodePtr prevNode,long long expo,long long fact)
{
    nodePtr newNode=(nodePtr)malloc(sizeof(node));
    newNode->expo=expo;
    newNode->fact=fact;
    newNode->link=prevNode->link;
    prevNode->link=newNode;
    return;
}
