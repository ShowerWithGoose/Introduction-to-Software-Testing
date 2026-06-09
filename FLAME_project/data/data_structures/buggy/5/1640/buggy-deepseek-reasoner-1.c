#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int xishu;
    int zhishu;
    struct duoxiangshi *link;
}duoxiangshi;

duoxiangshi *creat(int xishu,int zhishu);
void insert(duoxiangshi *head,int xishu,int zhishu);

int main()
{
    int a[2][100]={0},b[2][100]={0};
    int i=0,j=0,ii,jj;
    duoxiangshi *head,*point;
    while(1)
    {
        scanf("%d%d",&a[0][i],&a[1][i]);
        if(getchar()=='\n') break;
        i++;
    }
    while(1)
    {
        scanf("%d%d",&b[0][j],&b[1][j]);
        if(getchar()=='\n') break;
        j++;
    }
    for(ii=0;ii<=i;ii++)
    {
        for(jj=0;jj<=j;jj++)
        {
            if(ii==0&&jj==0)
            {
                head=creat(a[0][ii]*b[0][jj],a[1][ii]+b[1][jj]); 
                continue;
            }
            insert(head,a[0][ii]*b[0][jj],a[1][ii]+b[1][jj]);
        }
    }
    point=head;
    while(1)
    {
        printf("%d %d ",point->xishu,point->zhishu);
        point=point->link;
        if(point->link==NULL) // @@ Dereferencing NULL pointer: after the first iteration, point becomes NULL (since there is only one node), causing a segmentation fault.
        {
            printf("%d %d ",point->xishu,point->zhishu);
            break;
        }
    }
    return 0;
}
duoxiangshi *creat(int xishu,int zhishu)
{
    duoxiangshi *newxiang=(duoxiangshi*)malloc(sizeof(duoxiangshi));
    newxiang->xishu=xishu;
    newxiang->zhishu=zhishu;
    newxiang->link=NULL;
    return newxiang;
}
void insert(duoxiangshi *head,int xishu,int zhishu)
{
    duoxiangshi *temp=creat(xishu,zhishu),*point=head;
    duoxiangshi *weip;
    while(point!=NULL)
    {
        if(point->zhishu==zhishu)
        {
            point->xishu+=xishu;
            return;
        } 
        if(point->zhishu<zhishu) break;
        if(point->zhishu>zhishu)
        {
            weip=point;
            point=point->link;
        }
    }
    if(point==NULL)
    {
        weip->link=temp;
    }
    else
    {
        weip->link=temp;
        temp->link=point;
    }
}