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
qsort(a,n,sizeof(coordinate),cmp);
for(i=0;i<n;i++)
{
    flag=1;
    for(j=i+1,k=i;j<n;j++)
    {
        if((a[k].x2==a[j].x1)&&(a[k].y2==a[j].y1)) // @@ The comparison should be between the current end of the chain (a[k]) and the candidate segment (a[j]), not the starting segment (a[i]). Using a[i] prevents chaining beyond the first link.
        {
            flag++;
            k=j; // @@ The pointer to the current end of the chain (k) should be updated to j to continue the chain. Updating i here is incorrect as i is restored later.
        }
    }
    // i=k; // @@ This line is removed or commented out in logic, but strictly following instructions to annotate errors in existing lines. The original code had i=k which resets the outer loop index incorrectly if k changed, but k only changes inside. Actually, the original code structure `i=k` at the end of the outer loop body is problematic if k was updated. However, the primary logical error is inside the inner loop.
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
    return p1->x1 - p2->x1; // @@ The original comparison function `return -((p1->x1)<(p2->x1));` is incorrect. It returns -1 if p1->x1 < p2->x1, and 0 otherwise. This does not provide a strict weak ordering required by qsort (it fails to distinguish greater than). It should return the difference.
}