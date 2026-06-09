#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
typedef int ElemType[2];
typedef struct node{
    ElemType data;
    struct node * link1;
    struct node * link2;
}LNode,* LinkList;
int main()
{
    int n,i,j,num=0,max=0,x,y,x1,y1;
    LinkList p[105],q[105],r;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        p[i]=(LinkList)malloc(sizeof(LNode));
        q[i]=(LinkList)malloc(sizeof(LNode));
        scanf("%d %d %d %d",&p[i]->data[0],&p[i]->data[1],&q[i]->data[0],&q[i]->data[1]);
        p[i]->link2=q[i];
        p[i]->link1=NULL;
        q[i]->link1=p[i];
        q[i]->link2=NULL;
    }
    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            if ((p[i]->data[0]==q[j]->data[0])&&(p[i]->data[1]==q[j]->data[1]))
            {
                q[i]->link1=q[j];
                q[j]->link2=q[i];
            }
            if ((q[i]->data[0]==p[j]->data[0])&&(q[i]->data[1]==p[j]->data[1]))
            {
                q[i]->link2=q[j];
                q[j]->link1=q[i];
            }
        }
    }
    /*while (p[6]!=NULL)
    {
        num++;
        printf("%d %d %d\n",num,p[6]->data[0],p[6]->data[1]);
        p[6]=p[6]->link2;
    }*/
    for (i=1;i<=n;i++)
    {
        num=0;
        while (q[i]!=NULL)
        {
            num++;
            if (q[i]->link1==NULL)
            {
                x=q[i]->data[0];
                y=q[i]->data[1];
            }
            q[i]=q[i]->link1;
        }
        if (num>max)
        {
            max=num;
            x1=x;
            y1=y;
        }
    }
    printf("%d %d %d",max-1,x1,y1);
    return 0;
}

