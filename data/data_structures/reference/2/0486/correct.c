#include<stdio.h>
char a[1000],b[1000],c[1000];
int main()
{
	int i,k=1,n=1,m=1,l,x;
	int fu[1000],num[1000],ret,end[1000];
	int flag=0;
	int e=0;
	
	for(i=0;i<1000;i++)
	{
		num[i]=0;
		fu[i]=0;
	}
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!=' ')
		{
			b[k]=a[i];
			k++;
		}
	}
	k--;
	
	for(i=1;i<=k;i++)
	{
		if(b[i]>='0'&&b[i]<='9'){
			num[m]=b[i]-'0';
			i++;
			flag=0;
		}
		
		while(b[i]>='0'&&b[i]<='9')
		{
			num[m]=num[m]*10+b[i]-'0';
			i++;
			flag=0;
		}
		
		x=i;
		
		if(b[x]=='+')
		{
			fu[n++]=1;
			
		}
		else if(b[x]=='-')
		{
			fu[n++]=2;
		}
		else if(b[x]=='*')
		{
			fu[n++]=3;
		}
		else if(b[x]=='/')
		{
		    fu[n++]=4;
		}
		if(flag==0)
		{
			flag=1;
			m++;
		}
	}
	
	end[1]=num[1];
	for(i=1,k=1,m=1;;)
	{
		
		if(fu[i]==0)
		{
		
			break;
		}
		
		
		while(fu[i]==3||fu[i]==4)
		{
			m++;
			if(fu[i]==3)
			{
				end[k]*=num[m];
				i++;
			}
			else
			{
				end[k]/=num[m];
				i++;
			}
		}
		
		m++;
		k++;
		if(fu[i]==1||fu[i]==2)
		{
			end[k]=num[m];
			i++;
			
			continue;
		}
	}
	
	e=end[1];
	for(i=1,k=1;;i++)
	{
		if(fu[i]==0)
		{
			break;
		}
		if(fu[i]==1)
		{
			k++;
			e+=end[k];
		}
		else if(fu[i]==2)
		{
			k++;
			e-=end[k];
		}
	}
	
	printf("%d",e);
	return 0;


	

}

