#include<stdio.h>
#include<math.h>

int main()
{
	char shi0[100],shi1[100],fu[100],fu1[100];
	int i,j=0,j0,k=0,l=1,m=0,n=1,n0,l0,shu0[100]={0},shu1[100]={0},res;
	gets(shi0);
	for(i=0;shi0[i]!='\0';i++)
	{
		if(shi0[i]==43||shi0[i]==45||shi0[i]==42||shi0[i]==47||shi0[i]=='=')
		{
			fu[l]=shi0[i];
			l0=l;l+=2;
			for(j0;j0>=0;j0--)
		{
			shu0[k]+=(shi1[j0]-'0')*pow(10,j-1-j0);
		}
		k+=2;j=0;
		}
		else
		{
			if(shi0[i]!=32)
			{
				shi1[j]=shi0[i];
				j0=j;
				j++;
			}
		}
	}
	for(l=1;l<=l0;l+=2)
	{
		if(fu[l]=='*')
		{
			shu0[l+1]=shu0[l-1]*shu0[l+1];
		}
		else if(fu[l]=='/')
		{
			shu0[l+1]=shu0[l-1]/shu0[l+1];
		}
		else if(fu[l]=='+')
		{
			shu1[m]=shu0[l-1];
			fu1[n]='+';
			n0=n;m+=2;n+=2;
		}
		else if(fu[l]=='-')
		{
			shu1[m]=shu0[l-1];
			fu1[n]='-';
			n0=n;m+=2;n+=2;
		}
		else if (fu[l]=='=')
		{
			shu1[m]=shu0[l-1];
			fu1[n]='=';
			n0=n;m+=2;n+=2;
		}
	}
	for(n=1;n<=n0;n+=2)
	{
		if(fu1[n]=='+')
		{
			res=shu1[n-1]+shu1[n+1];
			shu1[n+1]=res;
		}
		else if(fu1[n]=='-')
		{
			res=shu1[n-1]-shu1[n+1];
			shu1[n+1]=res;	
		}
		else if(fu1[n]=='=')
		{
			res=shu1[n-1];
		}
	}
	printf("%d\n",res);
 }



