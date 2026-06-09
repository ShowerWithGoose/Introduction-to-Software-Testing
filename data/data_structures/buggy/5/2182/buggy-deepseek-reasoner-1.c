#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int xishu;
    int zhishu;
    struct Node *next;     
}Node;
Node *create(int xi,int zhi)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->xishu=xi;
    newnode->zhishu=zhi;
    newnode->next=NULL;
    return newnode;
}
void charu(Node **para,int xi,int zhi)
{
    Node *current=*para;
    if(current==NULL)
    *para=create(xi,zhi);
    else
    {
        while(current->next!=NULL)
        current=current->next;
        current->next=create(xi,zhi);
    }
}
Node *chengfa(Node *para1,Node *para2)
{
    Node *result=NULL;
    Node *current1=para1;
    while(current1!=NULL)
    {
        Node *current2=para2;
        while(current2!=NULL)
        {
            int xi=current1->xishu*current2->xishu;
            int zhi=current1->zhishu+current2->zhishu;
            Node *pre=NULL;
            Node *ptr=result;
            while(ptr!=NULL&&zhi<ptr->zhishu)
            {
                pre=ptr;
                ptr=ptr->next;
            }
            if(ptr!=NULL&&zhi==ptr->zhishu)
            ptr->xishu+=xi;
            else
            {
                Node *newNode=create(xi,zhi);
                newNode->next=ptr;
                if(pre!=NULL)
                pre->next=newNode;
                else
                result=newNode;
            }
            current2=current2->next;
        }
        current1=current1->next;
    }
    return result;
}
void print(Node *result)
{
    Node *current=result;
    while(current!=NULL)
    {
        printf("%d %d ",current->xishu,current->zhishu); // @@ Missing check for zero coefficient; should output only if current->xishu != 0
        current=current->next;
    }
}
int main()
{
    Node *para1=NULL;
    Node *para2=NULL;
    int x,z;
    char c;
    while(scanf("%d%d%c",&x,&z,&c)!=EOF)
    {
        if(c=='\n')
        break; // @@ The last term of the first polynomial is not added because break occurs before calling charu
        charu(&para1,x,z);    
    }
    while(scanf("%d%d%c",&x,&z,&c)!=EOF)
    {
        if(c=='\n')
        break; // @@ The last term of the second polynomial is not added because break occurs before calling charu
        charu(&para2,x,z);    
    }
    Node *result=chengfa(para1,para2);
    print(result);
    return 0;
}