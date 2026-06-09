#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define node  struct Node 
#define nodeptr struct Node* 

struct Node 
{
    int coef;
    int index;
    struct Node *next;
}mult1,mult2,result;

char temp[2][10000] = {};
int pos1 = 0,pos2 = 0;
int Read1();
int Read2();
nodeptr new();
void Insert(nodeptr , nodeptr );
nodeptr search(int,nodeptr, nodeptr);

int main()
{
    #ifdef ACU
    freopen("in.txt","r",stdin);
    #endif
    nodeptr ptr1 = &mult1, *ptr2 = &mult2, *ptr3 = &result,*end = new();
    int tempc = 0,tempi = 0,count1=1,count2=1;
    result.next = end,end->index = -1,result.index = ~(1<<31);
    gets(temp[0]),gets(temp[1]);
    // ptr1->next = new(),ptr2->next = new();
    // ptr1 = ptr1->next,ptr2=ptr2->next;
    
    
    while (ptr1->coef = Read1(),(ptr1->index = Read1()) != EOF)
    {
        ptr1->next = new();
        ptr1 = ptr1->next;
        count1++;
    }
    while (ptr2->coef = Read2(),(ptr2->index = Read2()) != EOF)
    {
        ptr2->next = new();
        ptr2 = ptr2->next;
        count2++;
    }
    

    ptr1 = &mult1,ptr2 = &mult2;
    for (size_t i = 0; i < count1-1; i++)
    {
        for (size_t j = 0; j < count2-1; j++)
        {
            tempc = ptr1->coef * ptr2->coef,tempi = ptr1->index + ptr2->index;
            nodeptr tmp = search(tempi,ptr3,end);
            if (tempi == tmp->next->index)
            {
                tmp->next->coef += tempc;
            }
            else
            {
                nodeptr tempnode = new();
                tempnode->coef = tempc,tempnode->index = tempi;
                Insert(tempnode,tmp);
            }
            ptr2 = ptr2->next;
        }
        ptr2 = &mult2;
        ptr1 = ptr1->next;
    }
    
    ptr3 = result.next;
    while(ptr3->index != -1)
    {
        printf("%d %d ",ptr3->coef, ptr3->index);
        ptr3 = ptr3->next;
    }
    return 0;
}


int Read1()
{
    int i = 0,result = 0;
    if (temp[0][pos1+i] == 0)
    {
        return EOF;
    }
    while((temp[0][pos1+i] != ' ')&&(temp[0][pos1+i] != 0))
    {
        result*=10,result += temp[0][pos1+i]-'0';
        i++;
    }
    pos1+=i+1;
    return result;
}


int Read2()
{
    int i = 0,result = 0;
    if (temp[1][pos2+i] == 0)
    {
        return EOF;
    }
    while((temp[1][pos2+i] != ' ')&&(temp[1][pos2+i] != 0))
    {
        result*=10,result += temp[1][pos2+i]-'0';
        i++;
    }
    pos2+=i+1;
    return result;
}


nodeptr new()
{
    return (nodeptr)malloc(sizeof(node));
}


void Insert(nodeptr ptr,nodeptr pos)
{
    ptr->next = pos->next;
    pos->next = ptr;
}

nodeptr search(int tempi, nodeptr begin,nodeptr end)
{
    nodeptr temp = new();
    temp->next = begin;
    while (temp->next != end)
    {
        if (tempi >= temp->next->index)
        {
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}
