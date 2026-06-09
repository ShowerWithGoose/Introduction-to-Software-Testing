#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    int number;
    int multi;
    struct node *next;
}linklist;
//multi为指数,number为系数


//把当前项temp插入到适当位置，并返回头节点指针
linklist* insert(linklist *first,linklist n)
{
    linklist *q,*temp;
    temp=(linklist*)malloc(sizeof(linklist));
    temp->multi=n.multi;
    temp->number=n.number;
    temp->next=NULL;
    int flag=0;
    if(first==NULL)
    {
        first=temp;
        return first;
    }
    else if(temp->multi>first->multi)
    {
        temp->next=first;
        first=temp;
        return first;
    }
    q=first;
    while(q!=NULL)
    {
        if(temp->multi==q->multi)
        {
            q->number+=temp->number;
            flag=1;
            break;
        }
        else if(q->next==NULL)
        {
            if(flag==0)
            {
                q->next=temp;
                temp->next=NULL;
                break;
            }
        }
        else if(temp->multi<q->multi&&temp->multi>q->next->multi)
        {
            temp->next=q->next;
            q->next=temp;
            flag=1;
            break;
        }

        q=q->next;
    }

    return first;
}

//打印用函数
void print(linklist* first)
{
    linklist*q;
    q=first;
    while(q!=NULL)
    {
        if(q->number!=0) printf("%d %d ",q->number,q->multi);
        q=q->next;
    }
}

//删除链表
void delete(linklist* first)
{
    linklist *q,*t;
    q=first;
    while(q!=NULL)
    {
        t=q;
        q=q->next;
        free(t);
    }
}

int main()
{
    linklist line1[1005],line2[1005],now;
    int num1=0,num2=0,i,j;
    char ch;
    //读入
    while(1)
    {
        scanf("%d",&line1[num1].number);
        ch=getchar();
        scanf("%d",&line1[num1++].multi);
        ch=getchar();
        if(ch=='\n') break;
    }
    while(1)
    {
        scanf("%d",&line2[num2].number);
        ch=getchar();
        scanf("%d",&line2[num2++].multi);
        ch=getchar();
        if(ch=='\n') break;
    }
    linklist *first;
    first=NULL;

    //逐项相乘
    for(i=0;i<num1;i++)
    {
        for(j=0;j<num2;j++)
        {
            now.multi=line1[i].multi+line2[j].multi;
            now.number=line1[i].number*line2[j].number;
            first=insert(first,now);
        }
    }

    print(first);
    delete(first);
}

