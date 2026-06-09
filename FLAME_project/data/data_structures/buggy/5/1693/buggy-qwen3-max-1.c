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
        for(j=i;j<count;j++)
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
    } @@ [The bubble sort loop bounds are incorrect: inner loop should go to `count-1` to avoid accessing zhi[j+1] out of bounds when j == count-1. Also, this sorting is unstable and inefficient, but the main issue is the off-by-one error causing undefined behavior or incorrect sorting.]
    for(i=0;i<count;i++)
    {
        if(zhi[i]==zhi[i+1]&&xi[i]!=0&&xi[i+1]!=0)
        {
            xi[i]=xi[i]+xi[i+1];
            for(j=i+1;j<count;j++)
            {
                xi[j]=xi[j+1];
                zhi[j]=zhi[j+1];
            }
            i--;
        }
    } @@ [This merging loop has multiple issues: (1) It accesses zhi[i+1] and xi[i+1] when i can be count-1, leading to out-of-bounds access. (2) It only merges adjacent duplicates once per pass, but after shifting elements left, new adjacent duplicates may form that aren't merged because the loop doesn't recheck properly. (3) The condition `xi[i]!=0 && xi[i+1]!=0` is unnecessary and wrong—zero coefficients should be handled by skipping output, not by preventing merging. This causes incorrect combination of like terms, leading to duplicate exponents in output.]
    for(i=0;i<count;i++)
    {
        if(xi[i]!=0)
        {
        printf("%d %d ",xi[i],zhi[i]);
        }
    }
    return 0;
}