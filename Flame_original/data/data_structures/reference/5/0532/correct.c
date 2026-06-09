#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cp(const void *p1,const void *p2)
{
    const int *p3=p1,*p4=p2;
    if(p3[2]<p4[2])
        return 1;
    else
        return -1;
}
int main(){
int a[10000][3],b[10000][3],c[10000][3];
memset(c,0,sizeof(c));
int n=1,m=1;
while(1)
{scanf("%d%d",&a[n][1],&a[n][2]);
if(getchar()=='\n')
break;
n++;
}
while(1)
{scanf("%d%d",&b[m][1],&b[m][2]);
if(getchar()=='\n')
break;
m++;
}
int s=1;
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
{c[s][1]=a[i][1]*b[j][1];
c[s][2]=a[i][2]+b[j][2];
s++;
}
s--;
qsort(c[1],s,sizeof(c[0]),cp);
for(int k=1;k<=s-1;k++)
    if(c[k][2]==c[k+1][2])
{
    c[k+1][1]+=c[k][1];
    c[k][2]=-1;
}
for(int k=1;k<=s;k++)
    if(c[k][2]!=-1)
    printf("%d %d ",c[k][1],c[k][2]);
return 0;
}


