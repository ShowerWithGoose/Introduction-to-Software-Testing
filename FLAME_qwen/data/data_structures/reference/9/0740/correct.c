#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line
{
    int m;
    int right;
    int left;
};
struct line LINE[10000];

int cmp(const void *p,const void *q)
{
    struct line *w=(struct line*)p;
    struct line *e=(struct line*)q;
    if((w->m)<(e->m)) return -1;
    else return 1;
}

int main()
{
    int n,a[10000][4],i,j,l,temp,p=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    for(i=0; i<n; i++)
    {
        l=i;
        temp=1;
        for(j=0; j<n; j++)
            if(a[l][2]==a[j][0]&&a[l][3]==a[j][1])
            {
                l=j;
                j=-1;
                temp++;
            }
        LINE[p].m=temp;
        LINE[p].right=a[i][1];
        LINE[p].left=a[i][0];
        p++;
    }
    qsort(LINE,n,sizeof(LINE[n-1]),cmp);
    printf("%d %d %d",LINE[n-1].m,LINE[n-1].left,LINE[n-1].right);
}

