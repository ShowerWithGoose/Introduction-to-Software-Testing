#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int xishu;
    int zhishu;
    struct duoxiangshi *link;
}duoxiangshi; // @@ [The struct tag 'duoxiangshi' is used in the definition but not declared properly. The type 'struct duoxiangshi' is incomplete because the typedef name 'duoxiangshi' is not yet available inside the struct definition.]

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
    for(ii=0;ii<=i;ii++) // @@ [Loop runs from 0 to i inclusive, but i was incremented after the last valid input, so a[0][i] and a[1][i] are uninitialized (zero). Should be ii < i.]
    {
        for(jj=0;jj<=j;jj++) // @@ [Same issue: jj <= j accesses uninitialized b[0][j], b[1][j]. Should be jj < j.]
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
        if(point->link==NULL) // @@ [If the list has only one node, point->link is NULL immediately, so this condition triggers and tries to print again, causing undefined behavior (dereferencing NULL in next iteration or double-printing). Also, if list is empty (though unlikely here), this crashes.]
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
    duoxiangshi *weip; // @@ [Variable 'weip' may be used uninitialized. If the while loop doesn't execute (e.g., head is NULL or first node has zhishu < input zhishu), 'weip' remains uninitialized, leading to undefined behavior when assigned to.]
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
        weip->link=temp; // @@ [If the list was empty (head == NULL), this code path is never reached because the while loop wouldn't run and 'weip' is uninitialized. But more critically, the function doesn't handle insertion at the head (when new term has highest exponent).]
    }
    else
    {
        weip->link=temp;
        temp->link=point;
    }
}