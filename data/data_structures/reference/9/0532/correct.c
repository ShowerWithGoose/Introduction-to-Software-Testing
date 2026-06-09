#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cp(const void *p1,const void *p2)
{
    const int *p3=p1,*p4=p2;
    if(p3[1]>p4[1])
        return 1;
else return -1;
}
int main(){
int n;
int a[105][5];
memset(a,0,sizeof(a));
scanf("%d",&n);
for(int i=1;i<=n;i++)
scanf("%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
qsort(a,n+1,sizeof(a[1]),cp);
int i,j,k;
for(j=1;j<=n-1;j++)
for(k=j+1;k<=n;k++)
{
    if(a[j][3]==a[k][1]&&a[j][4]==a[k][2])
    {
        a[j][0]++;
    }
}
for(k=n;k>=1;k--)
for(j=k;j>=1;j--)
{
    if(a[j][3]==a[k][1]&&a[j][4]==a[k][2])
    {
        a[j][0]=a[j][0]+a[k][0];
    }
}
int max=0,maxn=1;
for(i=1;i<=n;i++)
if(max<=a[i][0])
{
    max=a[i][0];
    maxn=i;
}
printf("%d %d %d",max+1,a[maxn][1],a[maxn][2]);
return 0;
}




