#include <stdio.h> 
#include<string.h>
#include<stdlib.h>

typedef struct coordinate{
int x1;
int y1;
int x2;
int y2;
}coordinate;


int cmp(const coordinate *p1,const coordinate *p2);

int main()
{
int n,i,j,k;
coordinate a[105];
int flag,max=1;
int p,q;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
}
qsort(a,n,sizeof(coordinate),cmp); @@ [The comparison function 'cmp' does not match the expected signature for qsort, which expects a function taking two 'const void *' arguments, not 'const coordinate *'. This causes undefined behavior or compilation error depending on compiler settings.]
for(i=0;i<n;i++)
{
    flag=1;
    for(j=i+1,k=i;j<n;j++)
    {
        if((a[i].x2==a[j].x1)&&(a[i].y2==a[j].y1))
        {
            flag++;
            i=j; @@ [Modifying loop variable 'i' inside the inner loop disrupts the outer loop's iteration logic and causes incorrect traversal of segments.]
        }
    }
    i=k; @@ [This attempts to restore 'i', but due to the flawed logic of nested loops and manual index manipulation, it fails to correctly simulate chaining of connected segments.]
    if(flag>max)
    {
        max=flag;
        p=a[i].x1;
        q=a[i].y1;
    }
}
printf("%d %d %d\n",max,p,q);
return 0;
}
int cmp(const coordinate *p1,const coordinate *p2)
{
    return -((p1->x1)<(p2->x1)); @@ [Incorrect implementation of comparison function: it returns 0 or -1 instead of negative/zero/positive as required by qsort. Also, the signature is incompatible with qsort's expected comparator (should take const void *).]
}