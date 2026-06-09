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
    } @@ [Array index out of bounds: when j == count-1, zhi[j+1] accesses zhi[count], which is beyond the array size (300). This leads to undefined behavior.]
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
    } @@ [Array index out of bounds: when i == count-1, zhi[i+1] accesses zhi[count], which is invalid. Also, after shifting elements, 'count' is not decremented, leading to incorrect loop bounds and potential duplicate or skipped terms.]
    for(i=0;i<count;i++)
    {
        if(xi[i]!=0)
        {
        printf("%d %d ",xi[i],zhi[i]);
        }
    }
    return 0;
}