#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int xishu;
    int zhishu;
    struct duoxiangshi *link;
}duoxiangshi; // @@ [The struct tag 'duoxiangshi' is used in the definition but not declared before use. The forward reference inside the struct should match the typedef name, but since the typedef is not yet complete at this point, it causes a compilation error. It should use 'struct duoxiangshi' consistently or define the struct with a tag.]

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
        if(point->link==NULL)
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