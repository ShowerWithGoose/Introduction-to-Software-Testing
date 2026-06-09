#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int i,j,k,p,q;
	int N,temp1,temp2;
int main(){
	long long int a[105][105],b[105][105],l[105][105];
	char c;
	k=0;i=0;j=0;p=0;q=0;
	do
	{
		scanf("%lld%lld%c",&a[i][0],&a[i][1],&c);
		i=i+1;
	}while(c!='\n');
	while(scanf("%lld%lld",&b[j][0],&b[j][1])!=EOF)
	{

		j=j+1;
	}

	q=0;
	for(k=0;k<i;k++)
	{
		for(p=0;p<j;p++)
		{
	
			l[q][0]=a[k][0]*b[p][0];
			l[q][1]=a[k][1]+b[p][1];				
			q=q+1;

		}
	}
	N=i*j;
	q=0;
	for(q=0;q<N;q++)
	{
		for(p=q;p<N;p++)
		{
			if(q!=p&&l[q][1]==l[p][1])
			{
				l[q][0]=l[q][0]+l[p][0];
				for(k=p+1;k<N;k++)
				{
				l[k-1][0]=l[k][0];
				l[k-1][1]=l[k][1];		
				}
				N=N-1;	
			}
			else if(l[q][1]<l[p][1])
			{
				temp1=l[q][1];
				l[q][1]=l[p][1];
				l[p][1]=temp1;
				temp2=l[q][0];
				l[q][0]=l[p][0];
				l[p][0]=temp2;				
			}
		}
	}
	for(q=0;q<N;q++)
	{
		printf("%lld ",l[q][0]);
		printf("%lld ",l[q][1]);		
	}

return 0;
}

