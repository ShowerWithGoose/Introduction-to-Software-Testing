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
    for(ii=0;ii<=i;ii++) @@ // Loop condition should be ii < i, not ii <= i, because i is the count of terms (0-indexed), so valid indices are 0 to i-1. Same issue for jj <= j.
    {
        for(jj=0;jj<=j;jj++) @@ // Same as above: jj should go from 0 to j-1, not j. This causes reading uninitialized array elements (a[0][i], b[0][j] etc.), leading to undefined behavior.
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
        if(point->link==NULL) @@ // If the list has only one node, point->link is NULL immediately, so this condition triggers and tries to print point again, but point is already the last node. Also, if the list is empty or head is NULL, this dereferences NULL. Additionally, after printing the last node inside the loop, it breaks, but the loop structure is flawed and may cause infinite loop or crash.
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
} @@ // The variable 'weip' is used without being initialized when the first node in the list has zhishu < input zhishu (i.e., insertion at head). In that case, the while loop breaks immediately, 'weip' is uninitialized, leading to undefined behavior when assigning weip->link.