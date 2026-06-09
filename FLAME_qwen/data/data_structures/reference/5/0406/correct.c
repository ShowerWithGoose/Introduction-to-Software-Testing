#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int coe;//系数
    int pow;//指数
    struct node *next;
};

void bubblesort(struct node a[], int n);

int main()
{
    int a,n,cnt=0,i,j=0;
    char c;
    struct node *head1,*head2,*p1,*p2,*q,*p0,*pt;
    head1=p1=NULL;
    head2=p2=NULL;

    do{
        scanf("%d%d%c",&a,&n,&c);
        q=(struct node*)malloc(sizeof(struct node));
        q->coe=a;
        q->pow=n;
        q->next=NULL;
        if(head1==NULL)
        {
            head1=p1=q;
        }else{
            p1->next=q;
            p1=p1->next;//p始终指向末尾节点
        }
    }while(c!='\n');

    do{
        scanf("%d%d%c",&a,&n,&c);

        //q=(struct node*)malloc(sizeof(struct node));
        for(p1=head1;p1!=NULL;p1=p1->next)
        {
            q=(struct node*)malloc(sizeof(struct node));
            q->coe=a*(p1->coe);
            q->pow=n+(p1->pow);
            q->next=NULL;
            if(head2==NULL)
            {
                head2=p2=q;
            }else{
                p2->next=q;
                p2=p2->next;
            }
        }

    }while(c!='\n');

    for(p2=head2;p2!=NULL;p2=p2->next)
    {
        cnt++;
    }
    p0=(struct node*)malloc(cnt*sizeof(struct node));
    pt=(struct node*)malloc(cnt*sizeof(struct node));
    for(i=0,p2=head2;i<cnt;i++,p2=p2->next)
    {
        p0[i].coe=p2->coe;
        p0[i].pow=p2->pow;
    }
    bubblesort(p0,cnt);

    /*for(i=0;i<cnt;i++)
    {
        printf("%d %d ",p0[i].coe,p0[i].pow);
    }
    printf("\n");
    */
    if(cnt==1){
        printf("%d %d ",p0[0].coe,p0[0].pow);
    }
    else{

    pt[0].coe=0;
    for(i=0;i<cnt-1;i++)
    {
        pt[j].pow=p0[i].pow;
        pt[j].coe+=p0[i].coe;
        if(p0[i].pow!=p0[i+1].pow)
        {
            j++;
            if(i!=cnt-2)
            {
                pt[j].coe=0;
            }else {
                pt[j].pow=p0[i+1].pow;
                pt[j].coe=p0[i+1].coe;
            }

        }
    }

    for(i=0;i<=j;i++)
    {
        printf("%d %d ",pt[i].coe,pt[i].pow);
    }
    }

    return 0;
}


void bubblesort(struct node a[], int n)
{
  int i, j;
  struct node hold;
  for( i=0; i < n-1; i++)
     for(j=0; j < n-1-i; j++)
          if(a[j].pow < a[j+1].pow)
             {
                 hold = a[j];
                 a[j] = a[j+1];
                 a[j+1] = hold;
              }
}



