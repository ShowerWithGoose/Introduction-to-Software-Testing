#include<stdio.h>
#include<stdlib.h>
struct mon{
int ratio;
int index;
//struct mon *next;
}a[1000],b[1000],ans[100000];
/*int main()
{
    struct mon *p,*head1=NULL,*head2=NULL,*r;
    int i,j;
    char c='a';
    while(c!='\n')
    {
        p=(struct mon*)malloc(sizeof(struct mon));
        scanf("%d%d",&p->ratio,&p->index);
        p->next=NULL;
        if(head1==NULL) head1=p;
        else r->next=p;
        r=p;
        c=getchar();
    }
    c='a';
    while(c!='\n')
    {
        p=(struct mon*)malloc(sizeof(struct mon));
        scanf("%d%d",&p->ratio,&p->index);
        p->next=NULL;
        if(head2==NULL) head2=p;
        else r->next=p;
        r=p;
        c=getchar();
    }

}*/
int high(struct mon *p1,struct mon *p2)
{
    if(p1->index>=p2->index) return -1;
    else return 1;
}
int main()
{
    int i,j,la,lb,l,k=0;
    char c='a';
    for(i=0;c!='\n';i++)
    {
        scanf("%d%d",&a[i].ratio,&a[i].index);
        c=getchar();
    }

    la=i;
    c='a';
    for(i=0;c!='\n';i++)
    {
        scanf("%d%d",&b[i].ratio,&b[i].index);
        c=getchar();
    }

    lb=i;
    l=la*lb;

    for(i=0;i<la;i++)
    {
        for(j=0;j<lb;j++)
        {

            ans[k].ratio=a[i].ratio*b[j].ratio;
            ans[k].index=a[i].index+b[j].index;

            k++;
        }
    }

    qsort(ans,l,sizeof(struct mon),high);

    for(i=1;i<l;i++)
        if(ans[i].index==ans[i-1].index) ans[i].ratio+=ans[i-1].ratio;

    for(i=0;i<l;i++)
    {
        if(i<l-1)
        {while(ans[i].index==ans[i+1].index) i++;}
        printf("%d %d ",ans[i].ratio,ans[i].index);

    }
    printf("\n");
    return 0;
}




















