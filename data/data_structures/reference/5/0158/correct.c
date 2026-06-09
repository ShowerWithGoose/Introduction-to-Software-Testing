#include<stdio.h>
long long a[200][2],b[200][2],c[10005][2];
int main()
{
int i=0,j,k=0;char t;long long temp;
for(i=0;i<100;i++)
{
scanf("%lld%lld",&a[i][0],&a[i][1]);
scanf("%c",&t);
if(t=='\n') break;
}
for(i=0;i<100;i++)
{
scanf("%lld%lld",&b[i][0],&b[i][1]);
scanf("%c",&t);
if(t=='\n') break;
}
for(i=0;i<100;i++)
{for(j=0;j<100;j++)
 {c[k][0]=a[i][0]*b[j][0];
  c[k][1]=a[i][1]+b[j][1];
  k++;
 }
 }
for(i=0;i<10000;i++)
{for(j=i+1;j<10000;j++)
 if(c[j][1]==c[i][1]) 
 {
 c[i][0]+=c[j][0];
 c[j][0]=0;
 }
}
for(i=0;i<10000;i++)
{for(j=i+1;j<10000;j++)
 if(c[j][1]>c[i][1]) 
 {temp=c[i][1];
 c[i][1]=c[j][1];
 c[j][1]=temp;
 temp=c[i][0];
 c[i][0]=c[j][0];
 c[j][0]=temp;
 }
}
for(i=0;i<10000;i++)
{if(c[i][0]!=0) printf("%lld %lld ",c[i][0],c[i][1]);
}
	return 0;
}

