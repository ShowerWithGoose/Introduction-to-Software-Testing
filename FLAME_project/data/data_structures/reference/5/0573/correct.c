#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

int X[80],Y[80];

struct list
{
    int xi;
    int zhi;
    struct list *next;
};

int main()
{
    int num1=0,num2=0;
    struct list *first=NULL,*a1,*b1,*c1;
    struct list *second=NULL,*a2,*b2,*c2;
    while(1)
    {
        int a0,b0;
        scanf("%d %d",&a0,&b0);
        char c0=getchar();
        b1 = (struct list *)malloc(sizeof(struct list));
        b1->xi=a0;
        b1->zhi=b0;
        b1->next=NULL;
        if(first == NULL)
            first=a1=b1;
        else{
            a1->next=b1;
            a1=b1;
        }
        num1++;
        if(c0=='\n') {break;}
    }
    b1->next=first;
    while(1)
    {
        int a0,b0;
        scanf("%d %d",&a0,&b0);
        char c0=getchar();
        b2 = (struct list *)malloc(sizeof(struct list));
        b2->xi=a0;
        b2->zhi=b0;
        b2->next=NULL;
        if(second == NULL)
            second=a2=b2;
        else{
            a2->next=b2;
            a2=b2;
        }
        num2++;
        if(c0=='\n') {break;}
    }
    b2->next=second;
    int N=num1*num2;
    int k=1;
    b1=b1->next;
    b2=b2->next;
    for(int i1=1;i1<=num1;i1++)
    {
        for(int i2=1;i2<=num2;i2++)
        {
            int m1,m2,n1,n2,p1,p2,z=0;
            m1=b1->xi;
            m2=b1->zhi;
            n1=b2->xi;
            n2=b2->zhi;
            p1=m1*n1;p2=m2+n2;
            for(int j=1;j<k;j++)
            {
                if(Y[j]==p2) {z=j;break;}
            }
            if(z!=0)
            {
                X[z]+=p1;N--;
            }
            else
            {
                X[k]=p1;Y[k]=p2;k++;
            }
            b2=b2->next;
        }
        b2=b2->next;
        b1=b1->next;
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int m2,n,n2;
            m2=Y[i];n2=Y[j];
            if(m2>n2)
            {
                Y[i]=n2;Y[j]=m2;
                n=X[i];
                X[i]=X[j];
                X[j]=n;
            }
        }
    }
    for(int i=1;i<N;i++)
    {
        printf("%d %d ",X[i],Y[i]);
    }
    printf("%d %d",X[N],Y[N]);
    return 0;
}

