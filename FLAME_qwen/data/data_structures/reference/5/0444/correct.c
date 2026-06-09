#include<stdio.h>
struct point
{
    int a;
    int b;
}c[100000],d[100000],he[100000];
int main(){
    int k=0,m=0,n=0;
    int r,v;
    char l;
    char j;
    while(l!='\n')
    {
        scanf("%d%d",&c[k].a,&c[k].b);
        k++;
        scanf("%c",&l);
        if(l=='\n')
            break;
    }
    while(j!='\n')
    {
        scanf("%d%d",&d[m].a,&d[m].b);
        m++;
        scanf("%c",&j);
        if(j=='\n')
            break;
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<m;j++)
        {
            he[n].a=c[i].a*d[j].a;
            he[n].b=c[i].b+d[j].b;
            n++;
        }
    }
    for(int i=0;i<k*m-1;i++)
    {
        for(int j=0;j<k*m-1-i;j++)
        {
            if(he[j].b>he[j+1].b)
            {
                 v=he[j].b;
                he[j].b=he[j+1].b;
                he[j+1].b=v;
                 r=he[j].a;
                he[j].a=he[j+1].a;
                he[j+1].a=r;
            }
        }
    }
    for(int i=0;i<k*m;i++)
    {
        for(int j=i+1;j<k*m;j++)
        {
            if(he[i].b==he[j].b&&he[i].a!=0)
            {
                he[i].a=he[i].a+he[j].a;
                he[j].a=0;
                he[j].b=0;
            }
        }
    }
    for(int i=k*m-1;i>=0;i--)
    {
        if(he[i].a!=0)
        {
            printf("%d %d ",he[i].a,he[i].b);
        }
    }
    return 0;
}

