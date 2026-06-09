#include <stdio.h>
int a[105][105]={0};
void search1(int p,int n)
{
for(int i=0;i<n;i++)
if(a[p][i]==1)
{printf("%d ",i);
for(int j=0;j<n;j++)
if(a[j][i]==1)
a[j][i]=2;
search1(i,n);
}
return;
}
void search2(int n)
{
int tab[105];
int top=-1,rear=-1;
for(int i=0;i<n;i++)
    if(a[0][i]==1)
{
    for(int j=0;j<n;j++)
    if(a[j][i]==1)
     a[j][i]=2;
    printf("%d ",i);
    tab[++rear]=i;
}
while(top<rear)
{
++top;
for(int i=0;i<n;i++)
if(a[tab[top]][i]==1)
{
for(int j=0;j<n;j++)
     if(a[j][i]==1)
     a[j][i]=2;
    printf("%d ",i);
    tab[++rear]=i;
}
}
return;
}
void clear(int n)
{
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
if(a[i][j]==2)
a[i][j]=1;
}
int main(){
int n,N;
int n1,n2;
int del;
scanf("%d%d",&n,&N);
for(int i=0;i<N;i++)
{scanf("%d%d",&n1,&n2);
if(n2!=0)
a[n1][n2]=1;
if(n1!=0)
a[n2][n1]=1;
}
scanf("%d",&del);
printf("%d ",0);
search1(0,n);
printf("\n");
clear(n);
printf("%d ",0);
search2(n);
printf("\n");
clear(n);
for(int i=0;i<n;i++)
a[del][i]=0;
for(int i=0;i<n;i++)
a[i][del]=0;
printf("%d ",0);
search1(0,n);
printf("\n");
clear(n);
printf("%d ",0);
search2(n);
printf("\n");
clear(n);
return 0;
}

