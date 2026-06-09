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
    int xi[300]={0},zhi[300]={0},middlexi,middlezhi; // @@ [Fixed array size may overflow if the number of product terms exceeds 300]
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
        scanf("%c",&x);
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
        scanf("%c",&x);
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
        for(j=i;j<count;j++) // @@ [Incorrect loop bounds for sorting; should be j<count-1 to avoid out-of-bounds and to perform a correct bubble sort]
        {
            if(zhi[j]<zhi[j+1]) // @@ [Accesses zhi[j+1] out of bounds when j == count-1]
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
    for(i=0;i<count;i++) // @@ [Loop should be i<count-1 to avoid out-of-bounds access in the next line]
    {
        if(zhi[i]==zhi[i+1]&&xi[i]!=0&&xi[i+1]!=0) // @@ [Condition does not handle all like terms (e.g., when one coefficient is zero) and causes out-of-bounds access when i==count-1]
        {
            xi[i]=xi[i]+xi[i+1];
            for(j=i+1;j<count;j++) // @@ [After shifting, the count should be decremented; otherwise the last element remains as a duplicate]
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