#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int coe;//系数
    int pow;//幂
    struct Node *next;
};
int mul[500][2];
void bubble(int a[][2], int n)
{
    int i,j,hold1,hold0,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j][1]<a[j+1][1])
            {
                hold1=a[j][1],hold0=a[j][0];
                a[j][1]=a[j+1][1],a[j][0]=a[j+1][0];
                a[j+1][1]=hold1,a[j+1][0]=hold0;
                flag=1;
            }
            if(a[j][1]==a[j+1][1])
            {
                a[j][0]=a[j][0]+a[j+1][0];
                a[j+1][0]=0;
            }
        }
        if(0==flag)
        break;
    }
}
int main()
{
    int a,n,i,j=0;
    char c;
    struct Node *head,*p,*q,*r;
    head=p=NULL;
    do{
        scanf("%d%d%c",&a,&n,&c);
        q=(struct Node*)malloc(sizeof(struct Node));
        q->coe=a,q->pow=n,q->next=NULL;
        if(head==NULL)
            head=p=q;
        else{
            p->next=q;
            p=p->next;
        }
    }while(c!='\n');
    do{
        scanf("%d%d%c",&a,&n,&c);
        q=(struct Node*)malloc(sizeof(struct Node));
        q->coe=a,q->pow=n,q->next=NULL;
        for(p=head,i=j;p!=NULL;r=p,p=p->next,i++,j++)
        {
            mul[i][0]=p->coe*q->coe,mul[i][1]=p->pow+q->pow;
        }
        free(q);
    }while(c!='\n');
    bubble(mul,i);
    for(j=0;j<i;j++)
    {
        if(mul[j][0]!=0)
        printf("%d %d ",mul[j][0],mul[j][1]);
    }
    return 0;
}

