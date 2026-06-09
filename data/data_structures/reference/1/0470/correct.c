#include<stdio.h>
int a[10],b[10],c[10];
int m;
void array(int n,int d[])
{
int i;
if(n==0)
{for(i=0;i<m;i++)
printf("%d ",c[i]);
printf("\n");
}
else
{
for(i=0;i<m;i++)
{if(b[i]!=0)
{c[m-n]=a[i];
b[i]=0;
array(n-1,&b[0]);
b[i]=1;
}
}
return;
}

}
int main()
{
scanf("%d",&m);
int i;
for(i=0;i<m;i++)
b[i]=1;
for(i=0;i<m;i++)
a[i]=i+1;
for(i=0;i<m;i++)
{
b[i]=0;
c[0]=a[i];
array(m-1,&b[0]);
b[i]=1;
}
return 0;
}



