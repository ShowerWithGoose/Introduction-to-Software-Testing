

/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[10000],b[10000],c[10000],d[10000];

struct number
{
    int xi;
    int zhi;
}num[10000];

int cmp(const void*a,const void*b)
{
    struct number * c = (struct number *)a;
    struct number * d = (struct number *)b;
    return d->zhi - c->zhi;
}

char ch=' ';
int main()
{
    struct number num[10000];
    int i,j,k=0;
    int cnt1=0,cnt2=0;
    while (ch!='\n')
    {
        scanf("%d %d%c",&a[cnt1],&b[cnt1],&ch);
        cnt1++;
    }
    ch=' ';
    while (ch!='\n')
    {
        scanf("%d %d%c",&c[cnt2],&d[cnt2],&ch);
        cnt2++;
    }
    for ( i = 0; i < cnt1; i++)
    {
        for ( j = 0; j< cnt2; j++)
        {
            num[k].xi=a[i]*c[j];
            num[k].zhi=b[i]+d[j];
            k++;
        }
        
    }
    qsort(num,k,sizeof(num[0]),cmp);

   for( i = 0; i < k; i++)
    {
        if(num[i].zhi == num[i+1].zhi && num[i].zhi != 0)        //合并指数相同的项数
        {
            num[i+1].xi += num[i].xi;
            num[i].xi = 0;
        }
    }
    for(int i = 0; i < k; i++)
        if(num[i].xi != 0)
        printf("%d %d ",num[i].xi,num[i].zhi);
    

    return 0;
    
    
}*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct NUM
{
    int zhi;
    int xi;
}node;
node num[100];
node first[100];
node second[100];

int cmp(const void*a,const void *b)
{
    node*c=(node*)a;
    node*d=(node*)b;
    return d->zhi-c->zhi;
}

int main()
{

    int i=0,j=0;
    int cnt1=0,cnt2=0;
    char ch=' ';
    while (ch!='\n')
    {
        scanf("%d %d%c",&first[cnt1].xi,&first[cnt1].zhi,&ch);
        cnt1++;
    }
    ch=' ';
    while (ch!='\n')
    {
        scanf("%d %d%c",&second[cnt2].xi,&second[cnt2].zhi,&ch);
        cnt2++;
    }
    int cnt=0;
    for ( i = 0; i < cnt1; i++)
    {
        for ( j = 0; j < cnt2; j++)
        {
            num[cnt].xi=first[i].xi*second[j].xi;
            num[cnt].zhi=first[i].zhi+second[j].zhi;
            cnt++;
        }
        
    }
    qsort(num,cnt,sizeof(num[0]),cmp);

    /*for ( i = 0; i < cnt; i++)
    {
        printf("%d %d ",num[i].xi,num[i].zhi);
        printf("\n");
    }*/
    

    for ( i = 0; i < cnt; i++)
    {
        if (i==cnt-1)
        {
            printf("%d %d ",num[i].xi,num[i].zhi);
            break;
        }
        

        if (num[i].zhi==num[i+1].zhi)
        {
            num[i+1].xi=num[i].xi+num[i+1].xi;
            continue;
        }
        printf("%d %d ",num[i].xi,num[i].zhi);
    }

    /*for ( i = 0; i < cnt; i++)
    {
        printf("%d %d ",num[i].xi,num[i].zhi);
    }*/
    
    
    return 0;



}
