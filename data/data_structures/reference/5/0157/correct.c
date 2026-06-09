#include<stdio.h>
long long a[10000][2],b[10000][2],c[10000][2];
int main(){
	int i=1,j=1;
	long long num ,index;
	int n,m,k=0;
	char ch;
	scanf("%lld%lld",&a[0][0],&a[0][1]);
	ch=getchar();
	while(ch!= '\n')
	{
		scanf("%lld %lld",&a[i][0],&a[i][1]);
		i++;
		ch=getchar();
	}
	ch='a';
	scanf("%lld %lld",&b[0][0],&b[0][1]);
	ch = getchar();
	while(ch!= '\n')
	{
		scanf("%lld %lld",&b[j][0],&b[j][1]);
		j++;
		ch = getchar();
	}
	
	for(n=0;n<i;n++)
	{
		for(m=0;m<j;m++)
		
		{
			c[k][0]=a[n][0]*b[m][0];
			c[k][1]=a[n][1]+b[m][1];
			k++;
		}
	}
	int A=k;
	long long temp,tmp;
	for(n=0;n<A;n++)
	{
		for(m=n+1;m<A;m++)
		{
			if(c[n][1]<c[m][1])
			{
				temp = c[n][0];
				tmp  = c[n][1];
				c[n][0] = c[m][0];
				c[n][1] = c[m][1];
				c[m][0] = temp;
				c[m][1] =tmp;
			}
		}
	}
	for(n=0;n<A;n++)
	{
		for(m=n+1;m<A;m++){
			if(c[n][1] == c[m][1])
			{
				c[n][0]= c[n][0]+c[m][0];
				c[m][1] = -1;
			}
		}
	}
	
	for(n=0;n<A;n++)
	{
		if (c[n][1] !=-1) printf("%lld %lld ",c[n][0],c[n][1]);
	}
	return 0;
}









