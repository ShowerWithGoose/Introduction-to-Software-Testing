#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct t
{
    int xishu;
    int zhishu;
    struct t *next;
};
int main()
{
    struct t *p,*first1;
    struct t *q,*first2;
    int xi[300]={0},zhi[300]={0},middlexi,middlezhi;
    int a,b,count=0;
    int i,j,k;
    char x;
    p=first1=(struct t *)malloc(sizeof(struct t));
    p->next=NULL;
    q=first2=(struct t *)malloc(sizeof(struct t));
    q->next=NULL;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        p->next=(struct t *)malloc(sizeof(struct t));
        p=p->next;
        p->xishu=a;
        p->zhishu=b;
        p->next=NULL;
        scanf("%c",&x); // @@ scanf("%c") reads the whitespace character left in the input buffer by the previous scanf("%d%d"), which prevents correct detection of the newline character to break the loop.
        if(x=='\n')
        {
            break;
        }    
    }
    while((scanf("%d%d",&a,&b))!=EOF)
    {
        q->next=(struct t *)malloc(sizeof(struct t));
        q=q->next;
        q->xishu=a;
        q->zhishu=b;
        q->next=NULL;
        scanf("%c",&x); // @@ Same issue as above: reads whitespace instead of newline, causing potential infinite loop or incorrect parsing.
        if(x=='\n')
        {
            break;
        }
    }
    p=first1;
    q=first2;
    while(p->next!=NULL)
    {
        p=p->next;
        while(q->next!=NULL)
        {
            q=q->next;
            xi[count]=p->xishu*q->xishu;
            zhi[count]=p->zhishu+q->zhishu;
            count++;
        }
        q=first2;
    }
    for(i=0;i<count;i++)
    {
        for(j=i;j<count;j++) // @@ Array index out of bounds when j equals count-1, as it accesses zhi[j+1] and xi[j+1]. The loop condition should be j < count - 1.
        {
            if(zhi[j]<zhi[j+1])
            {
                middlezhi=zhi[j];
                zhi[j]=zhi[j+1];
                zhi[j+1]=middlezhi;
                middlexi=xi[j];
                xi[j]=xi[j+1];
                xi[j+1]=middlexi;
            }
        }
    }
    for(i=0;i<count;i++) // @@ Array index out of bounds when i equals count-1, as it accesses zhi[i+1] and xi[i+1]. The loop condition should be i < count - 1.
    {
        if(zhi[i]==zhi[i+1]&&xi[i]!=0&&xi[i+1]!=0)
        {
            xi[i]=xi[i]+xi[i+1];
            for(j=i+1;j<count;j++) // @@ Array index out of bounds when j equals count-1, accessing xi[j+1] and zhi[j+1]. The loop condition should be j < count - 1. Also, count must be decremented after merging to avoid printing extra terms.
            {
                xi[j]=xi[j+1];
                zhi[j]=zhi[j+1];
            }
            i--;
        }
    }
    for(i=0;i<count;i++)
    {
        if(xi[i]!=0)
        {
        printf("%d %d ",xi[i],zhi[i]);
        }
    }
    return 0;
}