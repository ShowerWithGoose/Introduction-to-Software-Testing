#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int reverse(long long a[][2],int m);
int main()
{
long long coe1[100]={0},coe2[100]={0},pow1[100]={0},pow2[100]={0};
 long long num[1000][2]={0},tmp1,tmp2;
int i=0,j=0,k,l,m=0,s,t;
while(1)
{
	scanf("%lld%lld",&coe1[i],&pow1[i]);
	i++;
	if(getchar()=='\n')break;
}
while(1)
{
	scanf("%lld%lld",&coe2[j],&pow2[j]);
	j++;
	if(getchar()=='\n')break;
}
for(k=0;k<i;k++)
{
	for(l=0;l<j;l++)
	{
		num[m][0]=coe1[k]*coe2[l];
		num[m][1]=pow1[k]+pow2[l];
		m++;
	}
}
for(k=0;k<m;k++)
{
	for(l=k+1;l<m;l++)
	{
		if(num[k][1]==num[l][1])
		{
			num[k][0]=num[k][0]+num[l][0];
			num[l][0]=0;
		}
	}
}
for(k=0;k<m;k++)
{
	for(l=k+1;l<m;l++)
	{
		if(num[k][0]==0||num[l][0]==0)continue;
		else if(num[k][0]!=0&&num[l][0]!=0)
		{
			for(s=0;s<m;s++)
			{
			for(t=0;t<m-s;t++)
			{
				if(num[t][1]<num[t+1][1])
    {
     tmp1=num[t][1];     
    num[t][1]=num[t+1][1];
    num[t+1][1]=tmp1;
    tmp2=num[t][0];     
    num[t][0]=num[t+1][0];
    num[t+1][0]=tmp2;
   }
			}
			}
		}
	}
}
for(k=0;k<m;k++)
{
	for(l=0;l<2;l++)
	{
	if(num[k][0]!=0)printf("%lld ",num[k][l]);
	}
}

	return 0;
	} 
int reverse(long long a[][2],int m)
{
	 int i,j,t;
  for(i=0;i<m;i++) 
   for(j=0;j<m-i;j++) 
    if(a[j][1]<a[j+1][1])
    {
     t=a[j][1];     
    a[j][1]=a[j+1][1];
    a[j+1][1]=t;
   }
}

