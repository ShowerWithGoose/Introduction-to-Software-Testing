#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define M 1000

typedef struct position
{
    int x1;
    int x2;
    int y1;
    int y2;
    int l;
}seg,*segptr;

void erase(segptr a)
{
    a->x1=-1;
    a->x2=-1;
    a->y1=-1;
    a->y2=-1;
    a->l=-1;
    return;
}

int segcmp(const void * a,const void * b)
{
    segptr x=(segptr)a;
    segptr y=(segptr)b;
    if(x->x1!=y->x1) return x->x1-y->x1;
    else return x->y1-y->y1;
}

int main()
{
    int n;
    seg buf[M];
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&buf[i].x1,&buf[i].y1,&buf[i].x2,&buf[i].y2);


        buf[i].l=1;
    }
    qsort(buf,n,sizeof(seg),segcmp);

    int j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {

        if(i==j) continue;
        if((buf[i].x2==buf[j].x1)&&(buf[i].y2==buf[j].y1))
        {
            buf[i].x2=buf[j].x2;
            buf[i].y2=buf[j].y2;
            buf[i].l+=buf[j].l;
            erase(buf+j);


        }

    }
    int ml=buf[0].l;
    for(i=1;i<n;i++)
    {
        if(ml<buf[i].l)
        {
            ml=buf[i].l;j=i;

        }
    }
    if(ml==buf[0].l) j=0;
    printf("%d %d %d\n",ml,buf[j].x1,buf[j].y1);
    return 0;
}



