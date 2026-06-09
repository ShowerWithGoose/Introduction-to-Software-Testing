#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int i,j,k,sum,mid;
	char a[1000],b[1000],f[1000];
	int num[1000];
	gets(a);
	for(i=0,k=0;a[i]!='=';i++)
	{
		if(a[i]==' ')
		{
			j=i;
			for(;a[j]==' ';j++);
			i=j;
		}
		b[k++]=a[i];		
	}
	b[k]='=';k=0;j=0;
	for(i=0;i<=1000;i++)
	num[i]=0;
	for(i=0;b[i]!='=';i++)
	{
		if(b[i]<='9'&&b[i]>='0')
		{
			num[k]*=10;
			num[k]+=b[i]-'0';			
		}
		else
		{
			k++;
			f[j]=b[i];j++; 
		}
	}
	for(k=0;f[k]!='\0';k++)
	{
		if(f[k]=='*'||f[k]=='/')
		{
		    if(f[k]=='*')
			num[k+1]*=num[k];	
			else
			num[k+1]=num[k]/num[k+1];
			num[k]=0;
		    f[k]='p';
	    }
	}
	k=0;sum=num[0];
	while(f[k]=='p')
	{
		k++;
		sum=num[k];
	}
	for(k=0;f[k]!='\0';k++)
	{
		if(f[k]=='+')
		{
			while(f[k+1]=='p')
			k++;
			sum+=num[k+1];
		}
		else if(f[k]=='-')
		{
			while(f[k+1]=='p')
			k++;
			sum-=num[k+1];
		}
	}
	printf("%d",sum);
	return 0;	 
}

