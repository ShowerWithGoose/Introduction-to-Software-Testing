#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int cmp(const void*a,const void*b);
struct duo{
    int xiang;
    int zhi;
};

int cmp(const void*p,const void*q)
{
    struct duo *a=(struct duo*)p;
    struct duo *b=(struct duo*)q;
    return b->zhi-a->zhi;
}
int main()
{
    char c;
    int shua=0,shub=0,shuc=0;
    struct duo x[10005];
    struct duo y[10005];
    struct duo z[10005];
    scanf("%d%d%c",&x[shua].xiang,&x[shua].zhi,&c);
    shua++;
    while(c!='\n')
    {
        scanf("%d%d%c",&x[shua].xiang,&x[shua].zhi,&c);
        shua++;
    }
    
    scanf("%d%d%c",&y[shub].xiang,&y[shub].zhi,&c);
    shub++;
    while(c!='\n')
    {
        scanf("%d%d%c",&y[shua].xiang,&y[shua].zhi,&c); // @@ Typo: uses shua instead of shub, causing incorrect indexing for array y
        shub++;
    }
    qsort(x,shua,sizeof(struct duo),cmp);
    qsort(y,shub,sizeof(struct duo),cmp);
    for(int i=0;i<shua;i++)
    {
        for(int j=0;j<shub;j++)
        {
            z[shuc].xiang=x[i].xiang*y[j].xiang;
            z[shuc].zhi=x[i].zhi+y[j].zhi;
            shuc++;
        }
    }
    qsort(z,shuc,sizeof(struct duo),cmp);
    for(int i=0;i<shuc;i++) // @@ Loop bound error: accessing z[i+1] causes out-of-bounds when i == shuc-1, should be i < shuc - 1
    {
        if(z[i].zhi==z[i+1].zhi && z[i].zhi!=0) // @@ Logical error: condition z[i].zhi!=0 prevents merging constant terms (exponent 0), should be removed
        {
            z[i+1].xiang=z[i].xiang+z[i+1].xiang;
            z[i].xiang =0;
        }
    }
    
    for(int i=0;i<shuc;i++)
    {
        if(z[i].xiang!=0)
        {
            printf("%d %d ",z[i].xiang,z[i].zhi);
        }
    }
    return 0;
}